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
Syscall are simply functions provided by OS kernel for applications for requesting services from kernel to do. like :open, read, write, exit, pause, kill, so on...  
every syscall has a number like exception number, for example if you want to call a syscall in assembly, so you can store that number in a register so you can call it.

