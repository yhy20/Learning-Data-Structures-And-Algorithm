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

//直接sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> a;
        while(head) {
            a.emplace_back(head);
            head = head->next;
        }
        sort(a.begin(), a.end(), [](ListNode* l, ListNode* r) -> bool {
            return l->val < r->val;
        });
        ListNode dummy(0, nullptr);
        auto curr = &dummy;
        for(auto node : a) {
            curr->next = node;
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