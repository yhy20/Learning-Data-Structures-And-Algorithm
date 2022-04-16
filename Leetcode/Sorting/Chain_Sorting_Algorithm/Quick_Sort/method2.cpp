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

//简单优化版快速排序
void quickSort(ListNode* left, ListNode* right) {
    if(left == right || left->next == right) {
        return;
    }
    int n = 0;
    for(auto head = left; head != right; head = head->next) ++n;
    int r = rand() % n;
    auto m = left;
    while(r--) m = m->next;
    swap(left->val, m->val);
    auto curr = left, index = left;
    while(curr->next != right) {
        if(curr->next->val <= left->val) {
            swap(curr->next->val, index->next->val);
            index = index->next;
        }
        curr = curr->next;
    }
    swap(left->val, index->val);
    quickSort(left, index);
    quickSort(index->next, right);
}

int main() {
    return 0;
}