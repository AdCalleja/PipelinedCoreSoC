# PipelinedCoreRISCV

 ## Logisim

Given the complexity of the control units implementation based on logic gates Logisim is used as a schematic enviroment with error notification.

Data memory (RAM) is implemented as 4 byte-width blocks of depth 2<sup>addr_width-1</sup>.

### Diagram

![Top Level Diagram](images/topleveldiagram.png?raw=true "Top Level Diagram")

## How to use
***Warning:*** As the project is being currently modified may be some absolute paths.

### RTL synth and load of the bitstream to Alhambra-II.

A simple bash script has been created to execute the generation of the RTL model with Yosys and NextPNR and load it to the Alhambra-II board, but it can be replicated to do it with other boards.
[*Script*](/RTL/build/runAlhambra-ii.sh)

Standard:
~~~bash
./RTL/build/runAlhambra-ii.sh
~~~

Button:
Button 1 (SW1) is used as clock.

*Warning: to reset, Button 2 (SW2) must be pressed before Button 1 (SW1) as reset is designed to be synchronous*

~~~bash
./RTL/build/runAlhambra-ii.sh -D BUTTON
~~~

SlowClock:
1 Clock Cycle per second

~~~bash
./RTL/build/runAlhambra-ii.sh -D SLOWCLOCK
~~~

### Compilation and memory generation.

To compile and generate the memory files  [*runCtoMems.sh*](/RTL/build/runCtoMem.sh). It generates temporary files in */RTL/build/tmp/* and the memory files in  */RTL/build/output/*.

~~~bash
./RTL/build/runCtoMems.sh <source.c>
~~~

Both *text* and and *data* memory are defined by default as 4096 x 32 but can be modified by changing the *addr* bus width in [*PipelinedCore.v*](/RTL/src/PipelinedCore.v).

~~~verilog
parameter TEXT_ADDR_WIDTH = 12; 
parameter DATA_ADDR_WIDTH = 14; //Max addr width 14 -> [7:0]4*4096 //[1:0] select Byte from 0 to 3 //[13:2] 2**12 Select 1 of 4096 dirs
~~~

and using the -d flag of runCtoMems.sh

~~~bash
./RTL/build/runCtoMems.sh -d 4096 -c <source.c>
~~~

### Simulating.

To simulate with icarus and GTKWave using  [*PipelinedCore_bench.v*](/RTL/src/PipelinedCore_bench.v) the following script can be used:

~~~bash
./RTL/sim/runIcarusSim.sh [-D <BUTTON,SLOWCLOCK,DEBUGINSTRUCTION>]
~~~

(*DEBUGINSTRUCTION* propagate along all pipeline regs the instruction. It was used clarify while debugging what was the instruction in every step of the Pipeline)


## RTL

Working RV32I except Fence, Ecall and Ebreak.

## Testing
To test the basic instructions implemented and debug the design the following assembly code has been written in [Ripes](https://github.com/mortbopet/Ripes), getting also the disassembly version of the code:

~~~assembly
#Logisim Tests
#[addr]
#(value inside)
.data
    a: .word 1
    b: .word 2
    
.text
main:
    lw a0, 0 (a0)     # Load from Data[0+0](1) to x10(0)
    lw a1, 4 (a1)     # Load from Data[0+4](2) to x11(0)
    add a2, a0, a1    # Add 1 + 2 = 3 to x12
    sw a2, 8 (t0)     # Save x12(3) to Data[0+8]
    beq a2, a1, EQUAL # Don't brach x12(3) - x11(2) = 1
    sub a3, a2, a1    # Sub x12(3) - x11(2) = x13(1)
    sub a2, a2, a3    # Sub x12(3) - x13(1) = x12(2) a2 == a1
    beq a2, a1, EQUAL # Branch x12(2) - x11(2) = 0
    nop
    nop
    nop
    nop
EQUAL:
    and a3, a3, a2    # x13(1) AND x12(2) = x13(0)
    or a4, a3, a2     # x13(0) OR x12(2) = x14(2)
    lw a3, 4 (a3)     # Load from Data[0+4](2) to x13(0)
    beq a4, a3, LWBRANCH # Branch x14(2) - x13(2) = 0
    nop
    nop
    nop
    nop

LWBRANCH:
    add a5, a4, a3    # Add 2 + 2 = 4 to x15
~~~

![Test Disassembly](images/testdisassembly.png?raw=true "Test Disassembly")

The code in hexadecimal is load to the instruction memory in Logisim. A copy of it is load in the file *textmemory*, same as a copy of the data memory in *datamemory*.

The following Waveform show the result obtained in GTKWave and what caused the output *leds* used as a reference that the system is executing the correct instruction.
![Waveform](images/TestASMLeds.png?raw=true "Waveform")

After it, while adding RV32I instructions there where created more assembler test to ensure all instrucctions worked well.

