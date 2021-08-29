#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next, *prev;
};

struct Node *head = NULL, *tail = NULL;

struct Node* newnode(int newdata){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = newdata;
    new_node -> next = NULL;
    new_node -> prev = NULL;
    return new_node;
};

void auxillarynode(){
    head = newnode(0);
    tail = newnode(0);
    head -> next = tail;
    tail -> prev = head;
}

void insertfront(int newdata){
    
    struct Node* new_node = newnode(newdata);
    struct Node* temp;
    temp = head -> next;
    head -> next = new_node;
    new_node -> prev = head;
    new_node -> next = temp;
    temp -> prev = new_node;
}

void insertrear(int newdata){
    
    struct Node* new_node = newnode(newdata);
    struct Node* temp;
    temp = tail -> prev;
    tail -> prev = new_node;
    new_node -> next = tail;
    new_node -> prev = temp;
    temp -> next = new_node;
}

void deletefront(){
    struct Node* temp;
    if(head -> next == tail)
        printf("Empty Queue \n");
    else{
        temp = head -> next;
        head -> next = temp -> next;
        temp -> next -> prev = head;
        free(temp);
    }
    return;
    
}

void deletelast(){
    struct Node* temp;
    if(tail -> prev == head)
        printf("Queue Empty\n");
    
    else{
        temp = tail -> prev;
        tail -> prev = temp -> prev;
        temp -> prev -> next =  tail;
        free(temp);
    }
    return;
    
}

int peekhead(){
    if (head -> next == tail){
        printf("Queue Empty\n");
        return -1;
    }
    else
        return head -> next -> data;
}

int peektail(){
    if ( tail -> prev == head){
        printf("Queue Empty\n");
        return -1;
        
    }
    else
        return tail -> prev -> data;
}

void printlist(){
    struct Node* temp;
    if(head -> next == tail){
        printf("Queue Empty\n");
        return;
    }
    else{
        temp = head -> next;
        while(temp != tail ){
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}
 
int main(){
    auxillarynode();
    int data, ch;
    while(1){
        printf("1. Insert at front\n2. Insert at rear\n");
        printf("3. Delete at front\n4. Delete at rear\n");
        printf("5. Display List\n6. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the data to insert:");
                scanf("%d", &data);
                insertfront(data);
                break;

            case 2:
                printf("Enter ur data to insert:");
                scanf("%d", &data);
                insertrear(data);
                break;

            case 3:
                deletefront();
                break;
                
            case 4:
                deletelast();
                break;

            case 5:
                printlist();
                break;

            case 6:
                exit(0);

            default:
                printf("Pls. enter correct option\n");
                break;
        }
    }
    return 0;
  }

