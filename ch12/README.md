# Chapter 12: Concurrent Programming

I think this topic deserve its own book and should read a book just about Concurrency and Parallelism. 


if logical control flows(I assume it means two or more processes or programs that contain bunch instructions that transfer control from one to next one) overlap in time, it means they are concurrent and it is called concurrency.

	The text defines a logical control flow as:
	[A] series of program counter values that [correspond] exclusively to              instructions contained in [a program’s] executable object file or in shared       objects linked to [it] dynamically at run time.


Concurrency shows up at many different levels of computer system and in many situations. Hardware exception handlers, processes, Linux signal handlers, Application level Threads ...

Some keywords to search about for Concurrent programming and Parallel computing:
**Concurrency, Parallel computing**,  
**Single-Core, Multi-Core, MultiProcessor**,  
**Multiprocessing, Multithreading**,  
**Symmetric Multiprocessing, Simultaneous Multithreading, green thread**  

as I understand from this book and read on the internet, you want to do Concurrent because you want to execute few to many programs(processes) at the same time, go smooth, use all the resources, fast, when you think in level of OS and many program you want to work with, this make so much sense than think about a Calculator program:))
so in hardware level they tried to put 2 to 16 or more Cores in a single CPU, each core can execute instructions independently. before there were only single-core CPU but when you can put billions of transistor in a small place they said why not many core in a single CPU?

also for a massive parallel computing, GPU is the best, have way more Cores, like a GeForce RTX 4090 has 16384 cores and only can do Arithmetic on Integers and Float data types.

the difference between CPU and GPU:

![cpu vs gpu](CPU%20vs%20GPU.png)
Credit: [Branch Education](https://www.youtube.com/watch?v=d86ws7mQYIg)

- Concurrency:

- Parallel computing:

- Single-Core processor:

- Multi-Core processor:

- MultiProcessor :

- Multiprocessing:

- Multithreading:

- Symmetric Multiprocessing:

- Simultaneous Multithreading:

- green thread: