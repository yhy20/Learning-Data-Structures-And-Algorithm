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

//冒泡排序相比选择，插入排序，swap次数太多，不太值得写交换结点版本的排序
//仅交换值版的冒泡排序
ListNode* bubbleSort(ListNode* head) {
    if(!head || !head->next) return head;
    int n = 0;
    for(auto curr = head; curr; curr = curr->next) ++n;
    for(int i = n - 1; i >= 1; --i) {
        bool flag = true;
        auto curr = head;
        for(int j = 0; j < i; ++j) {
            if(curr->val > curr->next->val) {
                swap(curr->val, curr->next->val);
                flag = false;
            }
            curr = curr->next;
        }
        if(flag) break;
    }
    return head;
}

int main() {
    return 0;
}