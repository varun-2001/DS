#include <iostream> 
using namespace std; 
//creating binary search tree class 
class bst 
{ 
    bst *lchild; 
    int data; 
    bst *rchild; 
public: 
    bst(int ele=0) 
    { 
        lchild=NULL; 
        rchild=NULL; 
        data=ele; 
    } 
    void insert(int); 
    void display(bst *root); 
    bst* search(bst *p,int key); 
    bst* minimum_key(bst *ptr); 
}; 
bst *root=NULL; 
//inserting elements into tree 
void bst::insert(int ele) 
{ 
    bst *temp=new bst(ele); 
    if(root==NULL){root=temp;return;} 
    else 
    { 
        bst *curr=root,*prev=NULL; 
    while(curr) 
    { 
    prev=curr; 
    if(temp->data<curr->data) 
        curr=curr->lchild; 
    else if(temp->data>curr->data) 
        curr=curr->rchild; 
    else 
        {cout<<"Insertion is not possible";return;}} 
    if(temp->data>prev->data) 
        prev->rchild=temp; 
    else if(temp->data<prev->data) 
        prev->lchild=temp; 
} 
return; 
} 
//displaying the tree 
void bst::display(bst *p) //inorder rec 
{ 
    if (p!=NULL) 
    { 
        display(p->lchild); 
        cout<<p->data<<" "; 
        display(p->rchild); 
    } 
} 
//searching for key element 
bst* bst::search(bst *p,int key) 
{ 
    if (p==NULL) return NULL; 
    if(key == p->data) return p; 
    if( key<p->data) return search(p->lchild,key); 
    else 
    return search(p->rchild,key); 
} 
bst* bst::minimum_key(bst *ptr) 
{ 
    bst *curr = ptr; 
    /* loop down to find the leftmost leaf */ 
 
    while (curr && curr->lchild != NULL) 
        {curr = curr->lchild; } 
    return curr; 
} 
int main()  //driver code 
{ 
    bst b; 
    bst *temp; 
    int t,n; 
    cout<<"Enter the number of elements to be inserted in the binary tree: "; 
    cin>>n; 
    for(int i=1;i<=n;i++) 
    { 
    cout<<"Enter element to insert: "; 
    cin>>t; 
    b.insert(t); 
    } 
    b.display(root); 
    int p; 
    cout<<"\nEnter key to search: "; 
    cin>>p; 
    temp=b.search(root,p); 
    if (temp==NULL) cout<<"\nKey not found"; 
    else cout<<"\nKey found"; 
    return 0; 
} 
