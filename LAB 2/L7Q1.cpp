#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;
class tree
{
private:
    int val;
    tree *leftChild;
    tree *rightChild;
public:
    tree *createtree()
    {
        tree *ptr;
        int data;
        cout << "Enter data(-1 to stop): ";
        cin >> data;
        if (data == -1)
            return NULL;
        ptr = new tree;
        ptr->val = data;
        cout << "Enter left child of " << data << ": ";
        ptr->leftChild = createtree();
        cout << "Enter right child of: " << data << ": ";
        ptr->rightChild = createtree();
        return ptr;
    }
    
    void posttrav(tree *cur)
    {
        cout << "Iterative Postorder Traversal: ";
        if (cur == NULL)
            return;
        stack<tree *> s;
        s.push(NULL);
        do
        {
            while (cur)
            {
                if (cur->rightChild != NULL)
                    s.push(cur->rightChild);
                s.push(cur);
                cur = cur->leftChild;
            }
            cur = s.top();
            s.pop();
            if (cur->rightChild == s.top())
            {
                s.pop();
                s.push(cur);
                cur = cur->rightChild;
            }
            else
            {
                cout << cur->val << " ";
                cur = NULL;
            }
        } while (s.top() != NULL);
        cout << "\n";
        return;
    }
    void inordertrav(tree *cur)
    {
        cout << "Iterative Inorder Traversal: ";
        if (cur == NULL)
            return;
        stack<tree *> s;
        s.push(NULL);
        while (cur != NULL || s.top() != NULL)
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->leftChild;
            }
            cur = s.top();
            s.pop();
            cout << cur->val << " ";
            cur = cur->rightChild;
        }
        cout << "\n";
        return;
    }
    void preordertrav(tree *cur)
    {
        cout << "Iterative Preorder Traversal: ";
        if (cur == NULL)
            return;
        stack<tree *> s;
        s.push(NULL);
        s.push(cur);
        while (s.top() != NULL)
        {
            cur = s.top();
            s.pop();
            cout << cur->val << " ";
            if (cur->rightChild != NULL)
                s.push(cur->rightChild);
            if (cur->leftChild != NULL)
                s.push(cur->leftChild);
        }
        cout << "\n";
        return;
    }
    int finddepth(tree *cur)
    {
        if (cur == NULL)
        {
            return 0;
        }
        else
        {
            int ldepth = finddepth(cur->leftChild);
            int rdepth = finddepth(cur->rightChild);
            if (ldepth > rdepth)
                return (ldepth + 1);
            else
            {
                return (rdepth + 1);
            }
        }
    }
    int countleaf(tree *cur)
    {
        if (cur == NULL)
        {
            return 0;
        }
        else if (cur->leftChild == NULL && cur->rightChild == NULL)
        {
            return 1;
        }
        else
        {
            return countleaf(cur->leftChild) + countleaf(cur->rightChild);
        }
    }
};
int main()
{
    tree t, *t1 = NULL;
    t1 = t.createtree();
    t.posttrav(t1);
    t.inordertrav(t1);
    t.preordertrav(t1);
    cout << "The depth is: " << t.finddepth(t1) << "\n";
    cout << "The number of leaf nodes are: " << t.countleaf(t1) << "\n";
    return 0;
}   
