# Implementing Remote Procedure Calls

## Intro
* Core: providing abstraction for communication between distributed systems, furthuremore assisting building distributed system
* Semantics/ Efficiency/ Generality 
* Aims:
	* Make communication semantic strong however, simple enough 
* Decisions: 
	* No shared address space in this paper, considering cost
	* Make semantic just like local procedure call
* Structure: 
	* user, user-stub(for pack arguments and unpack results), RPCruntime(in caller and callee), server-stub, server
	* Programmer write interface(procedure name, arguments setting) and caller, callee application -> use app to generate user/server stub -> call RPC library (may need user to provide destination address) resides in system 

## Binding (done to set user/server stub)
* Q: 
	* how to point out the specific destination user want to bound
	* how to locate the destination and invoke specific process when arrive the destination 
* Naming Mechanism (by user? why this level?) 
	* Caller calls through interface by dictate 1) type: which kind of interface(the procedure) 2) instance: the implementor of the interface
* Locating specific exporter   (many importer to one?)
	* Use db to store interface types and instances: 
		* type entry: store the instance entires list
		* instance entry: store the network address of this remote procedure
	* For server(exporter) to set these information
		* server calls the server-stub then call RPCRuntime;
		* RPC writes down the type, instance info., the dispatcher procedure from server-stub and a unique ID for the exporter 
	* For importer to bind to an exporter 
		* Call interface type and instance to user-stub then to user RPCRuntime 
		* User RPCRuntime checks with the remote: succeed: get and store the ID and table index; fail: bind fail 
	* When calling
		* caller send packet with information; callee check these information 
		* when caller can not point a callee instance, RPCruntime can find the closest and available exporter    
* Discussion:
	* Dictate to connect to instance, not distpatcher directly 

## Packet-Level Transport Protocol
* lightweight (implemented by RPC package)
	* ensure the procedure only precisely run once
	* not abort facing deadlock (same with local procedure calls)
* Simple call
	* support retransmission 
	* using call identifier ???
* Complicated calls:
	* Procedure too long: using probe packet
	* Argumets too long: using multi-packets transmission, each ACK for each packet   
* Exception: 
	* RPCRuntime can return exception in result, and hand-in to process
* Facing multi-processes (Approaches in the paper system)
	* Providing a process pool in the system
	* Support multi-processes, using process ID ... (need read more!)

## Performance
Not carefully read yet. 

## Ref 