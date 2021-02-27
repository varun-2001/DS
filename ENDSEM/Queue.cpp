#include <iostream>
#define size 20
using namespace std;

class Queue{
    int front, rear;
    int q[20];
    public:
    void insert(int item);
    int delq();
    void display();
    Queue(){
        front =0;
        rear=-1;
    }
};

void Queue::insert(int item){
    if (rear==size-1){
        cout<<"Queue Overflow!!";
        return;
    }
    rear+=1;
    q[rear]=item;
}

int Queue::delq(){
    if (front>rear){
        cout<<"Queue Empty";
        return -1;
    }
    return q[front++];
}

void Queue::display(){
    int i=0;
    if (front>rear){
        cout<<"QUEUE EMPTY AF";
        return;
    }
    for (i=front;i<=rear;i++)
        cout<<q[i];
}


int main(){
    int x;
    Queue kyu= Queue();
    for (int i=0;i<10;i++){
        cin>>x;
        kyu.insert(x);
    }
    kyu.delq();
    kyu.display();
}