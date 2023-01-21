#include<stdio.h>
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
class Deque
{
private:
node *front;
node *rear;
public:
    Deque();
    ~Deque();
  void InsertatFront(int);
  void InsertatRear(int);
  void DeleteFront();
  void DeleteRear();
  int getFront();
  int getRear();
  bool isEmpty();
};
bool Deque::isEmpty()
{
   return (!front);
}
int Deque::getRear()
{
    return rear->data;

}
int Deque::getFront()
{
    return front->data;

}
void Deque::DeleteRear()
{
    node *n;
    if(rear)
    {
        n=rear;
        if(rear==front)
        front=rear=NULL;
        else{
            rear=rear->prev;
            rear->next=NULL;
        }
        delete n;
    }
}
void Deque::DeleteFront()
{
    node *n;
    n=front;
    if(front)
    {  n=front;
    if(front==rear)
      front=rear=NULL;
      else{
       front=front->next;
       front->prev=NULL;
      }
      delete n;

    }

}
 void Deque::InsertatRear(int item)
 {
    node *n=new node;
    n->data=item;
    n->prev=rear;
    n->next=NULL;
    if(rear)
    rear->next=n;
    else
    front=n;
    rear=n;
 }
 void Deque::InsertatFront(int item)
 {
    node *n=new node;
    n->data=item;
  n->prev=NULL;
  n->next=front;
  if(front)
    front->prev=n;
  else
  rear=n;
front=n;

 }
Deque::Deque()
{
    front=rear=NULL;
}

Deque::~Deque()
{
    while(front)
    DeleteFront();
}
