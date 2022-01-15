//https://stackoverflow.com/questions/59302235/stack-memory-operations-at-the-beginning-of-main-function-in-assembly

int initData = 0xABCDEF11;
int main(void) {
    for(;;){
        int val;
        char *a = (char*) 0x00002001;
        *a = 0;
        *a = 1;
        *a = 2;
        *a = 3;
        *a = 4;
        *a = 5;
        *a = 6;
        *a = 7;
        *a = 8;
    }
    return 0;
}


