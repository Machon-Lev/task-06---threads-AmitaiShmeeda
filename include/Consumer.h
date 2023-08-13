#ifndef CONSUMER_H
#define CONSUMER_H

#include "SafeQueue.h"
#include "Message.h"

class Consumer {
public:
    // Constructor: Initializes Consumer with a message queue and the number of producers
    Consumer(SafeQueue<Message>& queue, int numProducers);

    // The main execution function for the Consumer thread
    void run();

private:
    SafeQueue<Message>& messageQueue;    // Reference to the shared message queue
    int numFinishedProducers;            // Number of producers that have finished
    int maxFinishedProducers;            // Total number of producers
};

#endif // CONSUMER_H
