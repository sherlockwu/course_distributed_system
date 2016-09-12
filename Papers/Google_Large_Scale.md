# Building Large-Scale Internet Services

## Implications
Reliability and Availability are supposed to come from software

## Google Computational Environment
* Overview:
	* GFS/ Colossus file system
	* Cluster Scheduling    assign resources to jobs 
	* MapReduce 
	* Bigtable semi-structured storage system
* MapReduce
	* have some considerations in practice on input and output
* BigTable
	* Semi-structured data 
	* (row, column, timestamp) -> content, row in lexicographically
	* System overview (need to read the paper)
	* Bigtable Replication/ Coprocessors
* Spanner

## Techs for large-scale systems
* protocol buffer? 
* Estimate performance of a system 
* identify common needs
* Some patterns: 
	* one master, many workers
	* Canary Requests:  prevent all crashes by testing several at first
	* Tree:  to distribute reuqest throughput to many nodes
## Challenging

## Ref 