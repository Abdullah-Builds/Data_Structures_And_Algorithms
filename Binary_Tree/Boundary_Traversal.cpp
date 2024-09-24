/*Boundary traversal of a binary tree involves visiting the nodes in a specific order
             that includes the nodes on the boundary of the tree.

 * The traversal generally includes three main parts:

Left Boundary:  Traverse the nodes from the root to the leftmost leaf node,
                excluding the leaf nodes themselves.
Leaf Nodes:     Traverse all leaf nodes from left to right.
                These are the nodes that do not have any children.
Right Boundary: Traverse the nodes from the rightmost leaf node to the root,
                excluding the leaf nodes themselves. This part is traversed in 
                reverse order,so it’s typically done by first storing the nodes in a list 
                and then reversing the list before adding it to the final result*/


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
  

*/
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);                                
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    return root;
}

void Traversal_Left( Node* root, vector<int>&ans ){

    if( root == nullptr) return;
    if( root->left == nullptr && root->right == nullptr ) return;

    ans.push_back( root->val);
    if( root->left  ){   Traversal_Left(root->left,ans);}
    if( root->right ){  Traversal_Left(root->right,ans);}
    
}


void Traversal_Right( Node* root, vector<int>&ans ){

    if( root == nullptr) return;
    if( root->left == nullptr && root->right == nullptr ) return;

    if( root->left  ){ Traversal_Right(root->left,ans);}
    if( root->right ){ Traversal_Right(root->right,ans);}

    ans.push_back( root->val); 
    
}


void Traversal_Leaf_Nodes( Node* root, vector<int>&ans ){

    if( root == nullptr) return;
    if( root->left == nullptr && root->right == nullptr ) {
        ans.push_back( root->val);
    }

     Traversal_Leaf_Nodes(root->left,ans);
     Traversal_Leaf_Nodes(root->right,ans);

} 


int main(){

    vector<int>ans;
    Node* root = nullptr;
    root = Build_Tree();
    
    ans.push_back( root->val);

    Traversal_Left( root->left,ans );

    Traversal_Leaf_Nodes( root->left,ans);

    Traversal_Leaf_Nodes(root->right,ans);

    Traversal_Right( root->right, ans);


    for( int num : ans){
        cout << num << " ";
    }

}