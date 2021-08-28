#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* link;
};

struct Queue {
	struct Node *front, *rear;
};

struct Node* newnode(int newdata){
	struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
	temp -> data =newdata;
	temp -> link = NULL;
	return temp;
}

struct Queue* createQueue()
{
	struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
	q -> front = q -> rear = NULL;
	return q;
}

void enqueue(struct Queue* q, int newdata){

	struct Node* temp = newnode(newdata);
	if (q -> rear == NULL){
		q -> front = q -> rear = temp;
		return;
	}

	q -> rear -> link = temp;
	q -> rear = temp;
}

void dequeue(struct Queue* q){

	if (q -> front == NULL)
		return;

	struct Node* temp = q -> front;

	q -> front = q -> front -> link;

	if (q -> front == NULL)
		q -> rear = NULL;
	
	free(temp);
}

int peek(struct Queue* q){
	if(q -> rear == NULL)
		return -1;
	return q -> rear -> data;
}

int main(){
	
	struct Queue* q = createQueue();
	enqueue(q, 10);
	enqueue(q, 20);
	dequeue(q);
	dequeue(q);	
	enqueue(q, 40);
	enqueue(q, 30);
	enqueue(q, 10);
	dequeue(q);
	printf("Queue Front : %d \n", q -> front -> data);
	printf("Queue Rear: %d \n", q -> front -> data);

	return 0;
}
