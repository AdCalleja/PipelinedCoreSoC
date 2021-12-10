#!/bin/bash

display_help() {
    echo
    echo "Delete old files, run verilator to check for errors/warnings and run Yosys NextNPR and Icepack-Iceprog"
    echo
    echo "Usage: $0 [-D <BUTTON,SLOWCLOCK,DEBUGINSTRUCTION>]" >&2
    echo
    echo "   -h	Show help"
    echo "   -D,	Yosys verilog Define. <Parameter>=1 in verilog code"
    echo
    # echo some stuff here for the -a or --add-options 
    exit 1
}

while getopts 'h,D:' args; do
    case "${args}" in
        D) defines=${OPTARG};;
        
        h)display_help  # Call your function
          exit 0
          ;;
    esac
done

echo 'DELETING OLD FILES'
rm *.asc *.bin *.json
echo 'Defines  = -D'${defines}'=1'
#Listen to Verilator Warnings #Deactivated
#echo 'RUNNING VERILATOR'
verilator -Wall -cc ./../src/PPCSoC.v --prefix PPC -I./../src/ -D${defines}=1
#Synthesize
echo 'RUNNING YOSYS'
yosys -p "read_verilog -I ./../src/ -D${defines}=1 ./../src/PPCSoC.v; synth_ice40 -json hardware.json" #-q #./../src/PPCSoC.v
# -defer used to specify readmemh filename as a parameter. Doesn't Work well
#Place and Route
echo 'RUNNING NEXTNPR'
nextpnr-ice40 --hx4k --package tq144 --opt-timing --json hardware.json --asc hardware.asc --pcf ./../constrains/alhambra-ii_icestudio.pcf 
#Program
echo 'PROGRAMMING FPGA'
icepack hardware.asc hardware.bin
iceprog hardware.bin
