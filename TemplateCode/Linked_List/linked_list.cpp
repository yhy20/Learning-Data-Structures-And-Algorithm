#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode {
public:
    T val;
    LinkedListNode<T>* next;
    LinkedListNode() : next(nullptr) {}
    LinkedListNode(const T& x) : val(x), next(nullptr) {}
    LinkedListNode(const T& x, LinkedListNode<T>* next) : val(x), next(next) {}
};

template <typename T>
class LinkedList {
private:
    size_t size;
    LinkedListNode<T> dummy;
    LinkedListNode<T>*head, *tail;

public:
    LinkedList() {
        size = 0;
        head = &dummy;
        tail = head;
    }
    ~LinkedList() {
        clear();
    }

    T front() {
        return head->next->val;
    }

    T back() {
        return tail->val;
    }

    T operator[](size_t index) {
        return get(index);
    }

    T get(size_t index) {
        assert(index >= 0 && index < size);
        size_t t = 0;
        LinkedListNode<T>* curr = head;
        while(t++ <= index) {
            curr = curr->next;
        }
        return curr->val;
    }

    void push_front(const T& val) {
        ++size;
        head->next = new LinkedListNode<T>(val, head->next);
        if(tail == head) tail = head->next;
    }

    void push_back(const T& val) {
        ++size;
        tail->next = new LinkedListNode<T>(val, tail->next);
        tail = tail->next;
    }

    void insert(size_t index, const T& val) {
        assert(index >= 0 && index <= size);
        if(index == size) {
            push_back(val);
            return;
        }
        ++size;
        size_t t = 0;
        LinkedListNode<T>* curr = head;
        while(t++ < index) {
            curr = curr->next;
        }
        curr->next = new LinkedListNode<T>(val, curr->next);
    }

    void erase(size_t index) {
        assert(index >= 0 && index < size);
        --size;
        size_t t = 0;
        LinkedListNode<T>* curr = head;
        while(t++ < index) {
            curr = curr->next;
        }
        if(curr->next == tail) tail = curr;
        LinkedListNode<T>* next = curr->next->next;
        delete curr->next;
        curr->next = next;
    }

    void clear() {
        LinkedListNode<T>* curr = head->next;
        head->next = nullptr;
        while(curr) {
            auto next = curr->next;
            delete curr;
            curr = next;
        }
        size = 0;
        tail = head;
    }
};