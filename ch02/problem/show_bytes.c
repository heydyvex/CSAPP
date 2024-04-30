#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len, char *type) {
  int i;
  for (i = 0; i < len; i++)
    printf("%.2x", start[i]);

  printf(" ---> %s\n", type);
}

void show_int(int x) { show_bytes((byte_pointer)&x, sizeof(int), "int"); }

void show_short(short x) {
  show_bytes((byte_pointer)&x, sizeof(short), "short");
}

void show_long(long x) { show_bytes((byte_pointer)&x, sizeof(long), "long"); }

void show_float(float x) {
  show_bytes((byte_pointer)&x, sizeof(float), "float");
}

void show_double(double x) {
  show_bytes((byte_pointer)&x, sizeof(double), "double");
}

void show_pointer(void *x) {
  show_bytes((byte_pointer)&x, sizeof(void *), "pointer");
}

void test_show_bytes(int val) {
  int ival = val;
  float fval = (float)ival;
  double dval = (double)ival;
  long lval = (long)ival;
  short sval = (short)ival;
  int *pval = &ival;

  show_int(ival);
  show_short(sval);
  show_long(lval);
  show_float(fval);
  show_double(dval);
  show_pointer(pval);
}

int main() {

  test_show_bytes(12345);
  return 0;
}