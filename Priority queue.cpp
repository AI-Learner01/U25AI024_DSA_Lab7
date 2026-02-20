#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	int priority;
	Node* next;
}Node;

Node* Push(Node* head,int val,int py)
{
	Node* newnode =(Node*)malloc(sizeof(Node));
	newnode->data=val;
	newnode->priority=py;
	newnode->next=NULL;
	if (head==NULL)
	{
		head=newnode;
		return head;
	}
	Node* temp =head;
	if (newnode->priority<head->priority)
	{
		newnode->next=head;
		head=newnode;
		return head;
	}
	Node* fw=head->next;
	Node* bw=head;
	while (fw!=NULL)
	{
		if (newnode->priority>bw->priority && newnode->priority<fw->priority)
		{
			bw->next=newnode;
			newnode->next=fw;
			return head;
		}
		fw=fw->next;
		bw=bw->next;
	}
	bw->next=newnode;
	return head;		
}

Node* Pop(Node* head)
{
	if (head== NULL)
		return head;
	Node* temp=head;
	head=head->next;
	free(temp);
	return head;
}

int Peek(Node* head)
{
	if (head==NULL)
		return -1;
	return head->data;
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
	head=Push(head,4,1);
	head=Push(head,5,2);
	head=Push(head,6,3);
	head=Push(head,7,0);
	DisplayList(head);
	head=Pop(head);
	DisplayList(head);
	printf("Highest priority element in the queue is %d",Peek(head));
}
