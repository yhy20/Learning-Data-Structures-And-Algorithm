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

//自上而下归并排序，找中间结点开销较大
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head) {
        if(!head || !head->next) return head;
        return merge(head, nullptr);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if(left->next == right) {
            left->next = nullptr;
            return left;
        }
        auto fast = left, slow = left;
        while(fast != right && fast->next != right) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto l1 = merge(left, slow);
        auto l2 = merge(slow, right);
        ListNode dummy(0, nullptr);
        auto curr = &dummy;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

int main() {
    Solution s;

    return 0;
}