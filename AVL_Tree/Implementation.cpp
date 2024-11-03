#include <iostream>
using namespace std;


// AVL Tree Node
class Node {
    public:
    int val;
    Node* left;
    Node* right;
    int height;

    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
    Node(){
        left = nullptr;
        right = nullptr;
    }
};

// Function to get the height of the tree
int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Utility function to get the balance factor of a node
int getBalance(Node* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

// Right rotate subtree rooted with y (for Left-Left imbalance)
Node* LeftRotate(Node* root) {
    Node* x = root->left;
    Node* y = x->right;

    // Perform rotation
    x->right = root;
    root->left = y;

    // Update heights
    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;


    // Return new root
    return x;
}

// Left rotate subtree rooted with x (for Right-Right imbalance)
Node* RightRotate(Node* root) {
    Node* x = root->right;
    Node* y = x->left;


    // Perform rotation
    x->left = root;
    root->right = y;

    // Update heights
    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Utility function to print pre-order traversal of the tree
void Preorder(Node* root ) {
    if (root != nullptr) {
        cout << root->val << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

// Utility function to find the node with the minimum key value
int minValueNode(Node* node) {
    Node* current = node;

    while (current->left != nullptr)
        current = current->left;
        return current->val;
}


// Function to balance a node based on its balance factor
Node* balanceNode(Node* root) {
    int balance = getBalance(root);

    // Case 1: Left-Left (Zig-Zig) case
    if (balance > 1 && getBalance(root->left) >= 0)
        return LeftRotate(root);

    // Case 2: Right-Right (Zig-Zig) case
    if (balance < -1 && getBalance(root->right) <= 0)
        return RightRotate(root);

    // Case 3: Left-Right (Zig-Zag) case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = RightRotate(root->left);
        return LeftRotate(root);
    }

    // Case 4: Right-Left (Zig-Zag) case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = LeftRotate(root->right);
        return RightRotate(root);
    }

    // No rotation needed
    return root;
}


/******************************************************Insertion********************************** */

Node* Insertion(Node* root, int key) {
    // Step 1: Perform normal BST insertion
    if (root == nullptr)
        return root = new Node(key);
    if (key < root->val)
        root->left = Insertion(root->left, key);
    else if (key > root->val)
        root->right = Insertion(root->right, key);
    else
        return root;


    // Step 2: Update height of this ancestor node
    root->height = 1 + max(height(root->left), height(root->right));

    return balanceNode(root);

}


//***********************************************Deletion***************************************************


Node* Deletion(Node* root, int key) {
    // Step 1: Perform standard BST delete
    if (root == nullptr)
        return root;
    if (key < root->val)
        root->left = Deletion(root->left, key);
    else if (key > root->val)
        root->right = Deletion(root->right, key);
 else
    {

        if (root->left == NULL && root->right == NULL)         // 0 child
        {
            delete root;
            return NULL;
        }
        if (root->left == NULL && root->right)                // 1 child has 2 cases
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL && root->left)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left && root->right)                   // 2 child
        {
            int mini = minValueNode(root->right);
            root->val = mini;
            root->right = Deletion(root->right, mini);
            return root;
        }
    }


    // If the tree had only one node, return
    if (root == nullptr)
        return root;


    // Step 2: Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    return balanceNode(root);
}


// Main program to test AVL tree operations
int main() {
    Node* root = nullptr;


    // Inserting nodes to trigger all cases
    root = Insertion(root, 10);
    root = Insertion(root, 20);
    root = Insertion(root, 30); // Right-Right (Zig-Zig) case
    root = Insertion(root, 40);
    root = Insertion(root, 50);
    root = Insertion(root, 25); // Right-Left (Zig-Zag) case


    // Pre-order traversal of the tree
    cout << "Pre-order traversal of the AVL tree is: ";
    Preorder(root);
    cout << endl;


    // Deleting a node and balancing the AVL tree
    root = Deletion(root, 50);
    cout << "Pre-order traversal after deleting 50: ";
    Preorder(root);
    cout << endl;


    return 0;
}


