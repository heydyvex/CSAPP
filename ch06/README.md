# Chapter 6: The Memory Hierarchy

If you understand how system moves data up and down the memory hierarchy, then you can write your programs so that their items are stored higher in the hierarchy, where the CPU can access them more quickly.

the success of storage technology has been amazing over the years, in early days computers had few kilobytes of RAM and few megabytes of disk, but now days people take it for granted and that is why most programs are shit and using so much resources.

Random access memory(RAM) comes in two varieties, static and dynamic, static RAM (SRAM) is faster and significantly more expensive than dynamic RAM (DRAM), also SRAM is used for cache memory on chip, DRAM is used for the main memory plus the frame buffer of a graphics system, and typically most computers will have no more than a few tens of megabytes of SRAM but hundreds or thousands of megabytes of DRAM(need to study every computer and chip, for example apple M series computer)

SRAM has 6 transistor per bit, faster than DRAM, Persistent, not sensitive, expensive, used for Cache memory
DRAM has 1 transistor per bit, Not persistent, sensitive, chip, used for main memory and frame buffers

Data flows back and forth between CPU and DRAM main memory by electrical conduits called **buses**, each transfer between them called **bus transaction**, a read transaction transfer data from main memory to the CPU, a write transaction transfer data from CPU to main memory.  
a bus is a collection of parallel wires that carry address, data and control signals. just in summary buses are bridges between main memory.

I guess this specific field is changing so fast and getting better and better, need to read latest documents.

Disk Storages are very huge storage devices that can hold enormous amounts of data, on the order of hundreds to thousands of gigabytes unlike RAM-based memory.  but it takes very long to read and write data to disks. make sure to read about SSD disk storages they are very faster than HDD.

Locality, well-written programs tend to have good locality, locality in simple term means having all the data and instruction close together, this is principle of locality.  
there are two kind of locality, temporal and spatial
- temporal locality: a memory location that is referenced once is likely to be referenced again multiple times in the near future
- spatial locality: if a memory location is referenced once, then the program is likely to refrence a nearby memory location in the near future.

programs with good locality run faster that programs with poor locality. in hardware level principle of locality allows hardware designers to speed up main memory access by building small small fast memories known as cache memory, in Operating System level PoL allows the system to use main memory as a cache of the most recently referenced chunks of the virtual address space, also OS uses main memory to cache the most recently used disk blocks in the disk file system, in application level web browsers exploit temporal locality by caching recently referenced documents on a local disk, Web servers hold recently requested documents in front-end disk caches that satisfy requests for these documents without requiring any intervention from the server.

Memory hierarchy:
 ![Memory hierarchy](word-image115.png)

if level is close to 0, time of access to data is lower means it is so fast, and it is expensive per bit, if level is close to 4 time of access to data is higher means it is slow and it is chip per bit

I need to read more about caching, It seems cool and necessary