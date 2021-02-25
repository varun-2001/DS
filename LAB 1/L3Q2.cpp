#include <iostream>

using namespace std;
class Sparse
{
    int row, col, value;
public:
    Sparse(int r, int c, int v)
    {
        row = r ;
        col = c ;
        value = v ;
    }
    Sparse()
    {
        row = col = value = 0 ;
    }
    void display(Sparse s[ ]);
    void convert(Sparse s[ ], int [][6]);
    void transpose(Sparse s[ ] , int[][6]);
};
void Sparse :: transpose(Sparse s[ ],  int mat[][6])
{
     cout << "  TRANSPOSE " << endl;
     for(int i = 1 ; i <=  s[0].value ; i++)
    {
        int r = s[i].row;
        int c = s[i].col;
        int value = s[i].value;
        mat[c][r] = value;
    }
    for(int i =0 ; i < s[0].col; i++)
{   for(int j = 0 ; j < s[0].row; j++)
    {
        cout << mat[i][j] << " ";
    }   cout << endl;
}
}
void Sparse::display(Sparse s[])
{
    cout << "\n row \t col \t value \n" ;
    for(int i =0  ; i <= s[0].value; i++)
    {
        cout << "\n" << s[i].row << "\t" << s[i].col << "\t" << s[i].value;
    }
}
void Sparse::convert(Sparse s[], int mat[][6])
{
    for(int i = 1 ; i <=  s[0].value ; i++)
    {
        int r = s[i].row;
        int c = s[i].col;
        int value = s[i].value;
        mat[r][c] = value;
    }
    for(int i =0 ; i < s[0].row; i++)
{   for(int j = 0 ; j < s[0].col; j++)
    {
        cout << mat[i][j] << " ";
    }   cout << endl;
}

}
int main()
{
    Sparse s[20];
    int r, c, v;
    cout << "Rows:" << endl;
    cin >> r ;
    cout << "Columns:" << endl;
    cin >> c;
    cout << "No. of non-zero values:" << endl;
    cin >> v ;
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
