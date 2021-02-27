#include <iostream>
using namespace std;
class node
{
private:
    node *rcl, *lcl;
    int info;
public:
    node *create(node *root) //creating a tree
    {
        node *temp = new node;
        cout << "\nenter the info:";
        cin >> temp->info;
        temp->rcl = NULL;
        temp->lcl = NULL;
        if (root == NULL)
        {
            root = temp;
            return root;
        }
        node *cur = root, *prev = NULL;
        while (cur != NULL)
        {
            if (temp->info < cur->info)
            {
                prev = cur;
                cur = cur->lcl;
            }
            else
            {
                prev = cur;
                cur = cur->rcl;
            }
        }
        if (temp->info < prev->info)
        {
            prev->lcl = temp;
        }
        else
        {
            prev->rcl = temp;
        }
        return root;
    }
    void display(node *root, int level)
    {
        if (root == NULL)
        {
            return;
        }
        display(root->rcl, level + 1);
        for (int i = 0; i < level; i++)
        {
            cout << "  ";
        }
        cout << root->info << endl;
        display(root->lcl, level + 1);
    }
};
int main()
{
    node *root = NULL, n;
    int x;
    char c;
    int level = 0;
    cout << "Enter 1 to create a tree " << endl;
    cout << "Enter 2 to display the tree" << endl;
    do
    {
        cout << "Enter your choice :" << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            root = n.create(root);
            break;
        case 2:
            cout << " Tree contains" << endl;
            n.display(root, level);
            break;
        default:
            cout << "Invalid \n";
        }
        cout << "Do u want to continue?(y/n)";
        cin >> c;
    } while (c == 'y' || c == 'Y');
    return 0;
}
