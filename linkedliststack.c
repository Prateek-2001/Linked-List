#include<stdio.h>
#include<stdlib.h>

struct Node{
        int data;
        struct Node* link;
};

int push(struct Node** head_ref, int new_data){

        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

        new_node -> data = new_data;
        new_node -> link = (*head_ref);
        (*head_ref) = new_node;

        return 1;
        }


_Bool is_empty(struct Node* top){
        if (top -> link == NULL){
                return 0;
        }
        return 1;
}

int pop(struct Node** head_ref){

        if(!is_empty((*head_ref))){
                return -1;
                }

        struct Node* head = (*head_ref);

        int popped = head -> data;

        (*head_ref) = (*head_ref) -> link;

        free(head);

        return popped;

}

void printlist(struct Node* head){

        struct Node* ptr = head;
        while(ptr){
                printf("%d -> ", ptr -> data);
                ptr = ptr -> link;
        }
        printf("NULL\n");
}

int peek(struct Node* top){
        if (!is_empty(top)){
                return -1;
        }
        return top -> data;
}

int main(){

        struct Node* head = NULL;
        struct Node* top = head;

        push(&top, 2);
        push(&top, 4);
        push(&top, 6);
        printf("%d is popped\n", pop(&top));
        printlist(top);
        printf("%d is the top most element of the stack\n", peek(top));

        return 0;
}


