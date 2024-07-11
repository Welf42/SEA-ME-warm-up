# Multithreading

## Broader context: Concurrency

Concurrency means executing multiple tasks at the same time but not necessarily simultaneously. When you have to perform more than one task but you have a single resource then we go for concurrency. In a single-core environment, concurrency is achieved by context switching.

There are several scenarios in which concurrency can occur:
<!-- Maybe some kind of definition:  Sync vs. Async / -->

1. Asynchrony — This means that your program performs non-blocking operations. For example, it can initiate a request for a remote resource via HTTP and then go on to do some other task while it waits for the response to be received. It’s a bit like when you send an email and then go on with your life without waiting for a response.

2. Parallelism — This means that your program leverages the hardware of multi-core machines to execute tasks at the same time by breaking up work into tasks, each of which is executed on a separate core. It’s a bit like singing in the shower: you’re actually doing two things at exactly the same time.

3. Multithreading — This is a software implementation allowing different threads to be executed concurrently. A multithreaded program appears to be doing several things at the same time even when it’s running on a single-core machine. This is a bit like chatting with different people through various IM windows; although you’re actually switching back and forth, the net result is that you’re having multiple conversations at the same time.


## Some header (collection of info)

### Mutex
- Mutex is a specific kind of binary semaphore that is used to provide a locking mechanism. It stands for Mutual Exclusion Object. Mutex uses two operations: Lock & Unlock.
- A mutex is a locking mechanism used to synchronize access to a resource. Only one task (can be a thread or process based on OS abstraction) can acquire the mutex. It means there is ownership associated with a mutex, and only the owner can release the lock (mutex).
- Use a mutex when you (thread) want to execute code that should not be executed by any other thread at the same time.
### Semaphore
- A semaphore is a non-negative integer variable that is shared between various threads. Semaphore works upon signaling mechanism, in this a thread can be signaled by another thread. Semaphore uses two atomic operations for process synchronisation: Wait & Signal
- Use a semaphore when you (thread) want to sleep till some other thread tells you to wake up.



## Game Design
- Simple design would be to use progress bars and run a thread for each bar indicating distance of car on track.
- Advanced design requires a 2D racetrack design using andvanced Qt graphic libraries, such as QGraphicsView, QGraphicsScene, and QGraphicsItem.

## Ressources
- https://www.geeksforgeeks.org/mutex-vs-semaphore/
- 

## Tutorials
- 
- Videos on QGraphicsView, QGraphicsScene, and QGraphicsItem
- https://www.youtube.com/watch?v=4AyZ1Mmg8Ow
- https://www.youtube.com/watch?v=lmhfF6f-Emw