#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LLNode {
public:
    T val;
    LLNode<T>* next;
    LLNode() : next(nullptr) {}
    LLNode(const T& x, LLNode<T>* n = nullptr) : val(x), next(n) {}
};

template <typename T>
class LinkedList {
public:
    LinkedList() {
        listSize = 0;
        head = tail = &dummy;
    }
    ~LinkedList() {
        clear();
    }
    T front() const {
        return head->next->val;
    }
    T back() const {
        return tail->val;
    }
    bool empty() const {
        return listSize == 0;
    }
    size_t size() const {
        return listSize;
    }
    T operator[](size_t index) const {
        return get(index);
    }
    T get(size_t) const;
    void push_front(const T&);
    T pop_front();
    void push_back(const T&);
    void insert(size_t, const T&);
    T erase(size_t);
    void output(ostream&) const;
    void clear();

protected:
    size_t listSize;
    LLNode<T> dummy;
    LLNode<T>*head, *tail;
};

template <typename T>
T LinkedList<T>::get(size_t index) const {
    assert(index >= 0 && index < listSize);
    size_t t = 0;
    LLNode<T>* curr = head;
    while(t++ <= index) {
        curr = curr->next;
    }
    return curr->val;
}

template <typename T>
void LinkedList<T>::push_front(const T& val) {
    ++listSize;
    head->next = new LLNode<T>(val, head->next);
    if(tail == head) tail = head->next;
}

template <typename T>
T LinkedList<T>::pop_front() {
    assert(listSize > 0);
    --listSize;
    auto toDelete = head->next;
    if(toDelete == tail) tail = head;
    head->next = toDelete->next;
    T tmp = toDelete->val;
    delete toDelete;
    return tmp;
}

template <typename T>
void LinkedList<T>::push_back(const T& val) {
    ++listSize;
    tail->next = new LLNode<T>(val);
    tail = tail->next;
}

template <typename T>
void LinkedList<T>::insert(size_t index, const T& val) {
    assert(index >= 0 && index <= listSize);
    if(index == listSize) {
        push_back(val);
        return;
    }
    ++listSize;
    size_t t = 0;
    LLNode<T>* curr = head;
    while(t++ < index) {
        curr = curr->next;
    }
    curr->next = new LLNode<T>(val, curr->next);
}

template <typename T>
T LinkedList<T>::erase(size_t index) {
    assert(index >= 0 && index < listSize);
    --listSize;
    size_t t = 0;
    LLNode<T>* curr = head;
    while(t++ < index) {
        curr = curr->next;
    }
    if(curr->next == tail) tail = curr;
    auto toDelete = curr->next;
    curr->next = toDelete->next;
    T tmp = toDelete->val;
    delete toDelete;
    return tmp;
}

template <typename T>
void LinkedList<T>::output(ostream& out) const {
    for(auto curr = head->next; curr; curr = curr->next) {
        out << curr->val << " ";
    }
}

template <typename T>
void LinkedList<T>::clear() {
    LLNode<T>* curr = head->next;
    head->next = nullptr;
    while(curr) {
        auto next = curr->next;
        delete curr;
        curr = next;
    }
    listSize = 0;
    tail = head;
}

template <typename T>
ostream& operator<<(ostream& out, const LinkedList<T>& list) {
    list.output(out);
    return out;
}

template <typename T>
class LinkedQueue {
public:
    LinkedQueue() {}
    ~LinkedQueue() {}
    void push(const T& val) {
        pool.push_back(val);
    }
    T pop() {
        assert(pool.size() > 0);
        return pool.pop_front();
    }
    T front() const {
        assert(pool.size() > 0);
        return pool.front();
    }
    T back() const {
        assert(pool.size() > 0);
        return pool.back();
    }
    size_t size() const {
        return pool.size();
    }
    bool empty() const {
        return pool.empty();
    }

protected:
    LinkedList<T> pool;
};