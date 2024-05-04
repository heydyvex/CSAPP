# Chapter 2: Representing and Manipulating Information

[some homework problem](problem/)  

## Notes

Binary digits(bits) are used in computers and representing data, because it is easy to do, high or low voltage, turn on or turn off, Up or down etc...

Instead of single bit block for memory, 1 byte(8 bits) is used for 1 block in memory and byte is the smallest unit of memory that is assessable.

A single byte is 8 bit from 00000000 to 11111111, decimal equivalence is from 0 to 255.
Mathematician thought **Hexadecimal** would be better to describing bit patterns, Hexadecimal(hex) is base 16, from 0 to 9 and from A to F.

| Hexadecimal | Decimal | Binary |
| ----------- | ------- | ------ |
| 0           | 0       | 0000   |
| 1           | 1       | 0001   |
| 2           | 2       | 0010   |
| 3           | 3       | 0011   |
| 4           | 4       | 0100   |
| 5           | 5       | 0101   |
| 6           | 6       | 0110   |
| 7           | 7       | 0111   |
| 8           | 8       | 1000   |
| 9           | 9       | 1001   |
| A           | 10      | 1010   |
| B           | 11      | 1011   |
| C           | 12      | 1100   |
| D           | 13      | 1101   |
| E           | 14      | 1110   |
| F           | 15      | 1111   |

markdown table with hexadecimal, decimal, and binary representations from 0 to 15.
there is bunch of practice for how to convert these numbers system to each other, I don’t get into that here.

word size, indicate the size of pointer data, virtual address space is where there is range of addresses pointing to some blocks of memory, 32 bit word size system means that each pointer is 32 bit, a virtual address space can address to 2^32 byte memory (32 bit can handle 4 Gigabyte and 64 bit can handle 16 Exabyte)
64-bit and 32-bit is about CPU architecture just keep that in mind, registers only can carry amount of CPU's word size, which can be 32 or 64.

book is talking about C data types and amount of memory for each one (byte), I don’t list them here.

a pointer is a simple address that is pointing to a data in memory, type of pointer indicate the type of the data it's pointing at.


for a program object that is multiple bytes, there must conventions to how to order bytes in memory and what would address of the object be.

a multi-byte object is stored as contiguous sequence of bytes(next to each other) and for example you have value `x` type `int` has address `0x100` then the 4 bytes would be stored in memory location `0x100, 0x101, 0x102, 0x103`.

for ordering bytes that representing an object there are two conventions, *little endian* and *big endian*.
in little endian system the byte with smallest weight(least significant byte) is stored first. and in big endian vice versa, the byte with largest weight(most significant byte) is stored first.
for example: you have `0x02346798` at address `0x100`  
**little endian** would look like:

| `0x100` | `0x101` | `0x102` | `0x103` |
| ------- | ------- | ------- | ------- |
| `98`    | `67`    | `34`    | `02`    |

**big endian** would look like:

| `0x100` | `0x101` | `0x102` | `0x103` |
| ------- | ------- | ------- | ------- |
| `02`    | `34`    | `67`    | `98`    |

Boolean algebra is the core principle of how computer encode, store, and manipulate information, boolean algebra is about **True** and **False** or **1** and **0** for logical reasoning and there is three fundamental operations `NOT` , `AND`, `OR`

Wow, I didn’t know Claude Shannon was the person who made the first connection between algebra and digital logic.

bit-level operation in C is a little confusing with hexadecimal, because it turn it to bit (bit-level) and do operation, just don’t be an idiot when you see it again.

Integer Representation can be encoded in two different ways, one that can only represent nonnegative numbers(Unsigned integers in C), one that can represent negative, zero, and positive numbers(Signed integers in C) and there is a maximum range that can be stored in one integer variable (it is 64-bit all 1 ).

rest of the chapter is boring, just taking a look only.