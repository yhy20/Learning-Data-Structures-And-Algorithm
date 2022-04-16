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

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        srand((unsigned)time(NULL));
        // return bubbleSort(head);
        // return selectSort(head);
        // return selectSort1(head);
        // return insertSort(head);
        // return mergeSort(head);
        // quickSort(head,nullptr);
        quickSort1(head, nullptr);
        return head;
    }

    //简单快速排序
    void quickSort(ListNode* left, ListNode* right) {
        if(left == right || left->next == right) {
            return;
        }
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

    //简单优化版快速排序
    void quickSort1(ListNode* left, ListNode* right) {
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
        quickSort1(left, index);
        quickSort1(index->next, right);
    }

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

    //由于链表为单向链表，仅交换值版插入排序似乎没有比较简洁的实现
    //交换实际结点版的插入排序
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

    //交换实际结点版的选择排序
    ListNode* selectSort1(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy(0, head);
        ListNode ans(0, nullptr);
        auto curr2 = &ans;
        while(dummy.next) {
            auto pos = &dummy, curr1 = dummy.next;
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

    //不分割链表，原地交换的选择排序
    ListNode* selectSort2(ListNode* head) {
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

    //自上而下归并排序，找中间结点开销较大
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