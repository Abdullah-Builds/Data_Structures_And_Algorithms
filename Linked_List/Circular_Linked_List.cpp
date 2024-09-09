#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;

    Node(int v){

      value = v;
      next = nullptr;

    }
};

void Insert_pos(Node* &head,int pos, int val){

     if (head == nullptr) {  // If the list is empty, create the first node
        head = new Node(val);
        head->next = head;
        return;
    }
    
     if(pos == 0){  // Starting Node
        Node* temp = new Node(val);
        Node* ptr = head;

        while(ptr->next != head ){
            ptr = ptr->next;
        }

        temp->next = head;
        ptr->next = temp;
        head = temp;
    }

    else{ // Middle and End case

        Node* temp = new Node(val);
        Node* ptr = head;

        for(int i=0; i<pos && ptr->next != head; i++){
            ptr = ptr->next;
        }

        temp->next = ptr->next;
        ptr->next = temp;
       
    }
}


void Delete_pos(Node* &head, int pos){

    if(pos < 0 || head == nullptr){
        cout << "Invald" << endl;
    }

    else if(pos == 0){
    
        Node* ptr = head;

        while(ptr->next != head){
            ptr = ptr->next;
        }

        // If there is only one node in the list
        if (ptr == head) {
            delete head;
            head = nullptr;
            return;
        }

        ptr->next = head->next;
        head = head->next;
    }

    else{
        Node* ptr = head;

        for(int i=1; i< pos && ptr->next != head; i++){

            ptr = ptr->next;
        }

        if(ptr->next == head){

            cout << "Invalid" << endl;
            return;
        }

        Node* temp = ptr->next;
        ptr->next = temp->next;

        delete temp;
        
    }
}


void print(Node* head){

    Node* temp = head;

   
    do {   // If we use while loop last element will not print

        cout << temp->value << "->";
        temp = temp->next;

    } while (temp != head);

    cout << endl << endl;
}
int main(){

    Node* head = new Node(10);
    head->next = head;
    print(head);

    Insert_pos(head,1,100);
    print(head);

    Insert_pos(head,2,200);
    print(head);

    
    Insert_pos(head,3,300);
    print(head);
     
    Insert_pos(head,4,400);
    print(head);

    Delete_pos(head,4);
    print(head);
    
}

  


