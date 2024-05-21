
#### Practice

Memory mapping:
- write a program that maps a file into memory using memory-mapped files.
- try mapping a large file that exceeds the available physical memory and see how OS handles virtual memory paging

Process Memory Layout
- develop a program that allocates memory dynamically (`malloc`) and print out the virtual memory addresses of the allocated memory regions
- Look at the memory layout of program by examining the stack, heap, code and data sections using a debugger or memory mapping tool
- try with different memory allocation patterns and observe how the memory layout changes

Page Fault Handling
- write a program that intentionally cause page faults by accessing invalid memory addresses or unmapped pages
- use a debugger or profiling tool to observe the page fault handling process, like calls to the OS kernel and so on

Virtual Memory Simulation:
- implement a simple virtual memory simulator that simulates the page table management, page replacement algorithm and page fault handling

Shared Memory
- Develop a program that uses memory for IPC between two or more processes

