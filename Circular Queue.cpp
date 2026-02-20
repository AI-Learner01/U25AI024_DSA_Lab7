#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	Node* next;
}Node;

Node* front=NULL;
Node* rear=NULL;

Node* Enqueue (Node* head,int val)
{
	Node* newnode =(Node*)malloc(sizeof(Node));
	newnode->data=val;
	newnode->next=NULL;
	if (head==NULL)
	{
		head=newnode;
		newnode->next=head;
		front=head;
		rear=head;
		return head;
	}
	rear->next=newnode;
	rear=newnode;
	newnode->next=front;
	return head;
}

Node* Dequeue(Node* head)
{
	if (head==NULL)
		return head;
	Node* temp=head;
	head=head->next;
	front=head;
	rear->next=head;
	free(temp);
	return head;
}

int Front(Node* head)
{
	if (head==NULL)
		return -1;
	return front->data;
}

int Rear (Node* head)
{
	if (head==NULL)
		return -1;
	return rear->data;
}

Node* DisplayList(Node* head)
{
	if (head==NULL)
		return head;
	Node* temp=head;
	do 
	{
        printf("%d -> ",temp->data);
        temp =temp->next;
    }
    while (temp != head);
	printf("repeat");
    printf("\n");
}

int main()
{
	Node* head=NULL;
	head=Enqueue(head,14);
	DisplayList(head);
	head=Enqueue(head,22);
	DisplayList(head);
	head=Enqueue(head,-6);
	DisplayList(head);
	head=Dequeue(head);
	DisplayList(head);
	head=Dequeue(head);
	DisplayList(head);
	head=Enqueue(head,9);
	DisplayList(head);
	printf("\nthe front item from the queue is %d",Front(head));
	printf("\n the last item from the queue is %d",Rear(head));
}
