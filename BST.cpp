#include<stdio.h>
#include<iostream>
using namespace std;
struct node
{
    struct node *left;
    int item;
    struct node *right;
};
class BST
{
private:
    node *root;
public:
    BST();
    ~BST();
    bool isEmpty();
    void Insert(int);
    void preorder();
    void preorderrec(node *);
    void postorder();
    void postorderrec(node *);
    void inorder();
    void inorderrec(node *);
    void search(int);
    void del(int);
    node* deleteNode(node*,int);
    int height(node*);
    node* getroot();
};
node* BST::getroot()
{
    return root;
}

int BST::height(node *root)
{
    if(root==NULL)
    return 0;
    return max(height(root->left),height(root->right))+1;
}
node* BST::deleteNode(node *ptr,int data)
{
    if(ptr==NULL)
    return NULL;
    if(ptr->item>data)
    ptr->left=deleteNode(ptr->left,data);
    if(ptr->item<data)
    ptr->right=deleteNode(ptr->right,data);
    else
    {
        //no child
        if(ptr->left==NULL && ptr->right==NULL)
        {
            delete ptr;
            return NULL;
        }
        //single child
        if(ptr->left==NULL || ptr->right==NULL)
        {
            node *child=ptr->left?ptr->left:ptr->right;
            delete ptr;
            return child;
        }
        // double child
        node *pred,*parpred;
        parpred=ptr;
        pred=ptr->left;
        while(pred->right!=NULL)
        {
            parpred=pred;
            pred=pred->right;
        }
        ptr->item=pred->item;
        parpred->right=deleteNode(pred,pred->item);
    }
    return ptr;

}
void BST::del(int data)
{
   root=deleteNode(root,data);
}
void BST::search(int data)
{
    node *t;
    t=root;
    while(t)
    {
        if(t->item==data){
        cout<<"item found"<<endl;
        break;
        }
        else
        {
            if(t->item>data)
            {
                if(t->left!=NULL)
                t=t->left;
                else{
                cout<<"not found"<<endl;
                break;
                }
            }
            else{
                
                if(t->right!=NULL)
                t=t->right;
                else{
                cout<<"not found"<<endl;
                break;
                }
            }
        }
    }
}
void BST::preorder()
{
    preorderrec(root);
}
void BST::preorderrec(node *t)
{
    if(t)
    {
        cout<<" "<<t->item;
preorderrec(t->left);
preorderrec(t->right);

      
    }
}
void BST::postorder()
{
    postorderrec(root);
}
void BST::postorderrec(node *t)
{
    if(t)
    {
preorderrec(t->left);
preorderrec(t->right);
        cout<<" "<<t->item;

      
    }
}
void BST::inorder()
{
    inorderrec(root);
}
void BST::inorderrec(node *t)
{
    if(t)
    {
preorderrec(t->left);
        cout<<" "<<t->item;
preorderrec(t->right);

      
    }
}
 void BST::Insert(int data)
 {
   //Insertion always at leaf node
   node *t;
   node *n=new node;
   n->item=data;
   n->left=NULL;
   n->right=NULL;
   if(root==NULL)
    root=n;
    else{
        t=root;
         while(t->item!=n->item)
         {
            if(t->item>data)
            {
                if(t->left==NULL){
                t->left=n;
                break;
                }
                else
                {
                    t=t->left;
                }
            }
            else{
                 if(t->right==NULL){
                t->right=n;
                break;
                }
                else
                {
                    t=t->right;
                }
            }
         }
         if(t->item==data)
         delete n;
    }
   

 }
bool BST::isEmpty()
{
    return root==NULL;
}
BST::BST()
{
    root=NULL;
}

BST::~BST()
{
    while(root)
    del(root->item);
    
}
int main()
{
 BST a;
 a.Insert(1);
 a.Insert(12);
 a.Insert(9);
 a.Insert(5);
 a.Insert(6);
cout<<a.height(a.getroot())<<endl;
// cout<<a.isEmpty()<<endl;


    return 0;
}