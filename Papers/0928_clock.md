# Time, Clocks and Ordering of Events in DS
From partial ordering(which happens before) to logical clocks
and use of pyshical clocks

Seems to talk about two algorithms:
1: give the global order, and solved one sychronization problem
2: give the method to synchronize the physical clocks? 


## Intro
* "happened before" is partial ordering(two events can be concurrent)
* An algorithm to get total ordering from partial ordering
* Anomalous behavior (concurrent events not follow "phiscal observasion") -> introduce real clocks(and a algorithm to synchronize them with upper bound of drift)

## Partial Ordering
* process are sequencing events(a,b etc.) 
* a->b(happened before): a could influence b 
    * in single process, a happend before b 
    * double process, a is sending  message m, and b is receiving message m 
    * can pass, a->b b->c a->c

## Logical Clocks
* using the a->b, we can get logical clocks for distributed system (a litlle more complicated than partial ordering)
    * each process has clock, increasing between events 
    * when i sending message: 
        * add clocki into the message as Tm
        * j receive the message, adjust clockj to max(clockj, Tm+1)
* it does not indeed reflect the time of happeness     

## Ordering the events totally
* Purpose of logical clocks is to get events all around the system be ordered
    * just add a arbitrary order between processes, when a in pi and b in pj happens at the same logical clocks
* Used to reslove mutex resource problem
    * Each process owns a request queue stores every request of the resource
    * when request and release resource, process sends out messages
    * this algorithm has a problem: facing a process failed! 

## Anomalous Behavior
* Because logical clock truly not reflects physical time, a can happen before b, even when logical time a is larger than logical time of b

## Physical Clocks
* properly synchronized distribtued physical clocks can help 
* how to synchronize clocks in two machines never drift too large
    * similar method to constructing logical clocks (Tm+1 change to Tm+expected minimized transmission delay)
     