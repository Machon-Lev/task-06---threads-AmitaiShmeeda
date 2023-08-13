#ifndef SAFEQUEUE1
#define SAFEQUEUE1

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class SafeQueue {
public:
    SafeQueue() = default;

    // Pushes a value into the queue
    void push(const T& value);

    // Tries to pop a value from the queue
    bool tryPop(T& value);

    // Checks if the queue is empty
    bool empty() const;

private:
    std::queue<T> queue;
    mutable std::mutex mutex;
    std::condition_variable condVar;
};

#endif


#ifndef SAFEQUEUE2
#define SAFEQUEUE2

template <typename T>
void SafeQueue<T>::push(const T& value) {
    std::lock_guard<std::mutex> lock(mutex);
    queue.push(value);
    condVar.notify_one();
}

template <typename T>
bool SafeQueue<T>::tryPop(T& value) {
    std::lock_guard<std::mutex> lock(mutex);
    if (queue.empty()) {
        return false;
    }
    value = queue.front();
    queue.pop();
    return true;
}

template <typename T>
bool SafeQueue<T>::empty() const {
    std::lock_guard<std::mutex> lock(mutex);
    return queue.empty();
}

#endif
