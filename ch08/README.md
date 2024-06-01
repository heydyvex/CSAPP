# Chapter 8: Exceptional Control Flow

I think the whole idea of Exceptional Control Flow (ECF) is how to control flow and unexpected situations (No shit Sherlock). ECF exist at all levels of computer systems and level matters, like in you program and in processor there are different kind of ECF that need to be handled.

Exception
exceptions are a form of exceptional control flow that are implemented by hardware and OS.
Processor is executing instructions normally, a change in the processor's state (called an event) happen then that event triggers an abrupt control transfer (an exception) from the application program to an exception handler, after it finishes processing, the handler either returns control to the interrupted program or aborts.

event might be exactly related to the execution of the current instruction. e.g. a virtual memory page fault occurs, an arithmetic overflow occurs, an instruction attempts a divide by zero. or on the other hand the event might be unrelated to the execution of the current instruction, e.g. system timer goes off or an I/O request completes.

when the processor detects the event, it makes an indirect procedure call (an exception), through a jump table called an exception table, to an OS system subroutine which is exception handler that is designed to process this particular event. after exception handler finishes processing, three things can happen:
- handler returns control to the current instruction 
- handler returns control to the next instruction
- handler aborts the interrupted program

each type of possible exception in a system is assigned a unique nonnegative integer exception number, some of them assigned by designers of processor and others are assigned by the designer of the OS kernel.
for processor example are: page faults, divide by zero, memory access violations, breakpoints and arithmetic overflows, for OS kernel are system calls and signals from external I/O devices.

once the hardware triggers exception, the rest of the work is done in software by OS's exception handler.

Classes of Exceptions:
- interrupts: signal from I/O devices, Async,  Always returns to next instruction.
- traps: Intentional exception, Sync, Always returns to next instruction.
- faults: Potentially recoverable error, Sync, Might return to current instruction.
- aborts: Nonrecoverable error, Sync, Never returns.

Async exceptions occur as a result of events in I/O devices that are external to the processor, Sync exceptions occur as a direct result of executing an instruction

examples of exceptions in x86-64 systems:

| Exception number | Description              | Exception class   |
| ---------------- | ------------------------ | ----------------- |
| 0                | Divide error             | Fault             |
| 13               | General protection fault | Fault             |
| 14               | Page fault               | Fault             |
| 18               | Machine check            | Abort             |
| 32-255           | OS-defined exceptions    | Interrupt or trap |

System Call
Syscall are simply functions provided by OS kernel for applications for requesting services from kernel to do. like : open, read, write, exit, pause, kill, so on...  
every syscall has a number like exception number, for example if you want to call a syscall in assembly, so you can store that number in a register so you can call it.

Processes
Exception are basic building blocks that allow and help operating system kernel to provide the notion of a process.  
Process is a concept, **every computer program that is being executed is a Process**  
like you run a program from shell, it is a process and has its own:
- Memory Space
- Execution context
OS provide this abstraction and make these illusions that Program has exclusive access to processor, memory, I/O devices etc.
- An independent logical control flow that make illusion that program has exclusive use of the processor
- A private address space that provides illusion that our program has exclusive use of the memory system
In reality every process is isolated from another, one process cannot access to another process's data or information, one cannot corrupt another's memory, every process is separated by OS.


Concurrent Flow 
if process A runs and takes too long to complete, then process B have to wait.
OS try to solve this problem by concurrent flow, A and B execution overlaps in time with each other, called being executed concurrent. for example A begins to be executed then stop after few millisecond, process B begins to be executed stop after few millisecond then A start to to be executed then switch to B and overlapping each other until they are done.  
it is like they’re running concurrent but processor is just switching between them to execute and make the illusion of concurrent
Parallel execution is different, A and B truly are executed in Parallel in two Core processor


![concurrent vs parallel](ZktFr.png)


User mode and Kernel Mode
there are two modes in computer systems provided by OS, program with user mode cannot execute some instructions(privileged instructions), program with kernel mode can execute any instruction like halt the processor, initiate an I/O operation.


each process has a unique process ID(PID, positive number),  
from programer's perspective, process have three states: Running, Stopped, Terminated
(Read about syscall functions that are related to process control)
process can create another process called child process and the process that create other process called parent process

there is also higher level software form of exceptional control flow, called Linux signal,  signal is a very small massage that notifies process that an event happened in system. It’s Kernel job to send signal to process also it can happen by process to receive signal that is forced by kernel to react.

also at application lever specially in C, program can use nonlocal jumps to bypass normal call or return stack and branch directly from one function to another