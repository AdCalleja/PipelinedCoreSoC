DIR = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
PROJECTNAME=PipelinedCoreSoC
YOSYS_OPT = -p "read_verilog -I$(DIR)RTL/src/ -D$(MACRO)=1 $(DIR)RTL/src/PPCSoC.v; synth_ice40 -json $(DIR)RTL/build/hardware.json" -q
NEXTPNR_OPT = --hx4k --package tq144 --opt-timing --json $(DIR)RTL/build/hardware.json --asc $(DIR)RTL/build/hardware.asc --pcf  $(DIR)RTL/constrains/alhambra-ii_icestudio.pcf
#Firmware param. 
#Memory depth (Fixed. This alone don't modify memory depth)
DEPTH = 2048
SRC := $(wildcard $(DIR)firmware/*.c)
OBJ := $(SRC:$(DIR)firmware/%.c=$(DIR)firmware/build/tmp/%.o)
ELF := $(SRC:$(DIR)firmware/%.c=$(DIR)firmware/build/tmp/%.elf)
BIN := $(SRC:$(DIR)firmware/%.c=$(DIR)firmware/build/tmp/%.bin)
RAM := $(SRC:$(DIR)firmware/%.c=$(DIR)firmware/build/tmp/%.ram)
TEXT := $(SRC:$(DIR)firmware/%.c=$(DIR)firmware/build/output/text.txt)
DATA  := $(SRC:$(DIR)firmware/%.c=$(DIR)firmware/build/output/data)
#VERILOG MACRO
MACRO?=

#Basic Rules
.PHONY: all
all:
	@echo "make one of /firmware c source files"
	@echo "Verilog MACRO can be passed as: make MACRO=<BUTTON,SLOWCLOCK,DEBUGINSTRUCTION>"
	@echo "	make counter.c"

.PHONY: help
help: all

.PHONY: clean
clean:
	rm -f RTL/build/*.asc RTL/build/*.bin RTL/build/*.json	#RTL Synth
	rm -f RTL/sim/*.vvp RTL/sim/*.vcd 			#RTL Sim
	rm -f firmware/build/output/* firmware/build/tmp/*	#C Compilation
	
#Firmware Rules
$(OBJ): $(SRC)
	riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -Wl,-mstrict-align -nostartfiles -nostdlib -nodefaultlibs -save-temps=obj -static -c $(SRC) -o $@
$(ELF): $(OBJ)
	riscv64-unknown-elf-ld -m elf32lriscv -L $(DIR)firmware/build/ -T $(DIR)firmware/build/baselinker.ld $< -o $@
$(BIN): $(ELF)
	riscv64-unknown-elf-objcopy -O binary $< $@
$(TEXT): $(BIN)
	hexdump -ve '1/4 "%08x\n"' -s $(DEPTH) $<  > $@
$(RAM): $(BIN)
	hexdump -ve '1/1 "%02x\n"' -n $(DEPTH) $< | grep -v 00000000 > $@ # 1 Byte
$(DATA): $(RAM)
	@counter=0; \
	while IFS= read -r line; \
	do \
    	if [ $$counter -eq 4 ];then \
       		counter=0; \
    	fi; \
    	echo $$line >> $(DATA)$$counter.txt; \
    	counter=$$((counter+1)); \
	done < "$<"

firmware: $(TEXT) $(DATA)
	
test:
	@echo $(SRC)
	@echo $(OBJ)
	@echo $(ELF)
	@echo $(BIN)
	@echo $(TEXT)
	@echo $(DATA)
	
#Verilog Rules      
Alhambra:  Alhambra.synth

Alhambra.synth: firmware
	yosys $(YOSYS_OPT)
	nextpnr-ice40 $(NEXTPNR_OPT)
	icepack $(DIR)RTL/build/hardware.asc $(DIR)RTL/build/hardware.bin
	iceprog $(DIR)RTL/build/hardware.bin
	
Alhambra.show: firmware
	yosys $(YOSYS_OPT)
	nextpnr-ice40 $(NEXTPNR_OPT) --gui


