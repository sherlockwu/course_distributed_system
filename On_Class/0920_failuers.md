# Failures
* History
	* Eniac    how to build reliable system out of unreliable parts (**Hardware**)
	* consider both software, people 
* Today
	* Gray
	* Toronto 
* Next: **hardware** hard drive/ SSD/ Mem/ Network    much more reading

## Failure
* faults(disk failure) -> errors (system call, return -1) -> failures (user/operator see a problem)

## Gray:
keys to building reliable/ available systems
* metrics:
	* reliability: doesn't break, Mean Time Between Failures
	* availability: MTBF/ (MTBF + MTTRepair) 
* how to build reliable/ available systems:
	* **ideas** not that often fail or not that long to repair
	* redundancy (MTRR indeed) 
	* Modularity/ Isolation 
		* OS (processes)
		* distributed systems 
			1. nice build-in: pyshical isolation
	* Fail-fast   working or stop 
		* RAID 
* study the failures:
	*  Big part admin    automation 
	* Big part software 
		* bugs:   Bohrbugs(Deterministic, should be catched through test)/ Heisenbugs(Non-Determin)
		*  
	* hardware/ configs 

## Modern study of Failures:


## Follow 3 papers: how disk fails? 
File system interact with disks 
* How disk fails? 
	* Single block fail vs. single block may corrupt ?   what's the difference
* How file system react to disk failures 
	* fault injection to superblock/ inode or blocks
* Why fault handling so difficult? 
* Robust File and Storage Problems:
	* file system may make mistakes: file system checker
		* turn corrupt image into consistent image  




## Ref
