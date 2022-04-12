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

//新开辟一条链表ans进行选择排序，简化操作
//选择时注意选择最小节点的前一个结点
//使用哨兵结点技巧规避头节点的特殊操作

//交换实际结点版的选择排序
ListNode* selectSort(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode dummy(0, head);
    ListNode ans(0, nullptr);
    ListNode* curr2 = &ans;
    while(dummy.next) {
        ListNode* pos = &dummy;
        ListNode* curr1 = dummy.next;
        while(curr1->next) {
            if(curr1->next->val < pos->next->val) {
                pos = curr1;
            }
            curr1 = curr1->next;
        }
        curr2->next = pos->next;
        curr2 = curr2->next;
        pos->next = curr2->next;
        curr2->next = nullptr;
    }
    return ans.next;
}

int main() {
    return 0;
}