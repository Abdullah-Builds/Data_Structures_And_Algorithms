#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node *next;


    Node(int val){

        value = val;
        next = nullptr;
    }

};
    void Insert_Head(Node *&head ,int val){

        Node *temp = new Node (val);
        temp->next =  head;
        head = temp; ;
    }
    
    void Insert_Tail(Node *&head ,int val){

        Node *temp = new Node (val);
        Node *node = head;

        while(node->next != nullptr){
            node = node->next;
        }
        node->next = temp;
    }

    void print(Node* &head){

         Node *temp = head;
         while (temp != nullptr)
         {
            cout <<  temp->value << " " ;
            temp = temp->next;
         }
         temp = nullptr;
         cout << endl << endl;
    }

   void Insert_Position(Node* &head, int value,int pos){

       if(pos == 1){
        Insert_Head(head,value);
        return;
       }

       else if(pos == 3){
          Insert_Tail(head,value);
          return;
       }
       
       else{

        Node* temp = head;
        int cnt = 1;

        while(cnt < pos-1){
            temp = temp->next;
            cnt++;
        }
        
        //Edge Case : 
        if(temp == nullptr){
            cout << "Out of Bound " << endl;
            return;
        }

        Node* To_Insert = new Node (value);

        To_Insert->next = temp->next;
        temp->next = To_Insert;
        
       }
   }

      void Delete_Position(Node* &head , int pos){
          
          //Edge Case : It is possible that no element is Presnet in Node; 
          if(head == nullptr){
            cout << "No Element Present to be Deleted" << endl;
            return;
          }
          
          //First Position
          else if(pos == 1){
            head = head->next;
            return;
          }

          //Handling both middle and last elements
          else {

          Node *temp = head;
          int cnt = 1;

          while(temp!= nullptr &&  cnt < pos -1 ){
            temp = temp->next;
            cnt++;
          }

          // Edge case : It is possible that position given is not valid
          if(temp == nullptr || temp->next == nullptr){
            cout << "Out Of Bound" << endl;
          }
          
          Node *nodeToDelete = temp->next;
          temp->next = nodeToDelete->next;

          delete nodeToDelete;
          
          temp->next = nullptr;
          delete temp;
          
          }
   }
int main(){

    Node *node1 = new Node(10);
    Node *head_node2 = node1;
  
    Insert_Head(head_node2,100);
    print(head_node2);

    
    Insert_Tail(head_node2,200);
    print(head_node2);

    Insert_Position(head_node2,87,2);
    print(head_node2);

    Delete_Position(head_node2,4);
    print(head_node2);

}