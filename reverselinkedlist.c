/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* successor = NULL;

struct ListNode* reverseN(struct ListNode* head, int n) {
    if (n == 1) {
        successor = head->next;
        return head;
    }
    
    struct ListNode* last = reverseN(head->next, n -1);
    head->next->next = head;
    head->next = successor;
    
    return last;    
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (left == 1)
        return reverseN(head, right);
    
    head->next = reverseBetween(head->next, left-1, right-1);
    return head;
}
