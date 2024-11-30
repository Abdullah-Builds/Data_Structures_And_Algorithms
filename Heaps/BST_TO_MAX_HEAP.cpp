#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void Inorder_Traversal(TreeNode* root, vector<int>& nodes) {
    if (!root) return;
    Inorder_Traversal(root->left, nodes);
    nodes.push_back(root->val);
    Inorder_Traversal(root->right, nodes);
}

void Preorder_Assignment(TreeNode* root, vector<int>& nodes, int& index) {
    if (!root) return;
    root->val = nodes[index++];
    Preorder_Assignment(root->left, nodes, index);
    Preorder_Assignment(root->right, nodes, index);
}

void BST_TO_MAX_HEAP(TreeNode* root) {
    vector<int> nodes;
    Inorder_Traversal(root, nodes);
    reverse(nodes.begin(), nodes.end()); 
    int index = 0;
    Preorder_Assignment(root, nodes, index);
}

void Print(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    Print(root->left);
    Print(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    BST_TO_MAX_HEAP(root);
    Print(root);

    return 0;
}
