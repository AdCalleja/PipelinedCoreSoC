#!/bin/bash
#Get path
SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
#Clean
rm $SCRIPTPATH/*.vvp $SCRIPTPATH/*.vcd 

display_help() {
    echo
    echo "Run Icarus Verilog and then open with GTKWave"
    echo
    echo "Usage: $0 [-D <BUTTON,SLOWCLOCK,DEBUGINSTRUCTION>]" >&2
    echo
    echo "   -h	Show help"
    echo "   -D,	Macro. <Parameter>=1 in verilog code"
    echo
    # echo some stuff here for the -a or --add-options 
    exit 1
}
while getopts 'h,D:' args; do
    case "${args}" in
        D) defines=${OPTARG};;
        h) display_help  # Call your function
           exit 0
           ;;
    esac
done


iverilog -o PPCSoC.vvp -I $SCRIPTPATH/../src -D${defines}=1 $SCRIPTPATH/../src/PPCSoC_tb.v
vvp $SCRIPTPATH/PPCSoC.vvp
gtkwave -a $SCRIPTPATH/signals.gtkw $SCRIPTPATH/PPCSoC_tb.vcd
