# Chapter 3: Machine-Level Representation of Programs


## Notes

Okay, this chapter going to be about machine-level representation on program, assembly and compilers, It's going to be fun I guess, different level of abstraction, from C to assembly to machine code, how arrays and structures like this data types are implemented in machine level ... seems fun.

In late 1978 Intel designed 8086 microprocessor (29,000 transistors), one of the early integrated circuit chips, Intel was one of the greatest companies that pushed chip innovation further (but now in 2024 in dying), also in 1980 introduced 8087 floating-point processor(45,000 transistors) to operate alongside 8086 to execute floating-point instructions.

x86 architecture was used for these microprocessors and is one of the most popular chip architecture alongside ARM(I like this more).

1,000 = K
1,000,000 = M
1,000,000,000 = G

intel chips: 
, ,  T, 32-bit
, 1995, 5.5M T, 32-bit
Pentium/MMX, 1997, 4.5 T, 32-bit
Pentium II, 1997, 7M 

| Chip              | Year | Transistor                    | word size (bit) |
| ----------------- | ---- | ----------------------------- | --------------- |
| 8086              | 1978 | 29 K                          | 16-bit          |
| 80286             | 1982 | 134 K                         | 16-bit          |
| i386              | 1985 | 275 K                         | 32-bit          |
| i486              | 1989 | 1.2 M                         | 32-bit          |
| Pentium           | 1993 | 3.1 M                         | 32-bit          |
| PentiumPro        | 1995 | 5.5 M                         | 32-bit          |
| Pentium/MMX       | 1997 | 4.5 M                         | 32-bit          |
| Pentium II        | 1997 | 7 M                           | 32-bit          |
| Pentium III       | 1999 | 8.2 M                         | 32-bit          |
| Pentium 4         | 2000 | 42 M                          | 32-bit          |
| Pentium 4E        | 2004 | 125 M                         | 32-bit also 64  |
| Core 2            | 2006 | 291 M                         | 64-bit          |
| Core i7           | 2008 | 781 M                         | 64-bit          |
| Core i7 Sandy ... | 2011 | 1.17 G                        | 64-bit          |
| Core i7 Haswell   | 2013 | 1.4 G                         | 64-bit          |
| i9 13900K         | 2022 | 26 G                          | 64-bit          |
| i9 14900k         | 2023 | Unknown but guess around 26 G | 64-bit          |
Personal comment (may 2024):
"this is wild 😂, but we are limited by laws of Physics and cannot put more transistor in a small area as before, I think we need a new paradigm and principle for computing a new whole architecture from scratch that is "scalable", current chips are not scalable anymore.  
also we need skilled software engineers to make the most of chips, right now software engineers have skill issues and take everything for granted, use so much hardware recourse and software is complete BS.  
I must be a good software engineer period."

this command `gcc -Og` make your machine code less optimized and more readable for debugging or something like that `-O(blah)` will do this in few level, check your compiler doc, it is also available for Clang (I checked it out).

as I took some note of compiler process in chapter 1, it is amazing process to make easier coding for us, otherwise we had to code in assembly(aliens language). first C preprocessor happens(#include files blah blah) then generate assembly version of the program, then converts the assembly code to object code(a kind of machine code) by assembler, then it is time to merge and link files together by linker and after that you have a executable code(another kind of machine code).



