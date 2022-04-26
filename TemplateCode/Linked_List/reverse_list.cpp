struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//迭代反转
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next) return head;
    auto prev = head, curr = head->next;
    head->next = nullptr;
    while(curr) {
        auto next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//递归实现反转链表
//注意return要返回新的头节点
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next) return head;
    auto ans = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return ans;
}
