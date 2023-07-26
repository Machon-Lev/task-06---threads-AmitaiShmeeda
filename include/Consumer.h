#ifndef CONSUMER_H
#define CONSUMER_H

#pragma once
#include <atomic>
#include <vector>
#include <thread>
#include <mutex>
#include "Message.h"

class Consumer {
public:
    Consumer(int totalProducers);

    void run();
    void receiveMessage(const Message& message);

private:
    std::atomic<int> finishedProducers;
    std::vector<std::thread> producerThreads;
    std::mutex coutMutex;
    int totalProducers;
};

#endif // CONSUMER_H
