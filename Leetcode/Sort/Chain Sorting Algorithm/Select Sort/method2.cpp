#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//仅交换值版的选择排序
ListNode* selectSort(ListNode* head) {
    if(!head || !head->next) return head;
    auto curr = head;
    while(curr->next) {
        auto pos = curr, node = curr->next;
        while(node) {
            if(node->val < pos->val) {
                pos = node;
            }
            node = node->next;
        }
        swap(curr->val, pos->val);
        curr = curr->next;
    }
    return head;
}

int main() {
    return 0;
}