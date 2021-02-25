#include <iostream>
#include <stdio.h>

using namespace std;

class Student{
    private:
        char name[50];
        int rollNo;
        char grade;

    public:
        void read(Student s[],int n){
            for (int i=0;i<n;i++){
                cout<<"Enter Roll No.:";
                cin>>(s[i].rollNo);
                cin.sync();
                cout<<"Enter Name:";
                gets(s[i].name);
                cin.sync();
                cout<<"Enter Grade:";
                cin>>(s[i].grade);
                cin.sync();
            }
        }
        void display(Student s[], int n){
            cout<<"////////////////////////////////////////////////////////////////////////////// \n";
            for (int i=0;i<n;i++){
            cout<<"Name: "<<s[i].name<<endl;
            cout<<"Roll No.: "<<s[i].rollNo<<endl;
            cout<<"Grade: "<<s[i].grade<<endl<<"\n";
            }
        }
        void sort(Student s[],int n){
            Student temp;
            int min;
            for (int i=0;i<n;i++){
                min=i;
                for (int j=i+1;j<n;j++){
                    if (s[j].rollNo>s[min].rollNo){
                        min=j;
                    }
                }
                temp=s[min];
                s[min]=s[i];
                s[i]=temp;
            }
        }
};

int main()
{
    cout<<"Enter Number of Students:\n";
    int n;
    cin.sync();
    cin>>n;
    Student s[n],a;
    a.read(s,n);
    a.sort(s,n);
    a.display(s,n);
}
