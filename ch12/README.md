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

![cpu vs gpu](/assets/CPU%20vs%20GPU.png)
Credit: [Branch Education](https://www.youtube.com/watch?v=d86ws7mQYIg)

- Concurrency: is a general word for: "executing two or more tasks(processes) at the same time", it could be illusion of executing at the same time(time slicing) or truly parallel execution

- time slicing and context switching: a form of concurrency that OS kernel use scheduling and time slicing and context switching to make two or more processes to get executed at same time but it is not really at the same time only illusion.

- Parallelism and parallel computing: Parallelism means two or more tasks(processes) truly being executed at the same time, like for real.

- Single-Core processor: a processor that has only one Core that execute instruction.

- Multi-Core processor: a processor that has 2 to 32 Core that each one can independently execute instructions(in parallel).

- MultiProcessor : two or more CPU(a whole processor not a Core) that can execute instructions in parallel but share main memory.

- Multiprocessing: executing Processes at the same time and distribute them across the Cores or processors to get them executed in parallel. each process have their own address and memory space and is not shared but they can share using IPC.

- Thread and Multithreading: thread is part a process, it is hard to do multiprocessing when processes have their own address and memory separated. but threads shares parent process address and memory address so it is easier to concurrency and parallelism, and usually in applications, threads are used to make application concurrent, a process can be divided into many threads so to make it parallel

- green thread: also called virtual thread, is a thread that is scheduled by runtime library or virtual memory instead of natively by the OS, it means not relying on OS kernel ability and they are managed in user space not in kernel space. Golang use green threads but runtime actually and obviously rely on OS and programmer won’t see that part I guess.

more pictures to understand time slicing concurrency and parallelism:  

![Concurrency vs Parallelism](/assets/ZktFr.png)
![sequential vsconcurrent vs parallel](/assets/bsdfwer.png)
![concurrent vs parallel](/assets/Concurrent%20vs%20parallel.webp)
