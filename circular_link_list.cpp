#include<iostream>
#include<stdio.h>
using namespace std;
struct node{
	int item;
	node *next;
};
class CLL{
	node *last;
	public:
		CLL();
		void print();
		void insertbeg(int);
		void insertend(int);
		node* search(int);
		void insertafter(node*,int);
		void deletebeg();
		void deletelast();
		void deletespec(node*);
		~CLL();
};
CLL::~CLL()
{
	while(last)
		deletebeg();
}
void CLL::print()
{
	if(last)
	{
		node *t;
		t=last->next;
		do
		{
			cout<<t->item<<" ";
			t=t->next;
		}while(t!=last->next);
	}
}
void CLL::deletespec(node *p)
{
	if(p)
	{
		node *t;
		t=last->next;
		while(t->next!=p)
			t=t->next;
		t->next=p->next;
		if(t==p)
			last=NULL;
		else if(p==last)
			last=t;
		delete p;
	}
	//-----------------------------------------------
//	if(p)
//	{
//		node *t;
//		t=last->next;
//		while(t->next!=p)
//			t=t->next;
//		if(t->next==p->next)
//		{
//			last=NULL;
//		}
//		else
//		{
//			t->next=p->next;
//			if(last==p)
//			{
//				last=t;
//			}
//		}
//		delete p;
//	}
}
void CLL::deletelast()
{
	if(last)
	{
		node *t;
		t=last;
		while(t->next!=last)
			t=t->next;
		if(t==last)
		{
			delete last;
			last=NULL;
		}
		else
		{
			t->next=last->next;
			delete last;
			last=t;
		}
	}
	//---------------------------------------------
//	node *t,*p;
//	if(last)
//	{
//		t=last->next;
//		if(t==last)
//			last==NULL;
//		else
//		{
//			while(t!=last)
//			{
//				p=t;
//				t=t->next;
//			}
//			p->next=t->next;
//			last=p;
//		}
//		delete t;
//	}
}
void CLL::deletebeg()
{
	node *t;
	if(last)
	{
		t=last->next;
		if(last->next==t->next)
			last=NULL;
		else
			last->next=t->next;
		delete t;
	}
}
void CLL::insertafter(node *p,int data)
{
	if(p)
	{
		node *n=new node;
		n->item=data;
		n->next=NULL;
		n->next=p->next;
		p->next=n;
		if(last==p)
			last=n;
	}
}
node* CLL::search(int data)
{
	if(last)
	{
		node *t;
		t=last->next;
		do
		{
			if(t->item==data)
				return t;
			t=t->next;
		}while(t!=last->next);
	}
	return NULL;

//-------------------------------------
//	if(last)
//	{
//		node *t;
//		t=last->next;
//		if(last->item==data)
//			return last;
//		while(t!=last)
//		{
//			if(t->item==data)
//				return t;
//			t=t->next;
//		}	
//	}
//	return NULL;
}
void CLL::insertend(int data)
{
	node *n=new node;
	n->item=data;
	n->next=NULL;
	if(last==NULL)
	{
		last=n;
		last->next=n;
	}
	else
	{
		n->next=last->next;
		last->next=n;
		last=n;	
	}
}
void CLL::insertbeg(int data)
{
	node *n=new node;
	n->item=data;
	n->next=NULL;
	if(last)
	{
		n->next=last->next;
		last->next=n;
	}
	else
	{
		last=n;
		n->next=n;
	}
}
CLL::CLL()
{
	last=NULL;
}
int main()
{
	CLL obj;
	
	obj.insertbeg(12);
	obj.insertend(14);
//	obj.insertend(15);
//	obj.insertend(16);
//	obj.deletebeg();
//	obj.deletelast();
	node *t;
	t=obj.search(12);
	obj.insertafter(t,11);
	t=obj.search(11);
	obj.insertafter(t,10);
	t=obj.search(10);
	obj.deletespec(t);
	t=obj.search(12);
	obj.deletespec(t);
	t=obj.search(11);
	obj.deletespec(t);
	t=obj.search(14);
	obj.deletespec(t);
	t=obj.search(14);
	obj.deletespec(t);
	obj.insertbeg(10);
	obj.insertbeg(13);
	obj.print();
}












