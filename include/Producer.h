#ifndef PRODUCER_H
#define PRODUCER_H

#pragma once
#include <vector>
#include <thread>
#include "Message.h"


class Producer {
public:
    Producer(long long id);

    void run();

private:
    long long id;
    std::vector<Message> generateMessages();
};

#endif // PRODUCER_H
