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
    /*
              1
           /    \
         2        3
        / \      / \
       4   5    6   7
                     \
                      9
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);

    return root;
}

void solve(Node *root,  map<int, int> &mapping)
{
    if (root == nullptr)
        return;

    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        Node* temp = p.first;
        int hd = p.second;
        q.pop();

     
            mapping[hd] = (temp->val);

        if (temp->left)
           q.push({temp->left, hd-1});
        if (temp->right)
           q.push({temp->right, hd+1});
    }
}

void map_to_array( map<int, int> &mapping, vector<int>&ans ){

    for( auto &ch : mapping){
        ans.push_back( ch.second );
    }
}

int main()
{
    vector<int> ans;
    Node *root = Build_Tree();
     map<int, int> mapping;
    solve(root, mapping);
    map_to_array(mapping,ans);

    for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}
