#include<iostream>
#include<stdio.h>
using namespace std;
struct node{
	node *prev;
	int item;
	node *next;
};
class DLL
{
	node *start;
	public:
		DLL();
		void insertBeg(int);	
		void insertEnd(int);
		node* search(int);
		void insertAfter(node*,int);
		void deleteBeg();
		void deletelast();
		void deleteatspec(node*);
		void print();
		~DLL();
		
};
void DLL::print()
{
	node* temp=start;
	while(temp!=NULL)
	{
		cout<<temp->item<<" ";
		temp=temp->next;
	}
}
DLL::~DLL()
{
	while(start)
	    deleteBeg();
}
void DLL::deleteatspec(node *ptr)
{
	//important code
	if(ptr->prev)
		ptr->prev->next=ptr->next;
	else
		start=ptr->next;
	if(ptr->next)
		ptr->next->prev=ptr->prev;
	delete ptr;
//	node *temp=start;
//	if(start==NULL)
//	{
//		cout<<"List is empty";
//	}
//	else
//	{
//		if(start==ptr)
//		{
//			if(start->next==NULL)
//			{
//				delete start;
//				start=NULL;
//			}
//			else
//			{
//				start=start->next;
//				start->prev=NULL;
//				delete ptr;
//			}
//		}
//		else
//		{
//			while(temp->next!=ptr)
//			{
//				temp=temp->next;
//			}
//			if(ptr->next!=NULL)
//			{
//				ptr->next->prev=temp;
//				temp->next=ptr->next;
//				delete ptr;
//			}
//			else
//			{
//				temp->next=NULL;
//				delete ptr;
//			}
//		}
//	}
}
void DLL::deletelast()
{
	if(start)
	{
		node *t=start;
		while(t->next!=NULL)
			t=t->next;
		if(t->prev)
			t->prev->next=NULL;
		else
			start=NULL;
		delete t;
	}
//	node *temp=start;
//	if(start==NULL)
//	{
//		cout<<"List in empty";
//	}
//	else if(start->next==NULL)
//	{
//		delete start;
//		start=NULL;
//	}
//	else
//	{
//		while(temp->next->next!=NULL)
//		{
//			temp=temp->next;
//		}
//		delete temp->next;
//		temp->next=NULL;
//	}
}
void DLL::deleteBeg()
{
	if(start)
	{
		node *r=start;
		start=start->next;
		if(r->next)
			start->prev=NULL;
		delete r;
	}
	//------------------------------------------------
//	if(start)
//	{
//		node *r;
//		r=start;
//		if(start->next)
//			start->next->prev=NULL;
//		start=start->next;
//		delete r;
//	}
	//-------------------------------------------------
//	node *temp;
//	if(start==NULL)
//	{
//		cout<<"List in empty";
//	}
//	else
//	{
//		temp=start;
//		start=start->next;
//		start->prev=NULL;
//		delete temp;
//	}
}
void DLL::insertAfter(node *ptr,int data)
{
	if(ptr)
	{
		node *n=new node;
		n->item=data;
		n->prev=ptr;
		n->next=ptr->next;
		if(ptr->next)
			ptr->next->prev=n;
		ptr->next=n;
	}
//	node *n=new node;
//	n->item=data;
//	n->next=NULL;
//	n->prev=NULL;
//	if(ptr->next==NULL)
//	{
//		ptr->next=n;
//		n->prev=ptr;
//	}
//	else
//	{
//		n->next=ptr->next;
//		ptr->next->prev=n;
//		ptr->next=n;
//		n->prev=ptr;
//	}
}
node* DLL::search(int data)
{
	node *temp=start;
	while(temp!=NULL)
	{ 
		if(temp->item==data)
		    return temp;
		temp=temp->next;
	}
	return NULL;
}
void DLL::insertEnd(int data)
{
	node *temp=new node;
	node *t;
	temp->item=data;
	temp->next=NULL;
	if(start==NULL)
	{
		temp->prev=NULL;
		start=temp;
	}
	else
	{
		t=start;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=temp;
		temp->prev=t;
	}
}
void DLL::insertBeg(int data)
{
	node *n=new node;
	n->item=data;
	n->prev=NULL;
	n->next=start;
	if(start)
		start->prev=n;
	start=n;
//	node *n =new node;
//	n->item=data;
//	n->prev=NULL;
//	n->next=NULL;
//	if(start==NULL)
//	{
//		start=n;
//	}
//	else
//	{
//		n->next=start;
//		start->prev=n;
//		start=n;
//	}
}
DLL::DLL()
{
	start=NULL;
}
int main()
{
	DLL obj;
	obj.insertBeg(4);
	obj.insertBeg(5);
	obj.insertBeg(6);
	obj.print();
	return 0;
}
