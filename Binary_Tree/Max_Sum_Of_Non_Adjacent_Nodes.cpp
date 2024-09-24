#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

Node *Built_Tree() {
    
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

pair<int,int>solve( Node* root){

    if( root == nullptr ) return {0,0};

    pair<int,int>left  = solve(root->left);
    pair<int,int>right = solve(root->right);

    pair<int,int>ans;
    ans.first = root->val + left.second + right.second;
    ans.second = max(left.first,left.second) + max(right.first,right.second);

    return ans;
}



int main() {
    Node *root = nullptr;
    root = Built_Tree();

    pair<int,int>result = solve( root );
    cout << "Max Sum of Non Adjacent Nodes : " << max(result.first,result.second);

    return 0;
}

