#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string s1,s2,concat;
    cout<<"Enter String:"<<endl;
    cin>>s1;
    int count=0,i;

    //Length of String
    for (int i=0;s1[i]!='\0';i++){
        count++;
    }
    cout<<"Length Of String: "<<count<<endl;

/////////////////////////////////////////////////////////////////////////////

    //String concatenation
    cout<<"Enter String to concatenate:"<<endl;
    cin>>s2;
    concat=s1+s2;
    cout<<"Concatenated String: "<<concat<<endl;

/////////////////////////////////////////////////////////////////////////////

    //String Comparison
    int flag=0;
    i=0;
    while (s1[i]!='\0' && s2[i]!='\0'){
        if (s1[i]!=s2[i]){
            flag=1;
            break;
        }
        i++;
    }
        if (flag==0)
            cout<<"The Strings are equal"<<endl;
        else
            cout<<"The Strings are unequal"<<endl;

/////////////////////////////////////////////////////////////////////////////

    //Insert substring
    cout<<"Enter String, Substring and Index:"<<endl;
    char s[50],sub[50];
    int index,j=0;
    flag=1;
    cin>>s>>sub>>index;
    int sLength=strlen(s), subLength=strlen(sub);
    // SHIFTING ELEMENTS TO THE RIGHT BY LENGTH OF SUBSTRING
    for (int i=1;i<=(sLength-index);i++){
        s[sLength+subLength-i]=s[sLength-i];
    }
    s[sLength+subLength]='\0';
    // INSERTING SUBSTRING IN EMPTY SPACE
    for (int j=0;j<subLength;j++){
        s[index+j]=sub[j];
    }
    cout<<"Inserted Substring:"<<s;

/////////////////////////////////////////////////////////////////////////////


    //Delete substring
    char a[50],b[50];
    cout<<"\nEnter Main String:"<<endl;
    cin.sync();
    gets(a);
    cout<<"Enter Sub String:"<<endl;
    cin.sync();
    gets(b);
    int a1=strlen(a),b1=strlen(b);
    bool f =false;
    int loc=-1;

    for (int i=0;i<=a1-b1;i++){
        for (int j=i;j<i+b1;j++){
            f=true;
            if(a[j]!=b[j-i]){
                f=false;
                break;
            }
        }
        if (f==true){
            loc=i;
            break;
        }
    }
    if (loc==-1){
        cout<<"Substring Not Found";
        return 0;
    }
    for (int i=0;i<a1-loc;i++){
        a[loc+i]=a[loc+b1+i];
    }
    cout<<"RESULT:"<<a;
}
