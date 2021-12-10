# 0 "counter.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "counter.c"
int initData = 0xFF;
int initData2 = 0xABCDEF11;
int aproxsecond = 1000000;

void wait1sec(){
 for(int i=0; i<aproxsecond; i++){
  asm("nop");
 }
}
int main(void) {
    for(;;){
        int val;
        char *a = (char*) 0x00002001;
        *a = 0;
        *a = 1;
        wait1sec();
        *a = 2;
        wait1sec();
        *a = 4;
        wait1sec();
        *a = 8;
        wait1sec();
        *a = 16;
        wait1sec();
        *a = 32;
        wait1sec();
        *a = 64;
        wait1sec();
        *a = 128;
        wait1sec();
        *a = 0xC0;
        wait1sec();
        *a = 0xE0;
        wait1sec();
        *a = 0xF0;
        wait1sec();
        *a = 0xF8;
        wait1sec();
        *a = 0xFC;
        wait1sec();
        *a = 0xFE;
        wait1sec();
        *a = 0xFF;
        wait1sec();
    }
    return 0;
}
