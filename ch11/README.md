# Chapter 11: Network Programming

Most network application is based on the client-server model. in this model, an application consists of a server process and one or more client processes.
the fundamental operation in the client-server model is the transaction, client-server consists of four steps:
- when client needs service, it it initiates a transaction by sending a request to server.
- the server receives the request, interprets it, and manipulates its resources in appropriate way.
- the server sends a response to the client and then waits for the next request.
- the client receives the response and manipulates it.
(client-server transactions has nothing to do with database transactions, these two are different things and do not share any of their properties)

client and server are processes and not machines or hosts as they are called, a machine can run run many different clients and servers concurrently.


client and servers often run on separate machines(hosts) and communicate using computer network, networks are complicated and sophisticated systems.
there is model called OSI model that consists of 7 layers:

![OSI model](assets/OSI-7-layers.jpg)

top layers are software(7, 6, 5) and programs, and bottom(1, 2, 3) layers are hardware.
softwares are protocols that everyone is agreed to follow, hardwares are different types with different functionality like: network adopter(Ethernet or Wireless), Router, Switch, cable(fiber or something else), radio wave devices(satellite) etc...

Network adopter is just another I/O device that transfer data to memory by DMA.

TCP/IP is family of protocols for internet and communication for now(2024) and will remain this way until we have better or another way to communicate, this protocol is implemented in all host and computers, if you want to write a application you will most likely going use sockets interface and Unix I/O functions, you will communicate with OS kernel and OS kernel with network adopter.

I read a book about network and internet so I'm not gonna spend my time on this subject, I just don’t understand sockets in C and how to make a communication in C program.

