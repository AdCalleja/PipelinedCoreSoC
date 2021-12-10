#riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -mstrict-align -nostartfiles -nostdlib -nodefaultlibs -save-temps=obj -static -c crt0.s -o crt0.o

.section .text, "ax"
.global _start
_start:
    .cfi_startproc
    .cfi_undefined ra
    .option push
    .option norelax
    	la gp, 0x2000
    .option pop
    	la sp, 0x800
    	add s0, sp, zero
    	jal zero, main
    .cfi_endproc
    .end
