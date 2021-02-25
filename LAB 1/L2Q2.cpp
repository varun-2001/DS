#include <iostream>
#define STACK_SIZE 10
using namespace std;

class stack{
public:
    stack(){top=-1;}
    bool push(int item);
    char pop();
    void display();
private:
    int s[10],item,top;
};

bool stack::push(int item){
    if(top==STACK_SIZE-1){
        cout<<"Stack Overflow \n";
        return false;
    }
    else{
        s[++top]=item;
        return true;
    }
}
char stack::pop(){
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
        for (i=0;i<=top;i++){
            cout<<s[i];
        }
    }


}


int main()
{
    string palindrome;
    stack s;
    cout << "Enter A String:" << endl;
    cin>>palindrome;

    for (int i=0;palindrome[i]!='\0';i++){
        s.push(palindrome[i]);
    }
    int flag=1;
    for (int i=0; palindrome[i]!='\0';i++){
        if(s.pop()!=palindrome[i]){
            flag=0;
            break;
        }
    }
    if (flag)
            cout<<"PALINDROME";
    else
            cout<<"NOT PALINDROME";
    return 0;
}
