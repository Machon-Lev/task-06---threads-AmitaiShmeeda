#ifndef PRODUCER_H
#define PRODUCER_H

#include "SafeQueue.h"
#include "Message.h"

class Producer {
public:
    // Constructor: Initializes a producer with a thread ID and message queue
    Producer(int id, SafeQueue<Message>& queue);

    // The main execution function for the Producer thread
    void run();

private:
    int threadId;                    // ID of the producer thread
    SafeQueue<Message>& messageQueue; // Reference to the shared message queue
};

#endif 
