#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	Node* next;
}Node;

Node* rear=NULL;
Node* front=NULL;

Node* Enqueue (Node* head,int val)
{
	Node* newnode =(Node*)malloc(sizeof(Node));
	newnode->data=val;
	newnode->next=NULL;
	if (front==NULL)
	{
		head=newnode;
		rear=head;
		front=head;
		return head;
	}
	rear->next=newnode;
	rear=rear->next;
	return head;
}

Node* Dequeue (Node* head)
{
	if (front==NULL)
		return head;
	head=head->next;
	front=head;
	return head;
}

void isEmpty(Node* head)
{
	if (front==NULL)
		printf("Empty queue");
	else
		printf("Not an empty queue");	
}

int Front(Node* head)
{
	return front->data;
}

void DisplayList(struct Node* s)
{
	 while (s!= NULL)
	 {
		 printf("%d",s->data);
		 if (s->next!= NULL)
		 printf("-> ");
		 s =s->next;
	 }
	 printf("\n");
}

int main()
{
	Node* head=NULL;
	head=Enqueue(head,10);
	head=Enqueue(head,20);
	head=Enqueue(head,30);
	head=Enqueue(head,40);
	head=Enqueue(head,50);
	DisplayList(head);	
	head=Dequeue(head);
	head=Dequeue(head);
	DisplayList(head);
	isEmpty(head);
	printf("\nThe element on front is %d",Front(head));
}
