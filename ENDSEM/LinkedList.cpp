#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void pushFront(Node** head_ref, int newData){
    Node* newNode= new Node();
    newNode->data=newData;
    newNode->next=*head_ref;
    *head_ref=newNode;
}

void insertAfter(Node* prevNode, int newData){
    if (prevNode==NULL){
        cout<<"The Given Previous Node cannot be NULL";
        return;
    }
    Node* newNode = new Node();
    newNode->data=newData;
    newNode->next=prevNode->next;
    prevNode->next=newNode;
}

void print(Node* n){
    while (n!=NULL){
        cout<<n->data<<" ";
        n=n->next;    
    }
}

void append(Node** headRef, int newData){
    Node* newNode= new Node();
    Node *last = *headRef;
    newNode->data=newData;
    newNode->next=NULL;

    if (*headRef==NULL){
        *headRef=newNode;
        return;
    } 
    while(last->next !=NULL)
        last=last->next;

    last->next = newNode;
    return;
}

void deleteNode(Node** headRef, int key){
    Node* temp=*headRef;
    Node* prev=NULL;

    if (temp!=NULL && temp->data==key){
        *headRef=temp->next;
        delete temp;
        return;
    }

    else{
        while(temp!=NULL && temp->data!=key){
            prev=temp;
            temp=temp->next;
        }
        if (temp==NULL){
            return;
        }

    }
}

void deletePos(Node** headRef, int pos){
    if (headRef==NULL){
        return;
    }
    struct Node* temp = *headRef;

// To remove HEAD
    if (pos==0){
        *headRef=temp->next;
        free(temp);
        return;
    }

    for (int i=0;temp!=NULL && i<pos-1;i++){
        temp=temp->next;
    }
    if (temp==NULL && temp->next==NULL)
        return;
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next=next;
}


int main(){
    Node* head=NULL;
    append(&head, 6);
    pushFront(&head, 7);
    append(&head,4);
    insertAfter(head->next,8);
    cout<<"NEW LINKED LIST IS:\n";
    print(head);
    deleteNode(&head, 7);
    print(head);
    return 0;


}