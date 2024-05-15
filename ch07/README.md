# Chapter 7: Linking

Linking is an essential step that combines multiple object files and resolves external references between them. the Linker is the program or utility that is responsible for this step. it allows modular programming, code reuse and efficient memory usage.

you have this two C files:
`main.c`:
```C
int sum(int *a, int n);

int array[2] = {1, 2};

int main()
{
	int val = sum(array, 2);
	return val;
}
```

`sum.c`:
```C
int sum(int *a, int n)
{
	int i, s = 0;
	for (i = 0; i < n; i++)
		s += a[i];

	return s;
}
```

for compiling and linking these files together:
`clang -Og -o prog main.c sum.c`

this command simply run `clang` complier(LLVM) you can use `gcc` too  
first run **preprocessor** that translate ASCII `main.c` into an intermediate file `main.i` 
then C compiler translates `main.i` into an ASCII assembly language file `main.s`  
then assembler translates `main.s` to binary object file `main.o`  
compiler will do the same for `sum.c` and do all steps to `sum.o`
now it is time to linker to link this two files together using `ld` (linker), they will become an executable file named `prog`

