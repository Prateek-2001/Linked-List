/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){ 
    if(head == NULL)
        return head;
    if(head->next == NULL)
        return head;
    struct ListNode* tmp = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return tmp;
};

bool isPalindrome(struct ListNode* head){
    struct ListNode *iter = head, *reversedhalflist;
    int i = 0;
    bool flag = true;
    int count = 0;
    while(iter != NULL){
        count++;
        iter = iter -> next;
    }
    
    iter = head;
    
    for(int j = 0; j < count/2; j++){
        iter = iter -> next;
    }
    if (count%2 == 0){
        reversedhalflist = reverseList(iter);
    }
    else if(iter -> next != NULL){
        reversedhalflist = reverseList(iter -> next);
    }
    
    iter = head;
    
    if(count == 1)
        return true;
    
    else if(reversedhalflist == NULL){
        return false;
    }
    while(iter != NULL && reversedhalflist != NULL){
        
        if (iter -> val != reversedhalflist -> val){
            flag = false;
            break;
    }
        
        iter = iter -> next;
        reversedhalflist =  reversedhalflist -> next;
    }
    
    return flag;
    
    }

