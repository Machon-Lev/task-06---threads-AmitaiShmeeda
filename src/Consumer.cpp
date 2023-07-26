#include "../include/Consumer.h"
#include "../include/Producer.h"
#include "../include/Message.h"
#include <iostream>
#include <chrono>


Consumer::Consumer(int totalProducers) : finishedProducers(0), totalProducers(totalProducers) {}

void Consumer::run() {
    while (finishedProducers.load() < 2) {
        // Simulate some work for the consumer (you can remove this in the actual implementation).
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Consumer::receiveMessage(const Message& message) {
    std::lock_guard<std::mutex> lock(coutMutex);
    if (message.isLast()) {
        finishedProducers.fetch_add(1);
        if (finishedProducers.load() == totalProducers) {
            std::cout << "Consumer finished" << std::endl;
        }
    }
    else {
        std::cout << message.getThreadId() << " sent: " << message.getValue() << std::endl;
    }
}
