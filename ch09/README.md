# Chapter 9: Virtual Memory


OK, Processes share hardware resources obviously, CPU, main memory, etc with others.
sharing main memory is challenging somehow, what if one process use too much and others cannot be executed? or for security, what if a process try to corrupt another one? etc...

Virtual Memory (VM)
is an interaction of hardware exceptions, hardware, address translation, main memory, disk files, kernel software that provides each process a large, secure, private address space.
three important capabilities:
- treats main memory as cache for an address space stored on disk, keeping only the active areas in main memory and translating data back and forth between disk and memory as needed.
- simplifies memory management by providing each process with a uniform address space
- protects the address space of each process from corruption by other processes

without VM, CPU access directly the real actual physical address of main memory(each byte of main memory has a unique real address), with VM, CPU access to a virtual address, then MMU(memory unit management) translate that into physical address.

![system that uses virtual addressing](assets/mmu1.gif)

MMU is a cooperation between CPU and OS, dedicated hardware on CPU called MMU translate using a lookup table stored in main memory that contents are managed by OS

every byte of main memory has a virtual address chose from the virtual address space and a physical address chose from a physical address space.

Virtual Page
A virtual page is a fixed-size block of virtual memory addresses, virtual address space of a process is divided into equal-sized virtual pages, typically ranging from 4KB to 2MB (depends on OS and Hardware architecture), every virtual page has a corresponding entry in the page table which maps the virtual page to a physical page frame in RAM or to a location on disk.

Page Fault
this error happens when the process attempts to access a virtual page but its corresponding physical page is not present in memory.

page fault is an event so an exception that raises by processor and caught by the OS's MMU, then OS look at the error to determine if it is legitimate access, then try to load page frame to physical memory from disk and updates page table then rerun previous instruction.

overall VM make memory management a lot easier and this technique has a large impact on computer systems.  
also VM make memory protection a lot easier.

memory mapping is associating virtual memory area with an object(typically a file) on disk.