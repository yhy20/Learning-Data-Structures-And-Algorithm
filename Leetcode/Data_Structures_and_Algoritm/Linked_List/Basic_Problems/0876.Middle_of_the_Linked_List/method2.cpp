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

//链表中间左结点
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode dummy(0, head);
        auto fast = &dummy, slow = &dummy;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    Solution s;

    return 0;
}