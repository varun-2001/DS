#include <iostream>
#define STACK_SIZE 10

using namespace std;

class stack{
public:
    stack(){top=-1;}
    bool push(int item);
    int pop();
    void display();
private:
    int s[10],item,top;
};

bool stack::push(int item)
{
    if(top==STACK_SIZE-1){
        cout<<"Stack Overflow \n";
        return false;
    }
    else{
        s[++top]=item;
        return true;
    }
}
int stack::pop(){
if (top==-1){
    cout<<"Stack Empty\n";
    return -1;
}
return s[top--];
}

void stack::display(){
    int i=0;
    if (top==-1){
        cout<<"Empty Stack";
    }
    else{
        cout<<"Stack Elements:\n";
        for (i=0;i<=top;i++){
            cout<<s[i]<<"\n";
        }
    }


}


int main()
{
    stack s;
    int x;
    cout<<"Enter 10 elements for Stack:"<<endl;
    for (int i=0;i<10;i++){
        cin>>x;
        s.push(x);
    }
    s.display();
    return 0;
}
