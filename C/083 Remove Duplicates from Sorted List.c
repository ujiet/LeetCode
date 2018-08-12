struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) 
        return head;
    
    struct ListNode *cur = head, *front = head->next, *temp;
    
    while (front != NULL) {
        temp = front->next;
        if (cur->val == front->val) {
            cur->next = front->next;
            free(front);
        }
        cur = cur->next;
        if (temp)    
            front = cur->next;
        else
            front = temp;
    }
    
    return head;
}
