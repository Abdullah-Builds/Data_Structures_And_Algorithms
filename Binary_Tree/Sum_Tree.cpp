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
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;

    if (data == -1)
        return nullptr;

    Node *root = new Node(data);

    cout << "Enter Data for Left of " << data << ": ";
    root->left = Built_Tree();

    cout << "Enter Data for Right of " << data << ": ";
    root->right = Built_Tree();

    return root;
}

int Sum_Tree(Node *root, int &sum) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = Sum_Tree(root->left, sum);
    int rightSum = Sum_Tree(root->right, sum);

    sum += root->val;
    return root->val + leftSum + rightSum;
}

int main() {
    Node *root = nullptr;
    root = Built_Tree();

    int root_Val = root->val;
    int sum_left = 0;
    int sum_right = 0;

    Sum_Tree(root->left, sum_left);
    Sum_Tree(root->right, sum_right);

    if (sum_left + sum_right == root_Val) {
        cout << "Sum Tree is possible" << endl;
    } else {
        cout << "Sum Tree is not possible" << endl;
    }

    return 0;
}


/*                                                                 1                                                               
                                                                  / \            
                                                                 2   3
                                                                / \
                                                               4   5


                                            Here's how the function works step by step:

Start at the root node (1).
Recursively compute the sum for the left subtree.
Recursively compute the sum for the right subtree.
Add the current node's value to the running total (sum).
Return the sum of the subtree rooted at the current node.
We'll use the tree shown above and step through the function with a dry run. Initially, the sum is 0.

Step-by-Step Dry Run:

Node 1:

root is 1.
Call Sum_Tree(root->left, sum) for left child (2).
Node 2:

root is 2.
Call Sum_Tree(root->left, sum) for left child (4).
Node 4:

root is 4.
Call Sum_Tree(root->left, sum) for left child (nullptr).
Returns 0 (base case).
Call Sum_Tree(root->right, sum) for right child (nullptr).
Returns 0 (base case).
Update sum with 4 (sum is now 4).
Return 4 (root->val + leftSum + rightSum = 4 + 0 + 0).
Back to Node 2:

leftSum is 4.
Call Sum_Tree(root->right, sum) for right child (5).
Node 5:

root is 5.
Call Sum_Tree(root->left, sum) for left child (nullptr).
Returns 0 (base case).
Call Sum_Tree(root->right, sum) for right child (nullptr).
Returns 0 (base case).
Update sum with 5 (sum is now 9).
Return 5 (root->val + leftSum + rightSum = 5 + 0 + 0).
Back to Node 2:

rightSum is 5.
Update sum with 2 (sum is now 11).
Return 11 (root->val + leftSum + rightSum = 2 + 4 + 5).
Back to Node 1:

leftSum is 11.
Call Sum_Tree(root->right, sum) for right child (3).
Node 3:

root is 3.
Call Sum_Tree(root->left, sum) for left child (nullptr).
Returns 0 (base case).
Call Sum_Tree(root->right, sum) for right child (nullptr).
Returns 0 (base case).
Update sum with 3 (sum is now 14).
Return 3 (root->val + leftSum + rightSum = 3 + 0 + 0).
Back to Node 1:

rightSum is 3.
Update sum with 1 (sum is now 15).
Return 15 (root->val + leftSum + rightSum = 1 + 11 + 3).
Final Output:

The sum variable holds the total sum of the tree, which is 15.
The return value of the function call Sum_Tree(root, sum) is also 15, which is the sum of the entire tree.
Visual Representation:


                                                        1 (15)
                                                           / \
                                                         2 (11) 3 (3)
                                                        / \
                                                      4 (4) 5 (5)



*/
