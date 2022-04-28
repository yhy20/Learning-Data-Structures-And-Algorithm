#include <bits/stdc++.h>
using namespace std;

template <class T>
class DLLNode {
public:
    T val;
    DLLNode<T>*prev, *next;
    DLLNode() : prev(nullptr), next(nullptr) {}
    DLLNode(const T& x, DLLNode<T>* p = nullptr, DLLNode<T>* n = nullptr) {
        val = x;
        prev = p;
        next = n;
    }
};

template <class T>
class DoublyLinkedList {
public:
    DoublyLinkedList() {
        listSize = 0;
        head = tail = &dummy;
    }
    ~DoublyLinkedList() {
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
    T get(size_t index) const;
    void push_front(const T&);
    void push_back(const T&);
    T pop_front();
    T pop_back();
    void insert(size_t, const T&);
    T erase(size_t);
    void output(ostream&) const;
    void clear();

protected:
    size_t listSize;
    DLLNode<T> dummy;
    DLLNode<T>*head, *tail;
};

template <typename T>
T DoublyLinkedList<T>::get(size_t index) const {
    assert(index >= 0 && index < listSize);
    size_t t = 0;
    DLLNode<T>* curr = head;
    while(t++ <= index) {
        curr = curr->next;
    }
    return curr->val;
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& val) {
    if(listSize == 0) {
        push_back(val);
        return;
    }
    ++listSize;
    head->next = new DLLNode<T>(val, head, head->next);
    head->next->next->prev = head->next;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& val) {
    ++listSize;
    tail->next = new DLLNode<T>(val, tail, nullptr);
    tail = tail->next;
}

template <typename T>
T DoublyLinkedList<T>::pop_front() {
    assert(listSize > 0);
    --listSize;
    auto toDelete = head->next;
    if(head->next == tail) {
        head->next = nullptr;
        tail = head;
    } else {
        head->next = toDelete->next;
        toDelete->next->prev = head;
    }
    T tmp = toDelete->val;
    delete toDelete;
    return tmp;
}

template <typename T>
T DoublyLinkedList<T>::pop_back() {
    assert(listSize > 0);
    --listSize;
    T tmp = tail->val;
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
    return tmp;
}

template <typename T>
void DoublyLinkedList<T>::insert(size_t index, const T& val) {
    assert(index >= 0 && index <= listSize);
    if(index == listSize) {
        push_back(val);
        return;
    }
    ++listSize;
    size_t t = 0;
    DLLNode<T>* curr = head;
    while(t++ < index) {
        curr = curr->next;
    }
    curr->next = new DLLNode<T>(val, curr, curr->next);
    curr->next->next->prev = curr->next;
}

template <typename T>
T DoublyLinkedList<T>::erase(size_t index) {
    assert(index >= 0 && index < listSize);
    if(index == listSize - 1) {
        return pop_back();
    }
    --listSize;
    size_t t = 0;
    DLLNode<T>* curr = head;
    while(t++ < index) {
        curr = curr->next;
    }
    auto toDelete = curr->next;
    curr->next = toDelete->next;
    toDelete->next->prev = curr;
    T tmp = toDelete->val;
    delete toDelete;
    return tmp;
}
template <typename T>
void DoublyLinkedList<T>::output(ostream& out) const {
    for(auto curr = head->next; curr; curr = curr->next) {
        out << curr->val << " ";
    }
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    DLLNode<T>* curr = head->next;
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
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& list) {
    list.output(out);
    return out;
}

template <typename T>
class LinkedDequeue {
public:
    LinkedDequeue() {}
    ~LinkedDequeue() {}
    void push_front(const T& val) {
        pool.push_front(val);
    }
    void push_back(const T& val) {
        pool.push_back(val);
    }
    T pop_front() {
        assert(pool.size() > 0);
        return pool.pop_front();
    }
    T pop_back() {
        assert(pool.size() > 0);
        return pool.pop_back();
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
    DoublyLinkedList<T> pool;
};