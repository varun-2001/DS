#include <iostream>
using namespace std;

class node
{
    int data;
    node *next;

public:
    void display();
    void insert_end(int x);
    void insert_before(int k, int data1);
    void insert_after(int k, int data1);
    void delete_specific(int k);
};
node *first = NULL;
void node ::display()
{
    node *i = first;
    cout<<"The LinkedList Elements Are:\n";
    while (i != NULL)
    {
        cout << i->data <<endl;
        i = i->next;
    }
}
void node::insert_end(int x)
{
    if (first == NULL)
    {
        node *temp = new node();

        temp->data = x;
        temp->next = NULL;
        first = temp;
    }
    else
    {
        node *temp;
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
            cout << "hi" << endl;
        }
        node *i = new node();
        temp->next = i;

        i->data = x;
        i->next = NULL;
    }
}
void node::insert_before(int k, int data1)
{
    node *temp;

    if (first == NULL)
    {
        node *i = new node();

        i->next = NULL;
        i->data = data1;
        first = i;
    }
    else if (first->data == k)
    {
        node *i = new node();

        i->next = first;
        i->data = data1;
        first = i;
    }
    else
    {
        while (temp->next->data != k)
        {
            temp = temp->next;
        }
        node *i = new node();
        i->next = temp->next;
        temp->next = i;
        i->data = data1;
    }
}
void node::insert_after(int k, int data1)
{
    node *temp;

    if (first == NULL)
    {
        node *i = new node();
        i->next = NULL;
        i->data = data1;
        first = i;
    }
    else if (first->data == k)
    {
        node *i = new node();
        temp = first;
        temp->next = first->next;
        temp->data = data1;
    }
    else
    {
        temp = first;
        while (temp->data != k)
        {
            temp = temp->next;
        }
        node *i = new node();
        i->next = temp->next;

        temp->next = i;
        i->data = data1;
    }
}
void node::delete_specific(int k)
{
    node *temp = first;
    node *prev;
    while (temp->data != k)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete (temp);
}

int main()
{
    node *LL = new node();
    int choice;
    int ele;
    while (1){
        cout<<"Choose Option: \n ";
        cout<<"1) Insert an element in the beginning of the list \n";
        cout<<"2) Insert an element at the end of the list \n";
        cout<<"3) Insert an element before another element in the existing list \n";
        cout<<"4) Insert an element after another element in the existing list \n";
        cout<<"5) Delete a given element from the list\n";
        cout<<"6) Print the list\n";
        cin>>choice;
        switch (choice){
        case 1:
            cout<<"Enter Element:\n";
            cin>>ele;
            LL->insert_before(NULL, ele);
            break;
        case 2:
            cout<<"Enter Element:";
            cin>>ele;
            LL->insert_end(ele);
            break;
        case 3:
            int before;
            cout<<"Enter Element:";
            cin>>ele;
            cout<<"Enter Before Element:\n";
            cin>>before;
            LL->insert_before(before,ele);
            break;
        case 4:
            int after;
            cout<<"Enter Element:";
            cin>>ele;
            cout<<"Enter After Element:\n";
            cin>>after;
            LL->insert_after(after,ele);
            break;
        case 5:
            cout<<"Enter Element:\n";
            cin>>ele;
            LL->delete_specific(ele);
            break;
        case 6:
            LL->display();
            break;
        default:
            cout<<"INVALID";
            break;
    }
    }
}