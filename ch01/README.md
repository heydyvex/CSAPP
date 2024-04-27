# Chapter 1: A Tour of Computer Systems

## Notes

to run a simple program on computer, hardware and a systems software(OS) is needed.
It has been like this for decades and will be so for decades.

```C
#include <stdio.h>

int main()
{

	printf("hello, world\n");

	return 0;
}
```
a simple *hello world* program in C programming language, file name *hello.c*

```
#     i     n     c     l     u     d     e     SP     <
s     t     d     i     o     .     35     105     110
99     108     117     100     101     32     60     115
116     100     105     111     46

h     >     \n     \n     i     n     t     SP     m     a
i     n     (     )     \n     {     104     62     10
10     105     110     116     32     109     97     105
110     40     41     10     123
```
ASCII text representation of

This program is a sequence of bits(0 and 1s), 8 bits is 1 byte, each byte corresponds to a character - aka ASCII - a ASCII representation is like A = 65, and that number is one byte - 4 bits represent one real number like 1, two real number are 8 bits so it is  1 byte - other non-English languages use Unicode to represent characters.

A file consist exclusively of ASCII characters are known as text files, all other files are known as binary files.

It is insane to think that all information in system are bunch of bits, just think about it.

Computer cannot understand our C program, in order to run it, we have to translate it to machine code, we use a software called *Compiler*, it compile or translate our source file to object file - aka binary file - that is executable and can be understood by computer.

Clang and GCC are C and C++ Compiler, for make *hello.c* executable, first make sure Compiler is installed then use this command:
```sh
gcc hello.c -o hello
```
this will make a binary file *hello* that is executable and it can print hello world.

Compilation system consist of four phases(according to book):
Preprocessing, Compilation, Assembly, Linking phase.

- Preprocessing phase: Add header files - e.g. <stdio.h> - to original program, if compiler read `#include <some header file>` it will add that file on top of the C program. result is another C program with `.i` extension.

- Compilation phase: the compiler translates `hello.i` text file into `hello.s` text file that contains assembly language program.

- Assembly phase: Assembler translates `hello.s` into machine language instructions, known as a *relocatable object program*, and store result in `hello.o` file.

- Linking phase, `hello` program calls `printf` function, the `printf` function located in separate precompiled object file `printf.o`, need to be merged with our `hello.o` program, Linker(`ld`) handles this job, then result is `hello` file

Compilers, usually produce good code by Optimizing program performance. no need to understand how Compilers optimize code, but you need to know basics in language you program with, just to help your compiler to do better job (chapter 3, 5, 6).

Also you need to know about Linking errors in order to address it, and some linking error can happen at run time, so go read about this and don’t be a noob (chapter 7).

You must avoid security holes, like buffer overflow, to learn secure programming you need understand the consequences of the way data and control information are stored on the program stack (chapter 3), how is array stored in memory and how does compiler do it?

so now  `hello.c` program complied into executable `hello` object file now can be run via another program known as `shell` (in your terminal).

so what happens in hardware level?

Buses, data and information transfer by wires called buses, that carry bytes of information around, from disk to memory, from there to CPU, from there to display and so on...

I/O devices, are system's connection to the external world, like internet, keyboard, mouse, display, disk....
each I/O device is connected to the I/O bus by a controller or adapter to transfer data back and forth

Main memory, is a temporary storage that is close(different than register and cache) to processor(CPU) and can send and receive data to processor to process, it is consist of *dynamic random access memory* aka DRAM chips, and it is organized as a linear array of bytes, each with its own unique address (Chapter 6).

Processor, central processing unit (CPU), is like an engine that execute the program(instructions ) stored in main memory, processor defined by its `instruction set architecture` x86-64 is a architecture that has a very complex structure called CISC and there is ARM architecture is simple called RISC.

when you type `./hello` to program in shell, shell read each into register(cpu) then stores it in memory, (remember data from you keyboard goes to cpu registers then it send them to main memory, but this is different for disk and main memory, it directly goes from disk to memory(DMA)). 
once you hit enter on keyboard, shell start to run some instruction, copy and load from disk to memory(directly) then send from main memory to CPU then CPU send it to display to show you `hello world`, pretty cool right?

so there are many steps and works to move data around and we need to be as fast as possible (laws of physics are the limitations), from disk to memory from memory to cpu register. the more small and close to cpu means faster and faster. Aside from main memory, chip designers come up with another idea: *cache memory*, very close to cpu, faster that main memory but still a little slower than registers. e.g. L1 cache, L2 cache, L3 cache memories use SRAM.(chapter 6)

**Memory hierarchy**: CPU Register > L1 SRAM > L2 SRAM > L3 SRAM > Main memory > local storage(disk) > Remote storage(disk)

the smaller faster and costlier. the larger, slower and cheaper

well well well, software that most take it for granted (OS), in short operating system lies between application program e.g. `hello` program, and hardware(cpu, main memory, I/O devices, etc...)

every request by app program to hardware must to through the OS, to protect hardware from misuse by malicious software, provide simple way for software to work with hardware

OS provide abstractions(that doesn’t exist in real world), ***Files*** and I/O device, ***virtual memory*** as main memory and I/O devices, ***Processes*** and Processor, Main memory and I/O devices.

A process is the operating system's abstraction for a running program and many program can run concurrently(each process have exclusive use of hardware and CPU switch rapidly to execute few instruction from one process and few from another process, aka **context switching**)

in a process consist of multiply execution unit called Threads, it is easier to share data between multiple threads that multiple process, with threads you can build faster software.

Virtual memory is an abstraction that provides each process with the illusion that it has exclusive use of main memory. heap, stack. (chapter 9)

File is a sequence of bytes, that's it. every I/O device like disks, keyboards, displays, network is modeled as a file. and all input and output in the system is performed by reading and writing files. (chapter 10)

Internet, enables communication between two computer. network adapter is just another I/O device in computer that sends data to another computer instead of local disk using internet.