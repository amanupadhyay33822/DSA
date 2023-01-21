#include "arrayadt.cpp"
class ExtendedArray:public Array
{
public:
ExtendedArray(int);
int greatest();
int smallest();
void sort();
int sum();
float average();
void rotate();
void removeDuplicate();
void printArray();
void swapitem(int,int);
};
void ExtendedArray::swapitem(int i,int j)
{
    int temp;
    if(i>=0&&i<count()&&j<count()&&j>=0)
    {
        temp=get(i);
        edit(i,get(j));
        edit(j,temp);
    }
}
void ExtendedArray::printArray()
{
    for(int i=0;i<count();i++)
    cout<<" "<<get(i);
}
void ExtendedArray::removeDuplicate()
{
  for(int i=0;i<count();i++)
  {
    for(int j=i+1;j<count();j++)
      {
        if(get(i)==get(j))
         del(j);
         j--;
      }
  }

}
void ExtendedArray::rotate() 
{ int temp;
  int lastindex;
  if(!isEmpty())
  {
  lastindex=count()-1;
  temp=get(lastindex);
  for(int i=lastindex;i>0 ;i--)
  edit(i,get(i-1));
  edit(0,temp);

  }

} 
float ExtendedArray::average()
{
    return (float)sum()/count();
}
int ExtendedArray::sum()
{
    int sum=0;
    for(int i=0;i<count();i++)
    sum=sum+get(i);
    return sum;
}
void ExtendedArray::sort()
{
    int temp=0;
    for(int i=0;i<count();i++)
    {
        for(int j=i+1;j<count();j++)
        {
            if(get(i)>get(j))
            {
                temp=get(i);
                edit(i,j);
                edit(j,temp);
                 
            }
        }
    }
    


}
ExtendedArray::ExtendedArray(int cap):Array(cap) { }
int ExtendedArray::greatest()
{
int max;
if(isEmpty())
{  cout<<"\nArray is Empty";
  return -1;
}
    max=get(0);
    for(int i=1;i<count();i++)
    {
  if(max<get(i))
  max=get(i);
    }
return max;
}
int ExtendedArray::smallest()
{
int min;
if(isEmpty())
{  cout<<"\nArray is Empty";
  return -1;
}
    min=get(0);
    for(int i=1;i<count();i++)
    {
  if(min>get(i))
  min=get(i);
    }
return min;
}

