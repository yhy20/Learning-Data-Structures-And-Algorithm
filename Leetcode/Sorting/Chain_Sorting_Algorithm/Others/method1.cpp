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

//优先级队列
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        auto cmp = [](ListNode* a, ListNode* b) -> bool {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        while(head) {
            minHeap.push(head);
            head = head->next;
        }
        ListNode dummy(0, nullptr);
        auto curr = &dummy;
        while(!minHeap.empty()) {
            curr->next = minHeap.top();
            minHeap.pop();
            curr = curr->next;
        }
        curr->next = nullptr;
        return dummy.next;
    }
};

int main() {
    Solution s;

    return 0;
}