# PipelinedCoreSoC

![Pipelined Core SoC ](images/PPCSoCDiagram.png?raw=true "Bus Distribution and Example")



![Bus Distribution](images/PPCSoCBus.png?raw=true "Bus Distribution and Example")

Bus idea from [BrunoLevys'](https://github.com/BrunoLevy)  [FEMTOSOC](https://github.com/BrunoLevy/learn-fpga/blob/master/FemtoRV/RTL/femtosoc.v)  adapted to my core model and requierements.

 ## How to use

*Usage ported to **make**. Refer to [https://github.com/AdCalleja/PipelinedCoreSoC/tree/902a0603dfce1fe3c4218d3ee2e5142c4034b788](older commits) to see the bash script implementation.*

#### Prerequisites

Having installed [OSS CAD SUITE](https://github.com/YosysHQ/oss-cad-suite-build).

Having installed RISC-V toolchain.

Rules for Alhambra-II (If this is your board)

~~~bash
sudo sh -c "echo 'ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6010", MODE="0660", GROUP="plugdev", TAG+="uaccess"' > /etc/udev/rules.d/53-lattice-ftdi.rules"
~~~

#### Usage:

Source file placed in ./firmware is the one to be compiled.

Compile source file, synthesize hardware/memories, and load it to Alhambra board.

~~~bash
make alhambra
~~~

#### Compilation and memory generation.

Source file placed in ./firmware is the one to be compiled.

Temporary files are placed in *./firmware/build/tmp/* and the memory files in  *./firmware/build/output/*.

~~~bash
make firmware
~~~

The default memory sizes is set to (to fill Alhambra-II FPGA):

- Text Memory: 4096 words
- Data Memory: 2048 words

### Simulating.

To simulate with icarus and GTKWave using  [*PPCSoC_tb.v*](/RTL/src/PPCSoC_tb.v) the following script can be used:

~~~bash
./<download location>/PipelinedCoreSoC/RTL/sim/runIcarusSim.sh [-D <BUTTON,SLOWCLOCK,DEBUGINSTRUCTION>]
~~~

(*DEBUGINSTRUCTION* propagate along all pipeline regs the instruction. It was used clarify while debugging what was the instruction in every step of the Pipeline)


## Notes

Working RV32I except Fence, Ecall and Ebreak.
