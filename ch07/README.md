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

Static Linking
static linking is process where all the object files of main program and libraries get combined and linked and become a self-contained executable file that can load and run without needing anything.

Linkers have minimal understanding of target machine(ARM, x86-64 etc). that part already has been taken care of by compiler and assembler by generating the object files.

Object files:
- Relocatable object file: contains binary code and data in a form that can be combined with other relocatable object files at compile time to create an executable object file.
- Executable object file: contains binary code and data in a form that can be copied directly into memory a d executed.
- shared object file: a special type of relocatable object file that can be loaded into memory and linked dynamically at either load time or run time
compilers and assemblers generate relocatable object files including shared object files, linkers generate executable object files and an object module is a sequence of bytes and an object file is an object module stored on disk in a file.

Unix systems use `a.out` format for executable object file format modern linux and Unix-based systems use **Executable and Linkable Format**(`ELF`).  
**PE** file format for windows OS (executable is `.exe` and dynamic link library is `.dll`).  
Mac OS-X (also iOS maybe?) use Mach-O object file format (`.o`, `.dylib`, `.bundle`).  

a relocatable object file can contain many sections, like in `ELF`  .text is for machine code of compiled program, .rodata is for Read-only data such as the format strings in `printf` statements, .data is for initialized global and static C variables and so on...

Symbols
in object files, symbol refers to a named entity that represents a function, variable, or other code or data element within the program. `int add(int a, int b)` defines a function symbol named add, and int x, declares a variable symbol named x.
when source code is compiled into object files, the compiler generates symbol information for each function variable and other entities. this information includes the name of the symbol, its type, other metadata.
- defined symbols: these are symbols that have their definitions(code or data) present in the object file, a function that is implemented in the source file will have its corresponding symbol defined in object file
- undefined symbols: these are symbols that are referenced  or used in the object file but not defined within it, they represent external dependencies, such as functions from libraries or other object files that need to be resolved during the linking process
- local symbols: that are defined and referenced exclusively by module, these correspond to static function and global variables

`static` keyword in C make functions and variables private and only accessible in a file, and cannot be accessed from other file.

Symbol resolution is the process that the linker associates or resolves the undefined symbols in object files with their corresponding definitions from other object files or libraries during the linking phase.



