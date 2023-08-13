#include "../include/Consumer.h"
#include <iostream>

// Constructor for the Consumer class
Consumer::Consumer(SafeQueue<Message>& queue, int numProducers)
    : messageQueue(queue), numFinishedProducers(0), maxFinishedProducers(numProducers) {}

// The main execution function for the Consumer thread
void Consumer::run() {
    // Continue processing messages until all producers have finished
    while (numFinishedProducers < maxFinishedProducers) {
        // Create a Message object to hold the popped message
        Message message;

        // Try to pop a message from the queue
        if (messageQueue.tryPop(message)) {
            // Check if the popped message indicates that a producer has finished
            if (message.isLast()) {
                // Increment the count of finished producers
                numFinishedProducers++;

                // Print a message indicating that a producer has finished
                std::cout << message.getThreadId() << " finished." << std::endl;
            }
            else {
                // Print the thread ID and the sent value from the message
                std::cout << message.getThreadId() << " sent: " << message.getValue() << std::endl;
            }
        }
    }
}
