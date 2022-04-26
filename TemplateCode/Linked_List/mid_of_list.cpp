struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//遍历区间[head, nullptr)，找打区间[head, end]右边的结点
ListNode* middleNode(ListNode* head) {
    auto fast = head, slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//遍历区间[head, nullptr)，找打区间[head, end]左边的结点
ListNode* middleNode(ListNode* head) {
    ListNode dummy(0, head);
    auto fast = &dummy, slow = &dummy;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//遍历区间[left, right]，区间[left, right] 左边的结点
ListNode* middleNode(ListNode* left, ListNode* right) {
    auto fast = left, slow = left;
    while(fast != right && fast->next != right) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//遍历区间[left, right]，区间[left, right] 右边的结点
ListNode* middleNode(ListNode* left, ListNode* right) {
    auto fast = left, slow = left;
    while(fast != right && fast->next != right) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->next;
}