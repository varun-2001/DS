#include <iostream>
#include <ctype.h>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;
const int MAX = 50;
class Stack
{
    int top;
    char s[MAX][MAX];
    public :
    Stack(){top = -1;}
    void push(char a[]);
    char *pop();
};
void Stack ::push(char a[])
{
    top++;
    strcpy(s[top], a);
}
char* Stack :: pop()
{
    if(top == -1)
    {
        return "x";
    }
    else
    {
        return s[top--];
    }
}
void prefix_infix()
{
    Stack obj;
    char op1[20], op2[20], operator1[20];
    char symbol[20], prefix[30];
    cout << "Enter Postfix:" << endl;
    gets(prefix);
    for(int i = 0; i < strlen(prefix); i++)
    {
        char temp1[20], temp2[20];
        temp1[0] = prefix[i];
        temp1[1] =  '\0';
        strcpy(symbol, temp1);
        if(!isalpha(prefix[i]))
        {
        strcpy(op2, obj.pop());
        strcpy(op1, obj.pop());
        strcpy(temp2, "(");
        strcat(temp2, op1);
        strcat(temp2, symbol);
        strcat(temp2, op2);
        strcat(temp2, ")");
        obj.push(temp2);
        }
        else{obj.push(symbol);

        }
    }
    cout << "Result : " << obj.pop();
}
int main()
{
    prefix_infix();
    return 0;
}