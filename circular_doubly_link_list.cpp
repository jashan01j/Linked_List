#include<iostream>
#include<stdio.h>
using namespace std;
struct node{
	node *prev;
	int item;
	node *next;
};
class CDLL{
	node *start;
	public:
		CDLL();
		void traverse();
		void insertbeg(int);
		void insertlast(int);
		void deletebeg();
		void deletelast();
		node* search(int);
		void insertafter(node*,int);
		void deletespec(node*);
		~CDLL();
};
CDLL::~CDLL()
{
	while(start)
		deletebeg();
}
void CDLL::deletespec(node *temp)
{
	if(temp)
	{
		if(start==start->next)
		{
			start=NULL;
		}
		else
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			if(start==temp)
				start=temp->next;
		}
		delete temp;
	}
}
void CDLL::insertafter(node* temp,int data)
{
	if(temp)
	{
		node *n=new node();
		n->item=data;
		n->next=temp->next;
		n->prev=temp;
		temp->next->prev=n;
		temp->next=n;
	}
}
node* CDLL::search(int data)
{
	node *t;
	t=start;
	if(t)
	{
		do
		{
			if(t->item==data)
				return t;
			t=t->next;
		}while(t!=start);
	}
	return NULL;
}
void CDLL::deletelast()
{
	node *t;
	if(start)
	{
		if(start==start->next)
		{
			delete start;
			start=NULL;
		}
		else
		{
			t=start->prev;
			t->prev->next=start;
			start->prev=t->prev;
			delete t;
		}		
	}
}
void CDLL::deletebeg()
{
	node *t;
	if(start)
	{
		if(start==start->next)
		{
			delete start;
			start=NULL;
		}
		else
		{
			t=start;
			start->next->prev=start->prev;
			start->prev->next=start->next;
			start=start->next;
			delete t;
		}
		
	}
}
void CDLL::insertlast(int data)
{
	node *n=new node();
	n->item=data;
	if(start)
	{
		n->next=start;
		start->prev->next=n;
		n->prev=start->prev;
		start->prev=n;
	}
	else
	{
		n->next=n;
		n->prev=n;
		start=n;
	}
}
void CDLL::insertbeg(int data)
{
	node *n=new node();
	n->item=data;
	if(start)
	{
		n->next=start;
		start->prev->next=n;
		n->prev=start->prev;
		start->prev=n;
		start=n;	
	}
	else
	{
		n->next=n;
		n->prev=n;
		start=n;
	}
}
void CDLL::traverse()
{
	if(start)
	{
		node *t;
		t=start;
		do
		{
			cout<<t->item<<" ";
			t=t->next;
		}while(t!=start);
	}
}
CDLL::CDLL()
{
	start=NULL;
}
int main()
{
	CDLL obj;
//	obj.insertbeg(2);
//	obj.insertbeg(3);
	obj.insertlast(4);
	obj.insertlast(5);
//	obj.insertlast(6);
	node *t;
	t=obj.search(5);
	obj.deletespec(t);
	obj.traverse();
}
