#include "../include/Message.h"

// Default constructor: Initializes a message with default values
Message::Message()
    : threadId(0), value(0.0), last(false) {}

// Parameterized constructor: Initializes a message with specified values
Message::Message(int threadId, double value, bool isLast)
    : threadId(threadId), value(value), last(isLast) {}

// Get the thread ID of the message
int Message::getThreadId() const {
    return threadId;
}

// Get the value of the message
double Message::getValue() const {
    return value;
}

// Check if the message is the last one
bool Message::isLast() const {
    return last;
}
