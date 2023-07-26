#include <iostream>
#include <vector>
#include <thread>
#include "../include/Producer.h"
#include "../include/Consumer.h"
#include "../include/Message.h"

int main() {
    int totalProducers = 2; // Total number of producers
    Consumer consumer(totalProducers);
    std::thread consumerThread(&Consumer::run, &consumer);

    std::vector<std::thread> producerThreads;
    for (int i = 0; i < totalProducers; ++i) { // Create producers only once
        Producer producer(i);
        producerThreads.emplace_back(&Producer::run, &producer);
    }

    for (auto& thread : producerThreads) {
        thread.join();
    }

    consumerThread.join();
    return 0;
}
