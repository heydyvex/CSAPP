# Chapter 3: Machine-Level Representation of Programs


## Notes

Okay, this chapter going to be about machine-level representation on program, assembly and compilers, It's going to be fun I guess, different level of abstraction, from C to assembly to machine code, how arrays and structures like this data types are implemented in machine level ... seems fun.

In late 1978 Intel designed 8086 microprocessor (29,000 transistors), one of the early integrated circuit chips, Intel was one of the greatest companies that pushed chip innovation further (but now in 2024 in dying), also in 1980 introduced 8087 floating-point processor(45,000 transistors) to operate alongside 8086 to execute floating-point instructions.

x86 architecture was used for these microprocessors and is one of the most popular chip architecture alongside ARM(I like this more).

1,000 = K  
1,000,000 = M  
1,000,000,000 = G  

**intel chips**:

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

as I took some note of compiler process in chapter 1, it is amazing process to make coding easier for us, otherwise we had to code in assembly(aliens language). first C preprocessor happens(#include files blah blah) then generate assembly version of the program, then converts the assembly code to object code(a kind of machine code) by assembler, then it is time to merge and link files together by linker and after that you have a executable code(another kind of machine code).

Abstraction is one of the most important concept in computer science and I dare to say in world.  I means, hiding details of an implementation(assembly) through the use of a simple abstract model(C language), in fact abstraction coming from abstract, and it means something that physically doesn’t exist. `0` and `1` does not exist too, it is all high and low voltages down there😅. it is amazing isn’t it?

Instruction set architecture or ISA define behavior and format of machine-level program, defining the processor state, format of instructions and the effect each of these instructions will have on the state

the memory addresses used by a machine-level program are virtual addresses, it provide a memory model that appears to be a very large byte array(chapter 9).

the machine code differs greatly from C code, some parts of the processor states are hidden from C programmer, like:  
the program counter(indicates the address in memory of the next instruction to be executed), the integer register file contains 16 named locations storing 64-bit values, these registers can hold addresses like C pointer or integer data, the condition code registers hold status information about the most recently executed arithmetic or logical instruction, a set of vector registers can each hold one or more integer or floating-point value.

C provides some data types for data that can be declared and allocated in memory, but in machine-code level see memory as a simply a large byte-addressable array and all these C data types contiguous collections of bytes. also in assembly code there is no such distinction between signed or unsigned integers. Between types of pointers or pointers and integers.

Okay, we have this code written in C, `program.c`:  
```C
long mtul2(long, long);

void multstore(long x, long y, long *dest) {
	long t = mtul2(x, y);
	*dest = t;
}
```

we want to assemble it with clang(it generate better assembly than gcc on my machine😂)
the command to assemble (no compiling and linking): `clang -Og -S program.c`
our `program.s` :

```asm
	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0
	.globl	_multstore                      ; -- Begin function multstore
	.p2align	2
_multstore:                             ; @multstore
	.cfi_startproc
; %bb.0:
	stp	x20, x19, [sp, #-32]!           ; 16-byte Folded Spill
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	mov	x19, x2
	bl	_mtul2
	str	x0, [x19]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp], #32             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols

```
  
this is assembly code generated of our C program (btw I'm using mac m1 for this)
so now we want to compile it(no linking): `clang -Og -c program.c`
now our `program.o`, 
```
����������������h��� �������������������������������������H��������������H��������������������__text����������__TEXT������������������$����������������������������������__compact_unwind__LD������������(������� ����������������������������������2�������������������������������� �� ������P�����������������������������������������������������������������������O���{��C��������`���{A��O¨�_�������������$��������������������������-������������������������(�����������������������������������_multstore�_mtul2�ltmp1�ltmp0��
```

what the hell is this? this is sequence of hex bytes, this is a machine-code bro😂
okay to make it readable, we have to **disassemble** it using disassembler 
command: `objdump -d program.o` 
```asm

program.o:	file format mach-o arm64

Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
       0: a9be4ff4     	stp	x20, x19, [sp, #-32]!
       4: a9017bfd     	stp	x29, x30, [sp, #16]
       8: 910043fd     	add	x29, sp, #16
       c: aa0203f3     	mov	x19, x2
      10: 94000000     	bl	0x10 <ltmp0+0x10>
      14: f9000260     	str	x0, [x19]
      18: a9417bfd     	ldp	x29, x30, [sp, #16]
      1c: a8c24ff4     	ldp	x20, x19, [sp], #32
      20: d65f03c0     	ret

```

this is what disassembled a assembled code look like.

