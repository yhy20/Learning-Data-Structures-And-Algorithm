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

//排序单向链表
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // return bubbleSort(head);
        // return insertSort(head);
        // return selectSort(head);
        // return selectSort1(head);
        return mergeSort(head);
    }

    //仅交换值的bubble sort
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

    //交换实际结点版插入排序
    ListNode* insertSort(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy(0, nullptr);
        while(head) {
            auto curr = &dummy, pos = head;
            while(curr->next) {
                if(curr->next->val >= pos->val) break;
                curr = curr->next;
            }
            head = head->next;
            pos->next = curr->next;
            curr->next = pos;
        }
        return dummy.next;
    }

    //交换实际结点版的选择排序(双链表版)
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

    //交换实际结点版选择(就地交换版)
    ListNode* selectSort1(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* pos = dummy;
        ListNode* curr = head;
        ListNode* index = nullptr;
        int length = 0;
        while(curr) {
            ++length;
            curr = curr->next;
        }
        for(int i = 1; i < length; ++i) {
            int m = INT_MAX;
            for(curr = pos; curr->next != nullptr; curr = curr->next) {
                if(curr->next->val < m) {
                    m = curr->next->val;
                    index = curr;
                }
            }
            curr = index->next;
            index->next = curr->next;
            curr->next = pos->next;
            pos->next = curr;
            pos = pos->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }

    //仅交换值版的选择排序
    ListNode* selectSort2(ListNode* head) {
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

    //自上而下归并排序
    ListNode* mergeSort(ListNode* head) {
        if(!head || !head->next) return head;
        return merge(head, nullptr);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if(left == right)
            return left;
        if(left->next == right) {
            left->next = nullptr;
            return left;
        }
        ListNode *fast = left, *slow = left;
        while(fast != right && fast->next != right) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head1 = merge(left, slow);
        ListNode* head2 = merge(slow, right);
        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* curr = dummy;
        while(head1 && head2) {
            if(head1->val <= head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        curr->next = head1 ? head1 : head2;
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};

int main() {
    Solution s;

    return 0;
}