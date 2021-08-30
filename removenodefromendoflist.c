/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
   struct ListNode* current = head;
   struct ListNode* temp = head;
    struct ListNode* prev = NULL;
    
    int i =0;
    while(i!=n){
        i++;
        current = current -> next;
    }
    while(current){
        prev = temp;
        temp = temp -> next;
        current = current -> next;
    }
    if(prev)
        prev -> next = temp -> next;
    else
        head = temp -> next;
    free(temp);
    
    return head;

};
