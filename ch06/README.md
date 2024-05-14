# Chapter 6: The Memory Hierarchy

If you understand how system moves data up and down the memory hierarchy, then you can write your programs so that their items are stored higher in the hierarchy, where the CPU can access them more quickly.

the success of storage technology has been amazing over the years, in early days computers had few kilobytes of RAM and few megabytes of disk, but now days people take it for granted and that is why most programs are shit and using so much resources.

Random access memory(RAM) comes in two varieties, static and dynamic, static RAM (SRAM) is faster and significantly more expensive than dynamic RAM (DRAM), also SRAM is used for cache memory on chip, DRAM is used for the main memory plus the frame buffer of a graphics system, and typically most computers will have no more than a few tens of megabytes of SRAM but hundreds or thousands of megabytes of DRAM(need to study every computer and chip, for example apple M series computer)

SRAM has 6 transistor per bit, faster than DRAM, Persistent, not sensitive, expensive, used for Cache memory
DRAM has 1 transistor per bit, Not persistent, sensitive, chip, used for main memory and frame buffers

Data flows back and forth between CPU and DRAM main memory by electrical conduits called **buses**, each transfer between them called **bus transaction**, a read transaction transfer data from main memory to the CPU, a write transaction transfer data from CPU to main memory.  
a bus is a collection of parallel wires that carry address, data and control signals. just in summary buses are bridges between main memory

