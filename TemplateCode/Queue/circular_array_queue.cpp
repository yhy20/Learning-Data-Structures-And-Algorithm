#include <bits/stdc++.h>
using namespace std;

template <typename T>
class ArrayQueue {
public:
    ArrayQueue(size_t c) : queueSize(0), head(0), tail(0) {
        assert(c >= 0);
        capacity = c;
        pool = new T[capacity];
    }
    ~ArrayQueue() {
        delete[] pool;
    }
    T front() const {
        assert(queueSize > 0);
        return pool[head];
    }
    T back() const {
        assert(queueSize > 0);
        return pool[(tail + capacity - 1) % capacity];
    }
    size_t size() const {
        return queueSize;
    }
    bool empty() const {
        return queueSize == 0;
    }
    bool full() const {
        return queueSize == capacity;
    }
    bool push(const T&);
    T pop();

protected:
    T* pool;
    size_t capacity, queueSize;
    size_t head, tail;
};

template <typename T>
bool ArrayQueue<T>::push(const T& val) {
    if(queueSize == capacity) return false;
    pool[tail] = val;
    tail = (tail + 1) % capacity;
    ++queueSize;
    return true;
}

template <typename T>
T ArrayQueue<T>::pop() {
    assert(queueSize > 0);
    T tmp = pool[head];
    head = (head + 1) % capacity;
    --queueSize;
    return tmp;
}
