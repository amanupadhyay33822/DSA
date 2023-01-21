#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    node *left;
    int item;
    node *right;
    int height;
    
};
class AVL
{
private:
    node *root;
public:
    AVL();
    ~AVL();
    int getBalenceFactor();
    int height(node*);
};
int AVL::height(root)
{       ptr=root;
    if(root==NULL)
return 0;
return max(height(ptr->left),height(ptr->right))+1;

}

AVL::AVL()
{
    root=NULL;
}

AVL::~AVL()
{
}
