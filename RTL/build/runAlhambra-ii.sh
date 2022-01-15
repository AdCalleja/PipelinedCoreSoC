#!/bin/bash
#Get path
SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
#Clean
echo 'DELETING OLD FILES'
rm $SCRIPTPATH/*.asc $SCRIPTPATH/*.bin $SCRIPTPATH/*.json

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

while getopts 'h,I:D:' args; do
    case "${args}" in
        D) defines=${OPTARG}
        echo "Defines  = -D${defines}=1"
        ;;
        h)display_help  # Call your function
          exit 0
          ;;
    esac
done

#Listen to Verilator Warnings #Deactivated
#echo 'RUNNING VERILATOR'
#verilator -Wall -cc ./../src/PPCSoC.v --prefix PPC -I./../src/ -D${defines}=1
#Synthesize
echo 'RUNNING YOSYS'
yosys -p "read_verilog -I$SCRIPTPATH/../src/ -D${defines}=1 $SCRIPTPATH/../src/PPCSoC.v; synth_ice40 -json $SCRIPTPATH/hardware.json" #-q #./../src/PPCSoC.v
# -defer used to specify readmemh filename as a parameter. Doesn't Work well
#Place and Route
echo 'RUNNING NEXTNPR'
nextpnr-ice40 --hx4k --package tq144 --opt-timing --json $SCRIPTPATH/hardware.json --asc $SCRIPTPATH/hardware.asc --pcf  $SCRIPTPATH/../constrains/alhambra-ii_icestudio.pcf
#Program
echo 'PROGRAMMING FPGA'
icepack $SCRIPTPATH/hardware.asc $SCRIPTPATH/hardware.bin
iceprog $SCRIPTPATH/hardware.bin
