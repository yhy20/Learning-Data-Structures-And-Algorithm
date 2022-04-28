#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size());
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef double db;
const ll mod = 1e9 + 7;

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
    size_t size() {
        return listSize;
    }
    T operator[](size_t index) const {
        return get(index);
    }
    T get(size_t index) const;
    void push_front(const T& val);
    void push_back(const T& val);
    void insert(size_t index, const T& val);
    void erase(size_t index);
    void output(ostream& out) const;
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
void LinkedList<T>::erase(size_t index) {
    assert(index >= 0 && index < listSize);
    --listSize;
    size_t t = 0;
    LLNode<T>* curr = head;
    while(t++ < index) {
        curr = curr->next;
    }
    if(curr->next == tail) tail = curr;
    LLNode<T>* next = curr->next->next;
    delete curr->next;
    curr->next = next;
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
class MyLinkedList {
public:
    LinkedList<int> list;
    MyLinkedList() {}

    int get(int index) {
        if(index < 0 || index >= list.size()) return -1;
        return list.get(index);
    }

    void addAtHead(int val) {
        list.push_front(val);
    }

    void addAtTail(int val) {
        list.push_back(val);
    }

    void addAtIndex(int index, int val) {
        if(index < 0) {
            list.push_front(val);
            return;
        }
        if(index > list.size()) return;
        list.insert(index, val);
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= list.size()) return;
        list.erase(index);
    }
};

int main() {
    MyLinkedList s;

    return 0;
}