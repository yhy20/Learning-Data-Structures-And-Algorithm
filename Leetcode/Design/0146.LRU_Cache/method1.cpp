#include<bits/stdc++.h>
using namespace std;

struct DLLNode {
    int key, val;
    DLLNode *prev, *next;
    DLLNode(): key(0), val(0), prev(nullptr), next(nullptr) {}
    DLLNode(int k, int v,  DLLNode* p = nullptr, DLLNode* n = nullptr): key(k), val(v), prev(p), next(n) {}
};

class LRUCache {
public:
    LRUCache(size_t c) {
        size = 0;
        capacity = c;
        head = tail = &dummy;
    }
    int get(int key) {
        auto itr = map.find(key);
        if(itr == map.end()) return -1;
        change_priority(itr->second);
        return itr->second->val;
    }
    void put(int key, int val) {
        auto itr = map.find(key);
        if(itr != map.end()){
            itr->second->val = val;
            change_priority(itr->second);
            return;
        }
        push_front(key, val);
        if(size > capacity) pop_back();
    }
    void push_front(int key, int val){
        if(size == 0){
            head->next = new DLLNode(key, val, head);
            tail = tail->next;
        }else{
            head->next = new DLLNode(key, val, head, head->next);
            head->next->next->prev = head->next;       
        }
        map[key] = head->next;
        ++size;
    }
    void pop_back(){
        if(size == 0) return;
        map.erase(tail->key);
        tail = tail->prev;
        //delete tail->next;
        tail->next = nullptr;
        --size;
    }
    void change_priority(DLLNode* curr){
        if(curr == head->next) return;    
        if(curr == tail){
            tail = tail->prev;
            tail->next = nullptr;
        }else{
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
        }
        curr->next = head->next;
        head->next->prev = curr;
        head->next = curr;
        curr->prev = head;
    }

protected:
    size_t size, capacity;
    DLLNode dummy;
    DLLNode* head, *tail;
    unordered_map<int, DLLNode*> map;
};
