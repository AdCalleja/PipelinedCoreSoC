#include "ledstest.c"

.text
.global _start
.type _start, @function


.text
.option push
.option norelax
     li gp,0x00004000       #   Base address of memory-mapped IO
.option pop

     li sp,0x00001000      # Read RAM size in hw config register and
        #   initialize SP one position past end of RAM

call main
tail exit
