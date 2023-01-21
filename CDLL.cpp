#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class CDLL
{
private:
    node *start;
public:
    CDLL();
   void InsertFirst(int);
   void InsertLast(int);
   node* search(int);
   void InsertAfter(node*,int);
   void Deletestart();
   void Deletelast();
   void DeleteNode(node*);
   ~CDLL();

};
CDLL::~CDLL()
{
    while(start)
    Deletestart();

}
   void CDLL::DeleteNode(node* temp)
   {
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
   }
 void CDLL::Deletelast()
 {
    node *r;
    r=start->prev;
    if(r->next!=start)
   { r->prev->next=start;
    start->prev=r->prev; }
    else
    start=NULL;
    delete r;
 }
void CDLL::Deletestart()
{
node *t;
t=start;
if(start)
{start->prev->next=t->next;
t->next->prev=t->prev;
start=t->next;
delete t; }
}

void CDLL::InsertAfter(node* temp,int data)
{
    node *n=new node;
    n->item=data;
    n->prev=temp;
    if(temp->next==start)
    {
        n->next=start;
        start->prev=n;
    }
    else
    { n->next=temp->next;
    temp->next->prev=n; }
    temp->next=n;
}
node* CDLL::search(int data)
{
    node *t;
    t=start;
    do
    {
        if(t->item==data)
        return t;
        t=t->next;
    } while(t->next!=start);
      return NULL;  
}
    

 void CDLL::InsertLast(int data)
 {
    node *n=new node;
    n->item=data;
    n->prev=start->prev;
    n->next=start;
    n->prev->next=n;
    n->next->prev=n;
 }
void CDLL::InsertFirst(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
  {  n->next=n;
  n->prev=n;
  start=n;
   }
else
n->prev=start->prev;
    n->next=start;
    n->next->prev=n;
    start=n;
}
CDLL::CDLL()
{
    start=NULL;
}


