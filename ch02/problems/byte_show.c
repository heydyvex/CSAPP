#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for(i = 0; i < len; i++)
        printf("%.2x", start[i]);

    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val){
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main(){
    // test_show_bytes(12345);
    int val = 0x898;
    byte_pointer valp = (byte_pointer) &val;
    // show_bytes(valp, 1); /* A. */
    // show_bytes(valp, 2); /* B. */
    // show_bytes(valp, 3); /* C. */
    show_bytes(valp, sizeof(val));
    // const char *s = "int sum(int x, int y) { return x + y; }";
    // show_bytes((byte_pointer) s, strlen(s));
    return 0;
}