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

void solve(Node *root,  vector<int>&ans)
{
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        while (node) {
            // Add the current node's value to the result.
            ans.push_back(node->val);

            // If the current node has a left child, push it to the queue.
            if (node->left) {
                q.push(node->left);
            }

            // Move to the right child.
            node = node->right;
        }
    }
}


int main()
{
    vector<int> ans;
    Node *root = Build_Tree();
    solve(root,ans);

    for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}
