// This project was completed by Amitai Shmeeda in C++.
// It includes implementations for the SafeQueue, Producer, and Consumer classes,
// as well as the main program to coordinate their interactions.

#include "../include/SafeQueue.h"
#include "../include/Producer.h"
#include "../include/Consumer.h"
#include <thread>
#include <vector>

int main() {
    // Create a thread-safe queue to hold messages between producers and consumer
    SafeQueue<Message> messageQueue;

    // Number of producer threads
    int numProducers = 2;

    // Create a vector to hold producer threads
    std::vector<std::thread> producerThreads;

    // Start producer threads
    for (int i = 1; i <= numProducers; ++i) {
        producerThreads.emplace_back([i, &messageQueue]() {
            // Create a producer with the given thread ID and message queue
            Producer producer(i, messageQueue);
            // Run the producer
            producer.run();
            });
    }

    // Create a consumer with the message queue and the total number of producers
    Consumer consumer(messageQueue, numProducers);

    // Create a thread to run the consumer
    std::thread consumerThread([&consumer]() {
        // Run the consumer
        consumer.run();
        });

    // Wait for all producer threads to finish
    for (auto& thread : producerThreads) {
        thread.join();
    }

    // Wait for the consumer thread to finish
    consumerThread.join();

    return 0;
}
