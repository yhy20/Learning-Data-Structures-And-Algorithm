#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//由于链表为单向链表，仅交换值版插入排序似乎没有比较简洁的实现
//交换实际结点版的插入排序
ListNode* insertSort(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode dummy(0, nullptr);
    while(head) {
        auto curr = &dummy, pos = head;
        while(curr->next) {
            if(curr->next->val >= pos->val) break;
            curr = curr->next;
        }
        head = head->next;
        pos->next = curr->next;
        curr->next = pos;
    }
    return dummy.next;
}

int main() {
    return 0;
}