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

Node *Built_Tree()
{

    int data;
    cout << "Enter Data : " << endl;
    cin >> data;

    if (data == -1)
        return nullptr;

    Node *root = new Node(data);

    cout << "Enter data you want to enter at left : " << data << endl;
    root->left = Built_Tree();

    cout << "Enter data you want to enter at right : " << data << endl;
    root->right = Built_Tree();

    return root;
}

void Built_From_Level_Order_Traversal(Node *&root)
{

    queue<Node*> q;

    int data;
    cout << "Enter data : ";
    cin >> data;

    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        int left;
        cout << "Enter left data : " << temp->val << endl;
        cin >> left;

        if (left != -1)
        {

            temp->left = new Node(left);
            q.push(temp);
        }

        int right;
        cout << "Enter right data : " << temp->val << endl;
        cin >> right;

        if (right != -1)
        {

            temp->right = new Node(right);
            q.push(temp);
        }
    }
}

void Level_Order_Traversal(Node *root)
{

    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;

            if (!q.empty())
                q.push(nullptr);
        }

        else
        {
            cout << " " << temp->val << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void Morris_Traversal(Node* root) {
    Node* current = root;
     
     // It uses the constant space
    while (current != nullptr) {
        // If there is no left child, print the current node and move to the right child
        if (current->left == nullptr) {
            std::cout << current->val << " ";
            current = current->right;
        } else {
            // Find the predecessor (rightmost node in the left subtree)
            Node* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            // If the right child of the predecessor is null, establish the temporary link
            if (predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            } else {
                // If the right child of the predecessor points to the current node, remove the temporary link
                predecessor->right = nullptr;
                std::cout << current->val << " ";
                current = current->right;
            }
        }
    }
}

void Pre_Order_Traversal(Node *root)
{

    if (root == nullptr)
        return;

    cout << root->val << " ";
    Pre_Order_Traversal(root->left);
    Pre_Order_Traversal(root->right);
}

void In_Order_Traversal(Node *root)
{

    if (root == nullptr)
        return;

    In_Order_Traversal(root->left);
    cout << root->val << " ";
    In_Order_Traversal(root->right);
}

void Post_Order_Traversal(Node *root)
{

    if (root == nullptr)
        return;

    Post_Order_Traversal(root->left);
    Post_Order_Traversal(root->right);
    cout << root->val << " ";
}

int main()
{

    Node *root = nullptr;
    Built_From_Level_Order_Traversal(root);
    //root = Built_Tree(); // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 -1

    cout << " LEVEL ORDER TRAVERSAL " << endl;
    Level_Order_Traversal(root);
    cout << endl;

    cout << " PRE ORDER TRAVERSAL ";
    Pre_Order_Traversal(root);
    cout << endl;

    cout << " POST ORDER TRAVERSAL ";
    Post_Order_Traversal(root);
    cout << endl;

    cout << " IN ORDER TRAVERSAL ";
    In_Order_Traversal(root);
    cout << endl;

    cout <<"MORRIS TRAVERSAL ";
    Morris_Traversal(root);
    
}