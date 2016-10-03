# Analysis of Production Failures in Distributed Data-Intensive Systems
Find some regularity of failures in distributed system. 
Manual Analysis indeed

## Intro
Explore why current tested distributed system can experience failures

## Methodology and Limitations
Choose some of the reported failures to analyze.

## General Findings
* Complexity of Failures
	* almost no more than three input events in diverse permutations
* Improving Opportunities  
	* some popular causes like starting up services, adding a node etc. 
	* Almost all failures manifest on no more than 3 nodes
* Role of Timing
	* almost all deterministic failures (occurs definitely when sequence of inputs happen)
* Logs enable diagnosis
	* many failures result from wrong error handling
* Failure Reproducibility
	* Easy to reproduce with unit test 
	* only need input sequences, not data 

## Catastrophic Failures
* Almost all catastrophic failures results from incorrect error handling 
* Incorrect handling
	* Trivial Mistakes
		* Errors ignored 
		* Over-caught -> abort
		* TODO in handler  
	* System-specific 
		* Use symbolic execution tech 
* Method: 
	* test the code in exception handlers 

## Aspirator: A Simple Checker
* Implementation
	* static check the exception handlers 
* Got good experience checking real systems

## Related Work   

## Ref
