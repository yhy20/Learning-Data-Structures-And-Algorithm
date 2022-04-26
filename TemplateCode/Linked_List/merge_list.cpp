struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//双指针归并
ListNode* mergeList(ListNode* head1, ListNode* head2) {
    if(!head1 || !head2) return head1 ? head1 : head2;
    ListNode dummy, *curr = &dummy;
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
    return dummy.next;
}

//递归归并
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(!list1) {
        return list2;
    } else if(!list2) {
        return list1;
    } else if(list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}