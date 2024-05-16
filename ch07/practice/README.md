practice:

1 - Static Linking:
- write a simple C program that consists of multiple source files (main.c, utils.c, math.c)
- compile each source file separately using the compiler's option to generate object files(`clang -c file.c`)
- now manually link the object files together using the linker (`clang -o program main.o utils.o math.o`)

2 - Dynamic Linking:
- write a simple C program that uses an external library (e.g math library)
- compile the program with the option to generate position-independent code (`-fPIC`) and generate object file
- linking the program dynamically with the required library (`clang -o program main.o -lm`)

3 - Symbol Resolution:
- write a C program that consists of multiple source files, with some functions or variables defined in one file and used in another 
- compile the source files separately into object files
- intentionally omit one of the files during the linking process
- see the linker error message related to unresolved symbols and identify the missing object file
- link the program correctly and verify that it runs as expected

4 - Relocation:
- create a cf program that defines and uses global variables or func with known addresses or offsets
- compile the program into an object file
- use a tool like `objdump` or `nm` to inspect the object file and see the relative or symbolic addresses used for the code and data sections
- link the program, use the same tools to inspect the final executable, observing how the addresses have been relocated to absolute memory addresses

