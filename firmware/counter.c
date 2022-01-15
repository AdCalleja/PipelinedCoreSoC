int initData = 0xFF;
int initData2 = 0xABCDEF11;
int aproxsecond = 1000000;

void wait1sec(){
	for(int i=0; i<1000000; i++){
		asm("nop");
	}
}
int main(void) {
    for(;;){
        int val;
        char *a = (char*) 0x00002001;
        *a = 0;	//0000.0000
        *a = 1;	//0000.0001
        wait1sec();
        *a = 4;	//0000.0100
        wait1sec();
        *a = 16;	//0001.0000
        wait1sec();
        *a = 64;	//0100.0000
        wait1sec();
        *a = 128;	//1000.0000
        wait1sec();
        *a = 0xC0;	//1100.0000
        wait1sec();
        *a = 0xE0;	//1110.0000
        wait1sec();
        *a = 0xF0;	//1111.0000
        wait1sec();
        *a = 0xF8;	//1111.1000
        wait1sec();
        *a = 0xFC;	//1111.1100
        wait1sec();
        *a = 0xFE;	//1111.1110
        wait1sec();
        *a = 0xFF;	//1111.1111
        wait1sec();
    }
    return 0;
}


