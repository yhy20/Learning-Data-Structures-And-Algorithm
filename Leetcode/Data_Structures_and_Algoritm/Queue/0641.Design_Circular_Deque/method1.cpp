#include <bits/stdc++.h>
using namespace std;

template <typename T>
class ArrayDequeue {
public:
    ArrayDequeue(int c) : dequeueSize(0), head(0), tail(0) {
        assert(c >= 0);
        capacity = c;
        pool = new T[capacity];
    }
    ~ArrayDequeue() {
        delete[] pool;
    }
    T front() const {
        assert(dequeueSize > 0);
        return pool[head];
    }
    T back() const {
        assert(dequeueSize > 0);
        return pool[(tail + capacity - 1) % capacity];
    }
    bool empty() const {
        return dequeueSize == 0;
    }
    bool full() const {
        return dequeueSize == capacity;
    }
    bool push_front(const T&);
    bool push_back(const T&);
    T pop_front();
    T pop_back();

protected:
    T* pool;
    size_t head, tail;
    size_t capacity, dequeueSize;
};

template <typename T>
bool ArrayDequeue<T>::push_front(const T& val) {
    if(dequeueSize == capacity) return false;
    head = (head - 1 + capacity) % capacity;
    pool[head] = val;
    ++dequeueSize;
    return true;
}

template <typename T>
bool ArrayDequeue<T>::push_back(const T& val) {
    if(dequeueSize == capacity) return false;
    pool[tail] = val;
    tail = (tail + 1) % capacity;
    ++dequeueSize;
    return true;
}

template <typename T>
T ArrayDequeue<T>::pop_front() {
    assert(dequeueSize > 0);
    T tmp = pool[head];
    head = (head + 1) % capacity;
    --dequeueSize;
    return tmp;
}

template <typename T>
T ArrayDequeue<T>::pop_back() {
    assert(dequeueSize > 0);
    tail = (tail - 1 + capacity) % capacity;
    T tmp = pool[tail];
    --dequeueSize;
    return tmp;
}

class MyCircularDeque {
public:
    ArrayDequeue<int> q;
    MyCircularDeque(int c) : q(c) {}

    bool insertFront(int val) {
        return q.push_front(val);
    }

    bool insertLast(int val) {
        return q.push_back(val);
    }

    bool deleteFront() {
        if(q.empty()) return false;
        q.pop_front();
        return true;
    }

    bool deleteLast() {
        if(q.empty()) return false;
        q.pop_back();
        return true;
    }

    int getFront() {
        if(q.empty()) return -1;
        return q.front();
    }

    int getRear() {
        if(q.empty()) return -1;
        return q.back();
    }

    bool isEmpty() {
        return q.empty();
    }

    bool isFull() {
        return q.full();
    }
};
