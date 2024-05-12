# Chapter 4: Processor Architecture

Modern microprocessors are among the most complex systems ever created by humans, in fact it is nanotechnology, billions of transistor in a very small space. it is improved very very much since the first silicon chip, and got cheaper than it was before, for example apple M4 chip is the most powerful chip in the world that you can "buy" and it is cheap as hell, cannot wait to see what will come in the next decade.

there are many instruction set architecture(ISA) for example IA32, x86-64, ARM etc... a program compiled for one architecture will not run for other architecture(different chips but under a ISA family will be compatible).

I'm really want to know how chip can distribute instructions to many cores to execute them simultaneously not one at a time, I we are going to know how has been solved.

OMG it is unbelievable that first supercomputer named Cray 1 was produced in 1975, was the fastest computer in the world, able to perform 250 million arithmetic operations per second, 8 megabytes of RAM, 5,000 kg, consumed 115 kilowatts, cost $9 million, and only 80 of them were manufactured(it was not scalable clearly). now compare to nowadays phones or even smaller than phone. now you tell me how not to love this field?

We are going to understand how Hardware works and process instructions under the hood.

Y86-64 ISA is simpler than x86-64, is programmer-visible state (each instruction can read and modify some part of the processor state), there are 15 program registers same as x86-64, each 64-bit word, there are three single-bit condition codes `ZF, SF, OF`

Instruction encoding, the part that instruction get encoded into hex numbers and after that binary of course. 
`rmmovq %rsp, 0x123456789abcd(%rdx)` to encode this to hexadecimal, need to look up to instruction encoding list, for example `rmmovq` is `40` in the list, `rsp` is `42` and `0x123456789abcd` is `00 01 23 45 67 89 ab cd` reverse order is `cd ab 89 67 45 23 01 00`.  
the whole instruction encoding is `4042cdab896745230100`

CISC and RISC are two category for ISAs, CISC stands for "complex instruction set computer" and pronounced "sisk", RISC stands for "reduced instruction set computers" and "risk", x86-64 is a CISC, huge and complex, ARM is sort of RISC, simpler and tinier (but really are they?).  
life advice: be RISC and make it you philosophy, everything you build make it RISC too.

Major components are required to implement  a digital system: combinational logic to compute functions on bits, memory elements to store bits, clock signals to regulate the updating of the memory elements.

electronic circuits have a general use in many varieties of task .e.g: are used to represent 0(low vol) and 1(high vol), to compute functions on bits and store bits in different kind of memory. electronic circuit can be simple component like transistor or very complex involving thousands or millions of components interconnected.
also they can be used for analog not only digital systems.

Logic Gates are Boolean functions take and input(true or false, 1 or 0) and give output(true or false, 1 or 0), specific types of digital circuits that perform  logical operation on binary inputs, and three most fundamentals are `AND, OR, NOT`, they used as basic compute elements.

![Gate_in_Computer_Science_reference](/assets/Gate_in_Computer_Science_reference_sheet_e70131cb-748f-488f-9257-6149e56781d1_1024x1024.webp)

there are also other logic gates as seen in photo, fancy names but very simple. when you put these functions together you make magic called computer, Claude Shannon find this first (to make logic gate out of Boolean Algebra) by attending to philosophy class so do not forget to read philosophy.

when you put these function together(with some rules) they construct blocks known as combinational circuits, something:

![combinational circuits](/assets/combinational_circuit_design_Limited_Gate_Inputs_Example_3.webp)


Oh god, not getting into details, I'm in rush for my journey.

Stages or steps of a performed instruction in processor:
- Fetch stage: fetch the instruction from memory
- Decode stage: Decode the fetched instruction and read the required operands
- Execute stage: Performs the actual operation specified by the instruction
- Memory stage: Read from or writes to memory if the instruction involves memory access
- Write-back: writes the result back to the appropriate register or memory location

Principles of Pipelining, what is pipelining?   
in a situation where there is no pipelining, an instruction would complete all stages and after that, next instruction would start from first stage and so on...,  
in a situation where there is pipelining, first instruction fetch then go to next stage, second instruction fetch and so on...
Pipelining vs non-pipelining:
![Pipelining vs non-pipelining](/assets/pipelined-vs-non-pipelined-instruction-execution.jpg)


I think the best way to understand it, is to design one (a chip). book didn’t get into it that much.