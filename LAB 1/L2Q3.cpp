#include <iostream>
#include <string.h>
using namespace std;
enum Boolean
{
    FALSE,
    TRUE
};
class Stack
{
private:
    int top, a[20], maxsize;

public:
    Stack()
    {
        maxsize = 2;
        top = -1;
    }
    Stack(int size)
    {
        maxsize = size;
        top = -1;
    }
    Boolean isFull()
    {
        if (top == maxsize - 1)
            return TRUE;
        return FALSE;
    }
    Boolean isEmpty()
    {
        if (top == -1)
            return TRUE;
        return FALSE;
    }
    void push(int x);
    int pop();
    void display();
};

void Stack::push(int x)
{
    if (isFull())
        cout << "Stack is full";
    else
        a[++top] = x;
}
int Stack::pop()
{
    if (isEmpty()){
        cout << "Stack Is Empty!";
        return(-1);

    }
    else
        return (a[top--]);
}
void Stack::display(){
    if (isEmpty())
        cout << "Stack Is Empty!";
    else
    for (int i=top;i>-1;i--)
    {
        if (a[i]<10) cout<<a[i];
        if (a[i]>=10) cout<<(char)(a[i]+55);
        // Automatically adds the A,B,C,D,E,F or G wherever required
    }
}

int main()
{
    int MyNumber,base;
    Stack s(10);
    cout<<"Enter The Number to be Converted:\n";
    cin>>MyNumber;
    cout<<"Enter Base:\n";
    cin>>base;
while (MyNumber != 0)
{
    int rem = MyNumber % base;
    int quo = MyNumber / base;
    s.push(rem);
    MyNumber = quo;
}
s.display();
return 0;
}