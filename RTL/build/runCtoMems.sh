#!/bin/bash
#Get path
SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"

display_help() {
    echo
    echo "Compile C source and generate in ./output/ the source files for PipelinedCoreSoC."
    echo "FIXED Depth (2048) as it modify I/O addr also."
    echo
    echo "Usage: $0 -c <source.c>" >&2
    echo
    echo "   -h		Show help."
    echo "   -c <source.c>	Specify source."
    echo
    # echo some stuff here for the -a or --add-options 
    exit 1
}

depth=2048 #Default FIXED depth
new_depth() {
    depth=$1
    echo "The choosen depth is: $depth"
}
    


while getopts 'h,d:,c:' args; do
    case "${args}" in
    	c)source=${OPTARG}
    	name="$(basename -- $source)"
    	echo 'Source name: '"$name"
    	;;
        d)new_depth "${OPTARG}";;
        h)display_help  # Call your function
          exit 0
          ;;
    esac
done

# Check if source is provided
if [ $# -eq 0 ]; then
    echo "No arguments provided"
    exit 1
fi

# Obtain source name to generate files
#lenght=${#source}
#let lenght=lenght-2
#name=${source:0:lenght}
#echo 'Source name: '$name

# Create folder for compilation files
if [ ! -d $SCRIPTPATH/tmp ]; then
  mkdir -p $SCRIPTPATH/tmp;
else
  rm -rf $SCRIPTPATH/tmp/*
fi
if [ ! -d $SCRIPTPATH/output ]; then
  mkdir -p $SCRIPTPATH/output;
else
  rm -rf $SCRIPTPATH/output/*
fi

#FIXED Depth (2048) as it modify I/O addr also.
#Copy the linker script with the modified depth
#sed "4s/.*/. = $depth; /" baselinker.ld > ./tmp/linker.ld

# Compilation
riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -Wl,-mstrict-align -nostartfiles -nostdlib -nodefaultlibs -save-temps=obj -static -c $source -o $SCRIPTPATH/tmp/$name.o
#echo "Compilation done"
# Link
riscv64-unknown-elf-ld -m elf32lriscv -L $SCRIPTPATH -T $SCRIPTPATH/baselinker.ld $SCRIPTPATH/tmp/$name.o -o $SCRIPTPATH/tmp/$name.elf
#echo "Linking done"

# Linked ELF to bin
riscv64-unknown-elf-objcopy -O binary $SCRIPTPATH/tmp/$name.elf $SCRIPTPATH/tmp/$name.bin

#All-in-1 with custom crt
#riscv64-unknown-elf-gcc -g -ffreestanding -O0 -Wl,--gc-sections -nostartfiles -nostdlib -nodefaultlibs -Wl,-T,baselinker.ld crt0.s $name.c -o ./tmp/$name.o
#riscv64-unknown-elf-ld -m elf32lriscv -T baselinker.ld ./tmp/$name.o -o ./tmp/$name.elf
#riscv64-unknown-elf-objcopy -O binary ./tmp/$name.elf ./tmp/$name.bin

# Text and Data memory
hexdump -ve '1/4 "%08x\n"' -s $depth $SCRIPTPATH/tmp/$name.bin  > $SCRIPTPATH/output/text.txt
hexdump -ve '1/1 "%02x\n"' -n $depth $SCRIPTPATH/tmp/$name.bin | grep -v 00000000 > $SCRIPTPATH/tmp/$name.ram # 1 Byte

# Generate 4 files for the 4*8 x depth
input="$SCRIPTPATH/tmp/$name.ram"
counter=0
while IFS= read -r line
do
    if [ $counter -eq 4 ];then 
        let counter=0 
    fi
    echo $line >> $SCRIPTPATH/output/data$counter.txt
    let counter=counter+1
done < "$input"

#Show the linked memory
echo 
echo The memory is:
hexdump $SCRIPTPATH/tmp/$name.bin
readelf -a $SCRIPTPATH/tmp/$name.elf 
hexdump /$SCRIPTPATHtmp/$name.bin 


#EXTRA
#Dissasembly
#NOT LINKED
#riscv64-unknown-elf-objdump -d -M no-aliases ./tmp/$name.o > ./tmp/NoAliases$name.txt
#LINKWS
riscv64-unknown-elf-objdump -D -b binary -m riscv:rv32 -M no-aliases $SCRIPTPATH/tmp/$name.bin > $SCRIPTPATH/tmp/NoAliases$name.txt

cat $SCRIPTPATH/tmp/NoAliases$name.txt










# SOME OPTIONS
#Al formato de verilog readmemh
# riscv64-unknown-elf-objcopy -O verilog counter.elf counter.vh
# https://stackoverflow.com/questions/36648190/how-can-i-generate-a-hexfile-from-c-code-for-testing-a-32-bit-risc-v-hardware-de

# COMPILA LINKA .TEXT Y .DATAS
# riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -mstrict-align -save-temps=obj -static -c $name.c -o $name.o
# echo 'Ended: '$name.o

# riscv64-unknown-elf-ld -m elf32lriscv -T linker.ld $name.o -o $name.elf
# echo 'Ended: '$name.elf

# riscv64-unknown-elf-objcopy --dump-section .text=text.txt $name.elf
# echo 'Ended: text.txt'

# riscv64-unknown-elf-objcopy --dump-section .rodata=rodata.txt --dump-section .data=data.txt --dump-section .bss=bss.data $name.elf
# echo 'Ended: rodata.txt, data.txt, rodata.txt'

# DATA MEMORY 32-bits
# hexdump -ve '1/4 "%08x\n"' -n 4096 ./tmp/$name.bin | grep -v 00000000 > ./output/text.txt
# hexdump -ve '1/4 "%08x\n"' -s 4096 $name.bin > $name.ram # 4 Bytes
# https://reposhub.com/cpp/miscellaneous/darklife-darkriscv.html


# VERBOSE ASM
#riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -mstrict-align -save-temps=obj -static -fverbose-asm -S -c ledstest.c
