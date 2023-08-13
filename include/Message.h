#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
public:
    // Default constructor
    Message();

    // Parameterized constructor
    Message(int threadId, double value, bool isLast);

    // Get the thread ID of the message
    int getThreadId() const;

    // Get the value of the message
    double getValue() const;

    // Check if the message is the last one
    bool isLast() const;

private:
    int threadId;  // Thread ID
    double value;  // Value calculated by the producer
    bool last;     // Flag indicating if this is the last message
};

#endif
