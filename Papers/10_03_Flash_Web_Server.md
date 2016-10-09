# Flash: Efficient and Portable Web Server
Web server architectures
## Intro
* Requested files in mem or disk 

## Background
* accept conn -> read request -> find file -> send response header -> Read file -> Send data (How to interleave these operations since blocking)

## Server Architecture
* Multi-Process: processes are scheduled when blocking to realize concurrency
* Multi-threaded: kernel threads must(one thread block, other threads can go to CPU)
* SPED: (single process event-driven)
    * use un-block operations(except disk operations)
    * keep acting on different steps of different steps 
    * multi-SPED could also help 
* Asymmetric Multi-Process Event-Driven
    * has helper processes to hadnle blocking disk operations
    * finish, then notify main server process

## Design Comparison

## Flash Implementation 
* Some techs
    * Pathname translation caching
    * Response Header Caching
    * cache some files in mem

## Performance Evaluation 

## Related work

## Conclusion