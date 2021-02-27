#include <iostream>
using namespace std;

class Sparse{
    int row, column, value;

public:
    Sparse(int r, int c, int v){
        row=r;
        column=c;
        value=v;
    }
    Sparse(){
        row=column=value=0;
    }
    
    void display(Sparse s[]);
    void convert(Sparse s[], int [][6]);
    void transpose(Sparse s[], int [][6]);
};

void Sparse::transpose(Sparse s[], int mat[][6]){
    cout<<"TRANSPOSE:"<<endl;
    // Creates for loop for number of nzv
    for (int i=1;i<=s[0].value;i++){
        int r=s[i].row;
        int c=s[i].column;
        int v=s[i].value;
        mat[c][r]=value;
    }
    for (int i=0;i<s[0].row;i++){
        for (int j=0;j<s[0].column;j++){
            cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }
}

void Sparse::display(Sparse s[]){
    cout<<"\n Row \t Col \t Value \n";
    for (int i=0;i<=s[0].value;i++){
        cout<< "\n"<<s[i].row << "\t" <<s[i].column<<"\t"<<s[i].value;
    }
}

void Sparse::convert(Sparse s[], int mat[][6]){
    for (int i=1;i<=s[0].value;i++){
        int r=s[i].row;
        int c=s[i].column;
        int v=s[i].value;
        mat[r][c]=value;
    }
    for (int i=0;i<s[0].row;i++){
        for (int j=0;j<s[0].column;j++){
            cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }
}
int main(){
    Sparse s[20];
    int r,c,v;
    cout<<"Number of Rows:\n";
    cin>>r;
    cout<<"Number of Columns:\n";
    cin>>c;
    cout<<"Number of Non-Zero Values:\n";
    cin>>v;
    
    int mat[6][6] = {};
    int trans[6][6] = {};
    s[0] = Sparse(r,c,v);
    
    int nzv=v;
    for(int i = 1  ; i <= nzv; i++)
    {
        cout << "\n row" << i << ":";
        cin >> r ;
        cout << "\n col" << i << ":";
        cin >> c;
            cout << "\n value" << i << ":";
        cin >> v ;
        s[i] = Sparse(r,c,v);
    }

    s[0].display(s);
    cout << endl;
    s[0].convert(s, mat);
    s[0].transpose(s, trans);

}