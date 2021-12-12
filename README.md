# PipelinedCoreSoC

![Pipelined Core SoC ](images/PPCSoCDiagram.png?raw=true "Bus Distribution and Example")



![Bus Distribution](images/PPCSoCBus.png?raw=true "Bus Distribution and Example")

Bus idea from [BrunoLevys'](https://github.com/BrunoLevy)  [FEMTOSOC](https://github.com/BrunoLevy/learn-fpga/blob/master/FemtoRV/RTL/femtosoc.v)  adapted to my core model and requierements.

 ## How to use

### RTL synth and load of the bitstream to Alhambra-II.

A simple bash script has been created to execute the generation of the RTL model with Yosys and NextPNR and load it to the Alhambra-II board, but it can be replicated to do it with other boards.
[*Script*](/RTL/build/runAlhambra-ii.sh)

#### Prerequisites

Having installed ([OSS CAD SUITE](https://github.com/YosysHQ/oss-cad-suite-build)
Rules for Alhambra-II (If this is your board)

~~~bash
sudo sh -c "echo 'ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6010", MODE="0660", GROUP="plugdev", TAG+="uaccess"' > /etc/udev/rules.d/53-lattice-ftdi.rules"
~~~



#### Standard Use:

~~~bash
./<downloaded location>/PipelinedCoreRICV/RTL/build/runAlhambra-ii.sh
~~~

#### Button:

Button 1 (SW1) is used as clock.

*Warning: to reset, Button 2 (SW2) must be pressed before Button 1 (SW1) as reset is designed to be synchronous*

~~~bash
./<downloaded location>/PipelinedCoreRICV/RTL/build/runAlhambra-ii.sh -D BUTTON
~~~

#### SlowClock:

1 Clock Cycle per second

~~~bash
./<downloaded location>/PipelinedCoreRICV/RTL/build/runAlhambra-ii.sh -D SLOWCLOCK
~~~

### Compilation and memory generation.

To compile and generate the memory files  [*runCtoMems.sh*](/RTL/build/runCtoMem.sh). It generates temporary files in */RTL/build/tmp/* and the memory files in  */RTL/build/output/*.

~~~bash
./<downloaded location>/RTL/build/runCtoMems.sh -c <source.c>
~~~

The default memory sizes is set to (to fill Alhambra-II FPGA):

- Text Memory: 4096 words
- Data Memory: 2048 words

### Simulating.

To simulate with icarus and GTKWave using  [*PipelinedCore_bench.v*](/RTL/src/PipelinedCore_bench.v) the following script can be used:

~~~bash
./RTL/sim/runIcarusSim.sh [-D <BUTTON,SLOWCLOCK,DEBUGINSTRUCTION>]
~~~

(*DEBUGINSTRUCTION* propagate along all pipeline regs the instruction. It was used clarify while debugging what was the instruction in every step of the Pipeline)


## RTL

Working RV32I except Fence, Ecall and Ebreak.
