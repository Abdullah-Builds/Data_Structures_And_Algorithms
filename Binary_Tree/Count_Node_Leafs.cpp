#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

Node *Build_Tree()
{

    int data;
    cout << "Enter data : " << endl;
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }

    Node *root = new Node(data);

    cout << "Enter data at left " << data << endl;
    root->left = Build_Tree();

    cout << "Enetr data at right " << data << endl;
    root->right = Build_Tree();

    return root;
}

void Count_Leaf_Nodes(Node *root, int &count)
{

    if (root == nullptr)
    {
        count++;
        return;
    }

    Count_Leaf_Nodes(root->left, count);
    Count_Leaf_Nodes(root->right, count);

}

int main(){

    Node* root = nullptr;
    root = Build_Tree();

    int count = 0;
    Count_Leaf_Nodes(root,count);

    cout << "Number of Leaf Nodes : " << count ;

}