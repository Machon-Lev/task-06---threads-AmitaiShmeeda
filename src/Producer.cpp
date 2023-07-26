#include "../include/Producer.h"
#include "../include/Message.h"
#include <iostream>
#include <cmath>
#include <vector>

Producer::Producer(long long id) : id(id) {}

void Producer::run() {
    std::vector<Message> messages = generateMessages();
    for (const auto& message : messages) {
        std::cout << message.toString() << std::endl;
        // Simulate sending the message to the consumer (you can add communication mechanism here).
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

std::vector<Message> Producer::generateMessages() {
    std::vector<Message> messages;
    double value = static_cast<double>(id);

    while (value >= 1.0) {
        messages.emplace_back(id, value, false); 
        value /= 10.0;
    }

    messages.emplace_back(id, value, true); 
    return messages;
}
