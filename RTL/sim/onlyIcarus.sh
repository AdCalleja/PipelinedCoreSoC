#!/bin/bash

display_help() {
    echo
    echo "Run only Icarus Verilog. Update file for GTKWave"
    echo
    echo "Usage: $0 [-D <BUTTON,SLOWCLK,DEBUGINSTRUCTION>]" >&2
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

rm *.vvp *.vcd 
iverilog -o PPCSoC.vvp -I ./../src -D${defines}=1 ./../src/PPCSoC_tb.v
vvp PPCSoC.vvp
