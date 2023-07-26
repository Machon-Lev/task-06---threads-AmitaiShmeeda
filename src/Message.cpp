#include "../include/Message.h"

Message::Message(long long threadId, double value, bool last)
    : threadId(threadId), value(value), last(last) {}

long long Message::getThreadId() const {
    return threadId;
}

double Message::getValue() const {
    return value;
}

bool Message::isLast() const {
    return last;
}

std::string Message::toString() const {
    if (last) {
        return std::to_string(threadId) + " finished";
    }
    else {
        return std::to_string(threadId) + " sent: " + std::to_string(value);
    }
}
