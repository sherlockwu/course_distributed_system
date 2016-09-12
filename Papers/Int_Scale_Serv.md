# On Designing and Deploying Internet-Scale Services 
Internet-Scale service must own more automation.
## Intro
We need to take techs while we 1) expecet failures 2) keep simple 3) automate everything. 
## Recommendations
* Overall App Design
	* Need collaboration between development, test and operation teams
	* Basics: 
		* Failure recovery: service can continue without unacceptable loss 
		* Redundancy, in addition to expensive server
		* Commodity hardware slice: cheap, I/O, low power, independent
		* Single-version software
		* Multi-tenancy
	* More:
		* Develop in the full environment 
		* Zero trust to underlying components: 1.continue using cache, or 2. choose a tiny fraction of the user 
		* Use plan and script when need human intervention
		* Admission control at all levels 
		* Partition service to develop
		* Understand network design 
		* Analyze throughput and latency 
		* Understand potential load from new features 
		* Avoid single points of failure using load balance things 
* Automatic Management and Provisioning 
	* There are trade-offs for automation
	* Practices: 
		* Redundant and restartable 
		* Geo-distribution 
		* ???? What is automatic provisioning and installation 
		* Configuration and code as a unit
		* Recover at the service level  
* Dependency Management  
	* Expect latency
	* Prevent cascading failures 
	* Using proven components
	* Try to decouple components when overload (like only authenticate after longer time, not each session)
* Release Cycle and Testingg
	* Ship often 
	* Use production dat ato find problems
		* Many practices
* Hardware Selection and Standadization 
	* Using standard SKU
	* Abstract the network and naming (for convenience)
* Operations and Capacity Planning 
	* Prepare well recovery scripts
* Auditing, Monitoring and Alerting
	* Use logs 
	* Alert appropriately  
		* notice latencies
		* Have sufficient production data for analysis
* Graceful Degradation and Admission Control (when overload)
	* "A big red switch"   keep the vital ones processing 
	* Control admission: queue requests 
	* Meter admission  slow restart
* Customer 
	* To improve customer satisfication  

## Conclusions
* Service reliability by being operations-friendly 
* Best practices for it

## Ref