#include<iostream>
using namespace std;

class node
{
    int data;
    node* left;
    node* right;
public:
    node* createBST(node*);
    void inorderPrint(node*);
    node* deleteNode(node*, int);
    node* findMin(node*);
};
//created BST
node* node::createBST(node* root)
{
    if(root==NULL)
    {
        node *temp=new node;
        cout<<"Enter data"<<endl;
        cin>>temp->data;
        temp->right=NULL;
        temp->left=NULL;
        root=temp;
        return root;
    }
    else if(root->data>data)
    {
        root->left=createBST(root->left);
    }
    else
    {
        root->right=createBST(root->right);
    }
    return root;
}
//finding minimum by moving leftwards
node* node::findMin(node* root)
{
    if(root==NULL)
        return root;
    while(root->left!=NULL)
        root=root->left;
    return root;
}
//delete node code
node* node::deleteNode(node *root,int d)
{
    if(root==NULL)
        return root;
    else if(root->data>d)
    {
        cout<<"entering left loop "<<root->data<<endl;
        root->left=deleteNode(root->left,d);
    }
    else if(root->data<d)
    {
        cout<<"Entering right loop "<<root->data<<endl;
        root->right=deleteNode(root->right,d);
    }
    else //root value is found
    {
        cout<<"value found"<<endl;
        //Case 1: No child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        //Case 2: One child
        else if(root->left==NULL)
        {
            node* temp=root;
            root=root->right;
            delete temp;
            temp=NULL;
        }
        else if(root->right==NULL)
        {
            node* temp=root;
            root=root->left;
            delete temp;
            temp=NULL;
        }
        //Case 3: 2 children
        else
        {
            node* temp=findMin(root->right);//find minimum in right of root
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}
//Printing values of BST (preorder traversal)
void node::inorderPrint(node* root)
{
    if(root)
    {
        cout<<root->data<<" ";
        inorderPrint(root->left);
        inorderPrint(root->right);
    }
}

int main()
{
    node *root=NULL;
    node object;
    bool to_continue=true;
    while(to_continue)
    {
        int a;
        root=object.createBST(root);
        cout<<"To continue type 1"<<endl;
        cin>>a;
        if(a!=1)
             to_continue=false;
    }
    cout<<"Values inserted:"<<endl;
    object.inorderPrint(root);
    cout<<endl;
    int n;
    cout<<"Enter value to delete:"<<endl;
    cin>>n;
    root=object.deleteNode(root,n);
    cout<<"After deletion:"<<endl;
    object.inorderPrint(root);
    return 0;
}
