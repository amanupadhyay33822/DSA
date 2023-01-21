#include "SLL.cpp"
class Polynomial
{ struct node
  { int coeff;
   int pow;
   node *next;
  };
  node *start;
  public:
  Polynomial();
  void insert(int,int);
  void add(node*,node*);
};
void Polynomial::add(node* a,node* b)
{
  node *result;
 
  while(a->next&&b->next)
 {  if(a->pow<b->pow)
   {
    result->pow=b->pow;
    result->coeff=b->coeff;
    b=b->next;
   }
   else if(a->pow>b->pow)
   {
     result->pow=a->pow;
    result->coeff=a->coeff;
    a=a->next;
   }
   else
   {
    result->pow=b->pow;
    result->coeff=b->coeff+a->coeff;
     a=a->next;
     b=b->next;
   }
 }
 result
}
void Polynomial::insert(int c,int d)
{
    node*n=new node;
    node *t,*p;
    n->coeff=c;
    n->pow=d;

    if(start==NULL)
    {
      n->next=NULL;
      start=n;
    }
    else
    {
      t=start;
      p=NULL;
      while(t!=NULL)
      {
        if(t->pow<d)
       { n->next=t;
        p->next=n; }
      }
    }

}
Polynomial::Polynomial()
{
  start=NULL;
}
void sort(SLL &obj)
{
  node *t1,*t2;
  t1=obj.return_start();
t2=t1->next;
while(t2)
{
if(t1->item>t2->item)
{int x;
x=t2->item;
t2->item=t1->item;
t1->item=x;
}
else
{
  t2=t2->next;
  t1=t1->next;
}
}
}
int count(SLL &obj)
{ int count=0;
node *t;
t=obj.return_start();
   while(t!=NULL)
   {
    count++;
   }
return count;
}
node Reverse(SLL &obj)
{
  node*t1,*t2,*t3;
  t1=obj.return_start();
  t2=t1->next;
  t3=t2->next;
  while(t3!=NULL)
  {
    t2->next=t1;
    t1=t2;
    t2=t3;
    t3=t3->next;
  }
  

}
node* Middle(SLL &obj)
{
  node*t1,*t2;
  t1=t2=obj.return_start();
  while(t2!=NULL)
  {
    t1=t1->next;
    t2=t2->next->next;
  }
  return t1;
}
int Iscycle(SLL &obj)
{
  node *t1,*t2;
  t1=obj.return_start();
  t2=t1;
  
  do
  {
    if(t2==NULL)
    return 0;
    if(t2->next!=NULL)
    t2=t2->next->next;
    else
    return 0;
    t1=t1->next;

  }while(t1!=t2);
  return 1;
}

int length_of_cycle(SLL &obj)
{ int count=1;
node *t1,*t2;
  if(Iscycle(obj))
  {
      do
      {
             t2=t2->next->next;
             t1=t1->next;
      } while (t1!=t2);
      while(t1->next!=t2)
      {
        count++;
        t1=t1->next;
      }
      return count;
  }
  return 0;
}
