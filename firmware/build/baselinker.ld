SECTIONS {
. = 0x00000000;
.data : { * (.data); }
.bss : { * (.bss); }
. = 0x00000800; /*Data Memory 2^12 = 2048*/
.text : { 
	crt0.o (.text)
   	*(.text);
   	_end = .;  	
	}
.rodata : { * (.rodata); }
}
