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
    size_t size() {
        return listSize;
    }
    T operator[](size_t index) const {
        return get(index);
    }
    T get(size_t index) const;
    void push_front(const T& val);
    void push_back(const T& val);
    void pop_front();
    void pop_back();
    void insert(size_t index, const T& val);
    void erase(size_t index);
    void output(ostream& out) const;
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
void DoublyLinkedList<T>::pop_front() {
    if(listSize == 0) return;
    --listSize;
    if(head->next == tail) {
        delete head->next;
        head->next = nullptr;
        tail = head;
        return;
    }
    auto toDelete = head->next;
    head->next = toDelete->next;
    toDelete->next->prev = head;
    delete toDelete;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
    if(listSize == 0) return;
    --listSize;
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
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
void DoublyLinkedList<T>::erase(size_t index) {
    assert(index >= 0 && index < listSize);
    if(index == listSize - 1) {
        pop_back();
        return;
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
    delete toDelete;
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