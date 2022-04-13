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

//自低向上归并
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
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

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        int n = 0;
        for(auto curr = head; curr; curr = curr->next) ++n;
        ListNode dummy(0, head);
        for(int subLen = 1; subLen < n; subLen <<= 1) {
            auto prev = &dummy, curr = dummy.next;
            while(curr) {
                auto head1 = curr;
                for(int i = 1; i < subLen && curr->next; ++i) curr = curr->next;
                auto head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for(int i = 1; i < subLen && curr && curr->next; ++i) curr = curr->next;
                ListNode* next = nullptr;
                if(curr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                auto merged = merge(head1, head2);
                prev->next = merged;
                while(prev->next) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummy.next;
    }
};

int main() {
    Solution s;

    return 0;
}