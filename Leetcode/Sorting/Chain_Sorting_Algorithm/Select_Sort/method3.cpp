#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//不分割链表，原地交换的选择排序
ListNode* selectSort2(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* dummy = new ListNode(0, head);
    ListNode* pos = dummy;
    ListNode* curr = head;
    ListNode* index = nullptr;
    int length = 0;
    while(curr) {
        ++length;
        curr = curr->next;
    }
    for(int i = 1; i < length; ++i) {
        int m = INT_MAX;
        for(curr = pos; curr->next != nullptr; curr = curr->next) {
            if(curr->next->val < m) {
                m = curr->next->val;
                index = curr;
            }
        }
        curr = index->next;
        index->next = curr->next;
        curr->next = pos->next;
        pos->next = curr;
        pos = pos->next;
    }
    head = dummy->next;
    delete dummy;
    return head;
}

int main() {
    return 0;
}