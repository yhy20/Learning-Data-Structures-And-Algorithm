#include <bits/stdc++.h>
using namespace std;

int main() {
    Solution s;

    return 0;
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//直接归并排序
class Solution {
public:
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if(l == r) {
            return lists[l];
        }
        int mid = l + ((r - l) >> 1);
        auto head1 = merge(lists, l, mid);
        auto head2 = merge(lists, mid + 1, r);
        ListNode head;
        auto curr = &head;
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
        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
};

//优先级队列多路归并
class Solution {
public:
    struct Status {
        int val;
        ListNode* ptr;
        Status(int val, ListNode* ptr) : val(val), ptr(ptr) {}
        bool operator>(const Status& r) const {
            return val > r.val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Status, vector<Status>, greater<Status>> q;
        for(auto node : lists) {
            if(node) q.emplace(node->val, node);
        }

        ListNode dummy, *curr = &dummy;
        while(!q.empty()) {
            auto [val, ptr] = q.top();
            q.pop();
            curr->next = ptr;
            curr = curr->next;
            if(ptr->next) q.emplace(ptr->next->val, ptr->next);
        }
        return dummy.next;
    }
};