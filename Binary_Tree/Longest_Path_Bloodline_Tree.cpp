
                      //Max Path Sum From Root To Leaf Node

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


void solve( Node* root,int sum, int &maxsum, int len, int maxlen){

    if( root == nullptr ) {

        if( len > maxlen ){
            maxlen = len;
            maxsum = sum;
        }
        if( len == maxlen){
            maxsum = max( sum,maxsum);
        }
        return;
    }

    sum += root->val;

    solve(root->left,sum,maxsum,len+1,maxlen);
    solve(root->right,sum,maxsum,len+1,maxlen);

}

int main() {
    Node *root = nullptr;
    root = Built_Tree();
    
    int maxSum = 0;
    solve(root,0,maxSum,0,0);
    cout << "Maximum Path Sum from Root to Leaf Node : " << maxSum ;

    return 0;
}

