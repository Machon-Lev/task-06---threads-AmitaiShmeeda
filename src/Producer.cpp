#include "../include/Producer.h"
#include <thread>

// Constructor for the Producer class
Producer::Producer(int id, SafeQueue<Message>& queue)
    : threadId(id), messageQueue(queue) {}

// The main execution function for the Producer thread
void Producer::run() {
    // Initialize the value with the thread's ID as a double
    double value = static_cast<double>(threadId);

    // Flag indicating if the last message has been sent
    bool isLast = false;

    // Continue sending messages until the last message is sent
    while (!isLast) {
        // Create a message with the current thread's ID, value, and false indicating it's not the last message
        Message message(threadId, value, false);

        // Push the message into the queue for the Consumer to process
        messageQueue.push(message);

        // Divide the value by 10 for the next iteration
        value /= 10.0;

        // Check if the value has reached a small threshold, indicating the last message
        if (value < 1e-6) {
            // Set the flag to indicate the last message
            isLast = true;

            // Push a message with the thread's ID, value 0.0, and true indicating the last message
            messageQueue.push(Message(threadId, 0.0, true));
        }
    }
}
