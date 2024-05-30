# Chapter 12: Concurrent Programming

if logical control flows(I assume it means two or more processes or programs that contain bunch instructions that transfer control from one to next one) overlap in time, it means they are concurrent and it is called concurrency.

	The text defines a logical control flow as:
	[A] series of program counter values that [correspond] exclusively to              instructions contained in [a program’s] executable object file or in shared       objects linked to [it] dynamically at run time.


Concurrency shows up at many different levels of computer system. Hardware exception handlers, processes, Linux signal handlers, Application level Threads ...

