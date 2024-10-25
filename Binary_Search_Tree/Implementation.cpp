#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

Node* Built_Tree(Node* &root, int data) {
    if (root == NULL) {
        return root = new Node(data);
    }

    if (data < root->val) {
        root->left = Built_Tree(root->left, data);
    } else if (data > root->val) {
        root->right = Built_Tree(root->right, data);
    }
    return root;
}

void Insertion(Node* &root) {
    int data;
    while (true) {
        cout << "Enter Data (-1 to stop): ";
        cin >> data;
        if (data == -1) break;
        Built_Tree(root, data);
    }
}

bool Searching( Node* &root, int key ){

   if( root ==  NULL) return false;
   else if( root->val == key ) return true;
   else if( key > root->val ) Searching( root->right, key);
   else Searching( root->left,key );

}

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        cout << " ";
    }
}

void printBinaryTree(Node* root) {
    if (!root) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        bool hasNodes = false; 
        int space = (1 << (4 - level)); 

        printSpaces(space / 2);
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();

            if (current) {
                cout << setw(2) << current->val;
                hasNodes = true; 
                q.push(current->left);
                q.push(current->right);
            } else {
                cout << "  ";
                q.push(nullptr);
                q.push(nullptr);
            }
            printSpaces(space);
        }
        cout << endl;

        if (!hasNodes) {
            break;
        }
        level++;
    }
}

int main() {
    Node* root = nullptr;
    Insertion(root);
    cout << Searching(root,7) << endl;
    printBinaryTree(root);
    return 0;
}
