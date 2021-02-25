#include <iostream>
#include <cstring>

using namespace std;
const int STACK_SIZE=100;
class Stack {
    private:
    int top;
    int arr[STACK_SIZE];
    public:
    Stack(){
        top=-1;
    }
    void push(int elem){
        if(top<STACK_SIZE){
            arr[++top]=elem;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }

    int pop(){
        if(top>=0)
            return arr[top--];
        cout<<"Stack Underflow!"<<endl;
        return -1;
    }

    int peek(){
        if(top>=0)
            return arr[top];
        else{
            cout<<"Underflow"<<endl;
            return -1;
        }
    }

    void display(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
};

void prefix_evaluation()
{

    Stack obj ;
    int digit, op1, op2, res;
    char t, prefix[50] ;
    cout << "Enter Prefix:\n " ;
    gets(prefix);
    for(int i = strlen(prefix) - 1 ; i >=0 ; i--)
    {

        t = prefix[i];

        if(t >= 48 && t <= 57)
        {
            digit = t - '0';
            obj.push(digit);
        }
        else if(t == '+' || t == '-' || t == '*' || t == '/' || t == '%')
        {
            op1 = obj.pop();
            op2 = obj.pop();

        switch(t)
        {
            case '%' :
                obj.push(op1%op2); 
                break;
            case '/' : 
                obj.push(op1/op2); 
                break;
            case '+' : 
                obj.push(op1 + op2 ); 
                break;
            case '-': 
                obj.push(op1- op2 ); 
                break;
            case '*' : 
                obj.push(op1*op2); 
                break;
        }
        }
        else 
        {
            cout << "Enter " << t << "'s value" ;
            int val;
            cin >> val;
            obj.push(val);

        }
    }
    cout << "Result: " << obj.pop() ;
}
int main()
{

    prefix_evaluation();
    return 0;

}