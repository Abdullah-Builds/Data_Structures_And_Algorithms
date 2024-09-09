#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* prev;
    Node* next;

    Node(int v){

      value = v;
      prev = nullptr;
      next = nullptr;

    }
};

void Insert_Tail(Node* &head,int val){

    Node* temp = new Node(val);
    Node* ptr = head;

    while(ptr->next != nullptr){
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr->next;
    temp->next = nullptr;
}

void Insert_Head(Node* &head,int val){

    Node* temp = new Node(val);

    temp->next = head;
    head->prev = temp;
    head = temp;
   
}


void Insert_Position(Node* &head, int pos,int val){

    if(head == nullptr){
        cout << "Empty Linked List"  << endl;
    }

    else if(pos == 0){

        Insert_Head(head,val);
        return;
    }

    Node* ptr  = head;
    for(int i=1; i<pos; i++){
          ptr = ptr->next;
    }

    if(ptr == nullptr ){

        cout << "Out Of Bound" << endl;
        return;
    }

    Node* temp = new Node(val);

    Node* p = ptr->next;
    ptr->next = temp;
    temp->next = p;
    temp->prev = ptr->next; 

}

void Delete_Position(Node* &head, int pos){

    if(head == nullptr || pos < 0) {
        
        cout << "No Element Present" << endl;
        return;
    }

   if(pos == 0){
      head = head->next;
      return;
   }

   Node* temp = head;
   for(int i=1; i<pos; i++){
    temp = temp->next;
   }

   if(temp == nullptr || temp->next == nullptr) {
    cout << "Out Of Bound " << endl;
    return;
   }

   Node* curr = temp->next;
   Node* prev = temp;

   prev->next = curr->next;

   temp = nullptr;
   delete curr;
   delete prev;
}

void print(Node* head){

    Node* temp = head;
    while(temp != nullptr){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl << endl;
}

int main() {

    Node* node = new Node(10);
    Node* head = node;

    Insert_Head(head,100);
    print(head);

    Insert_Head(head,200);
    print(head);

    Insert_Tail(head,100);
    print(head);

    Insert_Position(head,3,300);
    print(head);

   Delete_Position(head,0);
   print(head);

   Delete_Position(head,3);
   print(head);
}