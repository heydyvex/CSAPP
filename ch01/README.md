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



