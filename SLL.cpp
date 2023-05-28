#include<iostream>
using namespace std;
template<typename X>
struct node{
	X item;
	node *next=NULL;
	};
template<typename X>
class SLL{
	node<X> *start;
	public:
	SLL();
	void insertBeg(X);
	void insertEnd(X);
	node<X>* search(X);
	void insertatspec(node<X>*,X);
	void deleteBeg();
	void deleteEnd();
	void deleteatspec(node<X>*);
	void traverse();
	node<X>* get_first_node();
	~SLL();
};
template<typename X>SLL<X>::~SLL()
{
	while(start)
	   deleteBeg();
}
template<typename X>node<X>* SLL<X>::get_first_node()
{
	return start;
}
template<typename X>void SLL<X>::deleteatspec(node<X>* temp)
{
	node <X>*t;
	if(start==NULL)
	   cout<<"List is epmty";
	else
	{
		if(temp)
		{
			if(start==temp)
			{
				start=temp->next;
				delete temp;
			}
			else
			{
				t=start;
				while(t->next!=temp)
				{
					t=t->next;
				}
				t->next=temp->next;
				delete temp;
			}
		}
	}
}
template<typename X>void SLL<X>::deleteEnd()
{
	if(start==NULL)
	{
		cout<<"\nLinkList is Empty";
	}
	else if(start->next==NULL)
	{
		delete start;
		start=NULL;
	}
	else
	{
		node <X>*ptr=start;
		while(ptr->next->next!=NULL)
		{
			ptr=ptr->next;
		}
		delete ptr->next;
		ptr->next=NULL;
	}
}
template<typename X>void SLL<X>::deleteBeg()
{
	node <X>*s;
	if(start)
	{
		s=start;
		start=start->next;
		delete s;
	}
}
template<typename X>void SLL<X>::insertatspec(node<X> *ptr,X data)
{
	node <X>*n=new node<X>;
	n->item=data;
//	ptr=search(item);
	n->next=ptr->next;
	ptr->next=n;
}
template<typename X>node<X>* SLL<X>::search(X data)
{
	node <X>*temp=start;
	while(temp!=NULL)
	{
		if(temp->item==data)
		{
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}
template<typename X>void SLL<X>::traverse()
{
	node<X>* temp=start;
	while(temp!=NULL)
	{
		cout<<temp->item<<" ";
		temp=temp->next;
	}
}
template<typename X>void SLL<X>::insertEnd(X data)
{
	node<X>* temp=new node<X>;
	temp->item=data;
	if(start==NULL)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		node<X>* ptr;
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
template<typename X>void SLL<X>::insertBeg(X data)
{
	node<X>* temp=new node<X>;
	temp->item=data;
	temp->next=start;
	start=temp;
}
template<typename X>SLL<X>::SLL()
{
	start=NULL;
}
int main()
{
	SLL <float> s1;
	s1.insertBeg(4.4);
	s1.insertEnd(7.8);
	s1.insertEnd(6);
	s1.traverse();
}
