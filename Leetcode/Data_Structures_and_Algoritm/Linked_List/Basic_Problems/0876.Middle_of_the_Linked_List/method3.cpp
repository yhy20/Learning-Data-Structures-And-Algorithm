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

//遍历区间[left, right]，区间[left, right] 左边的结点
class Solution {
public:
    ListNode* middleNode(ListNode* left, ListNode* right) {
        auto fast = left, slow = left;
        while(fast != right && fast->next != right) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

//遍历区间[left, right]，区间[left, right] 右边的结点
class Solution {
public:
    ListNode* middleNode(ListNode* left, ListNode* right) {
        auto fast = left, slow = left;
        while(fast != right && fast->next != right) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->next;
    }
};

int main() {
    Solution s;

    return 0;
}