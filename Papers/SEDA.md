# Staged Event-Driven Architecture

## Motivations
* Web Service

## SEDA
* SEDA architecture
    * has stages(as basic modules): input event queue -> event handler(thread pool)
    * and a controller to adjust resource allocations and scheduling: 
        * adjust number of threads in thread pool
        * adjust number of events processed in each invocation of a event handler
* A http server
    * stages pipelined by message queues
    * dynamically control each stage
* Gnutella p2p file sharing
    *  stages: 1 . connetction handling 2. Table, Process and route 3. Host discovery

## Comparison

## Conclusion
* resource control based on measurement