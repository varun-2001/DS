#include <iostream>
using namespace std;
class list
{
    int data;
    list *next;
    list *prev;

public:
    void ins_rear();   //insert at rear
    void del_rear();   //delete rear node
    void ins_pos();    //insert at position, pos
    void del_pos();    //delete node at any pos
    void ins_after();  //insert after node
    void ins_before(); //insert before node
    void traverse();   //print
};
list *first = NULL;

void list::ins_rear()
{
    list *temp, *curr;
    temp = new list;
    cout << "\nEnter the data:";
    cin >> temp->data;
    temp->prev = NULL;
    temp->next = NULL;
    if (first == NULL)
        first = temp;
    else
    {
        for (curr = first; curr->next != NULL; curr = curr->next)
            ;
        curr->next = temp;
        temp->prev = curr;
    }
    traverse();
}

void list::del_rear()
{
    list *curr, *prev;
    if (first == NULL)
    {
        cout << "LIST EMPTY";
        return;
    }
    if (first->next == NULL)
    {
        first = NULL;
    }
    else
    {
        for (curr = first; curr->next != NULL; curr = curr->next)
        {
            prev = curr;
        }
        prev->next = NULL;
        delete (curr);
    }
    traverse();
}

void list::ins_pos()
{
    list *curr, *temp;
    temp = new list();
    int val, x, ctr = 0;
    cout << "Enter the value to be inserted: ";
    cin >> val;
    temp->next = NULL;
    temp->prev = NULL;
    temp->data = val;
    cout << "Enter the position to be inserted(starting from 0): ";
    cin >> x;
    curr = first;
    if (x == 0)
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    while (ctr < x)
    {
        curr = curr->next;
        ctr++;
    }
    curr->prev->next = temp;
    temp->prev = curr->prev;
    temp->next = curr;
    curr->prev = temp;
    traverse();
}

void list::del_pos()
{
    list *curr;
    curr = first;
    int x, ctr = 0;
    cout << "Enter the position to be deleted(starting from 0): ";
    cin >> x;
    if (first == NULL)
    {
        cout << "LIST IS EMPTY!";
    }
    if (x == 0 && first->next == NULL)
    { //only one element
        first = NULL;
    }
    else
    {
        while (ctr < x)
        {
            curr = curr->next;
            ctr++;
        }
        if (curr->next == NULL)
        {
            curr->prev->next = NULL;
            delete (curr);
        }
        else
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete (curr);
        }
    }
    traverse();
}
void list::ins_after()
{
    int x, flag = 0;
    list *temp;
    temp = new list;
    cout << "\nEnter the element after which the node is to be inserted: ";
    cin >> x;
    cout << "\nEnter the data for the node: ";
    cin >> temp->data;
    temp->prev = temp->next = NULL;
    if (first == NULL)
    {
        cout << "\nList empty, adding this element as headnode";
        first = temp;
    }
    else if (first->data == x) //first node
    {
        temp->next = first->next;
        if (first->next != NULL)
            first->next->prev = temp;
        first->next = temp;
    }
    else
    {
        for (list *curr = first; curr != NULL; curr = curr->next)
        {
            if (curr->data == x && curr->next != NULL) //not last node
            {
                temp->next = curr->next;
                curr->next->prev = temp;
                curr->next = temp;
                temp->prev = curr;
                flag = 1;
                break;
            }
            else if (curr->data == x && curr->next == NULL) //last node
            {
                curr->next = temp;
                temp->prev = curr;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
        cout << "\nNode not found\n";
    traverse();
}
void list::traverse()
{
    list *p;
    if (first == NULL)
        cout << "\nlist is empty";
    cout << "the list is: ";
    for (p = first; p != NULL; p = p->next)
    {
        cout << p->data << " ";
    }
}
void list::ins_before()
{
    int x, flag = 0;
    list *temp;
    temp = new list;
    cout << "\nEnter the element before which the node is to be inserted:";
    cin >> x;
    cout << "\nEnter the data for the node:";
    cin >> temp->data;
    temp->prev = temp->next = NULL;
    if (first == NULL)
        cout << "\nLink is empty";
    else if (x == first->data)
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
        flag = 1;
    }
    else
    {
        for (list *curr = first; curr != NULL; curr = curr->next)
        {
            if (curr->data == x)
            {
                temp->next = curr;
                temp->prev = curr->prev;
                curr->prev->next = temp;
                curr->prev = temp;
                flag = 1;
                break;
            }
        }
    }
}

int main()
{
    list l;
    char ch = 'y';
    do
    {
        cout << "\n1.Insert at rear\n2.Delete at Rear\n3.Insert at Position\n4.Delete Element at Position\n5.Insert After Element\n6.Insert Before Element\n7.Display\n8.Exit";
        cout << "\nEnter your choice:";
        cin >> ch;
        switch (ch)
        {
        case '1':
            l.ins_rear();
            break;
        case '2':
            l.del_rear();
            break;
        case '3':
            l.ins_pos();
            break;
        case '4':
            l.del_pos();
            break;
        case '5':
            l.ins_after();
            break;
        case '6':
            l.ins_before();
            break;
        case '7':
            l.traverse();
        case '0':
            break;
        default:
            cout << "\nInvalid input";
            break;
        }
        cout << "\nDo you want to continue? (y->yes)";
        cin >> ch;
    } while (ch == 'y');
}
