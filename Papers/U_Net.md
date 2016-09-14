# U-Net: A user network interface for parallel and distributed computing 
rewritten network interface ?    why for distributed computing? 
## Intro
Thinking:
	1. provide processes a view of access to comminucation device (what view? )
	2. user can construct new protocols with good performance  (why good performance ?)
Motivation:
	1. network soft path became the bottleneck (distributed applications need low round-trip latencies and high bandwidth)
	2. flexible protocol defined by APP can help 
Decision: 
	1. the protocol should be placed in user space (some hardware, OS issues)
	2. issue: designing a programming interface to the network
Contribution:
	designed a user-level communication architecture

## Motivation 
* low communication latencies
	* small messages in LAN become important in distributed systems 
	* while process overhead plays an important role to those messages' latency 
* small-message bandwidth
	* also imporant for the same reason 
* protocol and interface flexibility
	* For using specific techs(like reducing mem copies) to optimize specific apps, integrating user-level network access with kernel is important
* new networking architecture
	* key: directly remove the kernel path from network 
	* need to handle multiplexing and demultiplexing (set this into network interface with kernel only to setup it)
	* buffer management and protocol processing at User-level
	* final: user have a virtual view of NI(with already multiplex functions) 

## User-level network interface architecture
the interface of a user to set send/receive mechanisms
* sending and receiving messages
	* architecture: each process owns a endpoint as handler to the network
		* endpoint has a communication segment for storing data
		* and queues storing pointer to the segments  (recv que, send que, free que)
	* sending: 
		* process write into segment and send que (then automatically the NI will fetch)
	* receiving:
		* NI write into specifc endpoint (using destination)
		* process block to read received data or set upcalls 
* multiplexing and demultiplexing messages
	* multiplex and demultiplex and the architecture of U-Net ensure the seperation of each process's accessing to NI
* Zero-copy vs. true zero-copy
	* Base-level U-Net
		* need to copy data from process to its communication segment
	* Direct-Access U-Net
		* process's communication segmeent share the address space with the process (store pointers in the segment to the true mem address, using when NI fetch sent messages and write back received messages)
* Base-level U-Net architecture
	* communication segment locate in a pinned memory
	* this mem is aligned for using DMA
	* together use with recv/ send/ free queue
	* an optimization for short message: store message directly in descriptor
* Kernel emulation of U-Net
	* since segment and queues are scarce resources, let processes share a endpoint
	* then process own a kernel-emulated U-Net endpoint(just virtually the same)
* Direct-Access U-Net architecture
	* quite difficult

## Implementations
Implementation of U-Net based on some architecture and hardware

## Active Messages implementation 
* Based on U-Net, designed the mechanism to realize AM
* Then benchmarked the system

## Benchmarks
* To see impact of U-Net based communication to distributed applications
* This application now is based on Split-C, a parallel programming language

## TCP/IP and UDP/IP 
* Implement TCP with high performance
* Providing flexibility to TCP/ UDP  (do not need to consider buffer size etc.)
* Make it possible to get application controlled flow-control and feedback

## Ref 
* Provide a Network Interface to user which could lower processing overhead, as well as provide more flexbility to realize network protocols