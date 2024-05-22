# Chapter 10: System-Level I/O

this chapter is about Unix I/O

Input/output (I/O) is the process of communication between a computer(CPU and Main memory) with other devices like keyboard, disk, monitor, network(internet) and etc...
input copies data from an I/O device to main memory and output copies data from memory to a device.
input: sending data and instructions **to** the Main memory and then CPU from outside world(I/O devices)
output: sending data and instructions **from** the CPU then Main memory to outside world(I/O devices)

C provides a standard I/O library for I/O operations, like `printf` and `scanf` functions,  
these higher-level functions are implemented by system-level Unix I/O functions provided by kernel. (it is different in systems that are not Unix-base like windows)


Unix I/O
A linux file is a sequence of m bytes.  
In Unix-based(specially linux) all I/O devices such as disk, monitor, terminals, networks are modeled as files, and all input and output is performed by reading and writing files. this mapping of devices to files allows the linux kernel to export a simple, low-level application interface(API) known as Unix I/O that make all input and output to be performed in a uniform and consistent way.


Files
a regular file contains arbitrary data, Application programs distinguish between text files(ASCII or Unicode) and binary files, but to the kernel no difference between text and binary files.
A linux text file consist of a sequence of text lines and each line is terminated by a newline(`\n`).   
A directory is a file consisting of an array of links each link maps a filename to a file or directory.  
A socket is a file that used to communicate with another process(programs) across the network(internet, another computer)

by typing `/` in terminal, it goes to the root directory, Kernel organize all files in a single directory hierarchy anchored by the root directory called slash `/`. 