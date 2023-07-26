#ifndef MESSAGE_H
#define MESSAGE_H

#pragma once

#include <string>

class Message {
public:
    Message(long long threadId, double value, bool last);

    long long getThreadId() const;
    double getValue() const;
    bool isLast() const;

    std::string toString() const;

private:
    long long threadId;
    double value;
    bool last;
};

#endif // MESSAGE_H
