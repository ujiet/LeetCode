/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool check(struct ListNode *end, struct ListNode **frontptr) {
    if (end == NULL) return true;
    
    bool isPalin = check(end->next, frontptr) && ((*frontptr)->val == end->val);
    *frontptr = (*frontptr)->next;
    return isPalin;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode *front = head;
    return check(head, &front);
}
