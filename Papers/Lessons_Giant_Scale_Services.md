# Lessons from Giant-Scale Services
Availability is important

## The Basic Model
* Advantages of Giant-scale services (some)
* Basic model:
	* Queries-driven service and read mostly
	* Client, IP netowrk, Load manager, servers, Data store, backplane to connect servers
* Load management:
	* Different switch techs

## High Availability
* Availability Metrics:
	* uptime(MTBF, MTRR) -> yield (measure availability in the query format)/ harvest (in data format)
	* some relations: 
		* fault -> 1. replicated (no influence to harvest,ok; then, when high utilization, which means each server in high-load, influence the yield, cannot handle all queries)
		* fault -> 2. partitioned (of course, influence to harvest; then, with stable load in left servers, the capacity in queries (yield) remains the same)
	* DQ Principle: 
		* data/ query multi queries/second    -> constant 
		* DQ correlated to the number of nodes 
	* compare replication and partitioning using DQ
		* Rep: Q down;  Par: D down    (grab the notion of yield and harvest)
	* Graceful Degradation  (control on D,Q)
		* Admission Control/ Database Reduction
	* Use Replicas for Disaster Tolerance


## Online Evolution and Growth 
* Completing upgrades without taking down the site
* Several methods

## Conlusions

## Ref 