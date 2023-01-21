#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class DLL
{
node *start;
public:
  DLL();
  void InsertFirst(int);
  void InsertLast(int);
  node * search(int);
  void InsertAfter(node*,int);
  void DeleteFirst();
   void DeleteLast();
   void DeleteAfter(node*);
   ~DLL();
};
DLL::~DLL()
{
    while(start)
     DeleteFirst();
}
  void DLL::DeleteAfter(node* t) 
  { if(t->prev)
  t->prev->next=t->next;
  else
  start=t->next;
  if(t->next)
  t->next->prev=t->prev;
  else
  delete t;
  }
void DLL::DeleteLast()
{
    if(start==NULL)
    cout<<"\nUnderflow";
    node *t=start;
    while(t->next!=NULL)
    t=t->next;
    if(t->prev)
    t->prev->next=NULL;
    else
    start=NULL;//there is only one node
    delete t;
    
}
void DLL::DeleteFirst()
{
    
    if(start==NULL)
    cout<<"\nunderflow";
    node *t=start;
    start=start->next;
    if(t->next)
    start->prev=NULL;
    delete t;
}
void DLL::InsertAfter(node *t,int data)
{ 
    node *n=new node;
    n->item=data;
    n->prev=t;
    n->next=t->next;
    if(t->next)
    t->next->prev=n;
    t->next=n;
}
node * DLL::search(int data)
{ node *t;
t=start;
  while(t!=NULL)
{
   if(t->item==data)
   return t;
   t=t->next;
}
return NULL;
}
void DLL::InsertLast(int data)
{ node *t;
    node *n=new node;
    n->next=NULL;
    n->item=data;
    
    if(start==NULL)
   { n->prev=NULL;
    start=n;  }
    else
    { t=start;
    while(t->next!=NULL)
        t=t->next;
    n->prev=t;
    t->next=n;
    }
}
DLL::DLL()
{
  start=NULL;
}
void DLL::InsertFirst(int data)
{ 
    node *n=new node;
    n->prev=NULL;
    n->item=data;
    n->next=start;
    if(start)
  n->next=start;
    start->prev=n;
    start=n; 
    
}

