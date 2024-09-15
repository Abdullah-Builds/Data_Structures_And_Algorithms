//Level : Hard

#include<iostream>
#include<stack>
#include <cstring> 

using namespace std;

class Stack{
private:

  int size;
  int num_of_stack;
  int freespot;
  int *arr;
  int *next;
  int *top;

  public: 
  Stack(int s, int k){
    size = s;
    num_of_stack = k;
    freespot = 0;
    arr = new int[size];
    next = new int[size];
    top = new int [num_of_stack];

    for(int i=0; i<size-1; i++){
        next[i] = i+1;
    }
    next[size-1] = -1;

     memset(top, -1, num_of_stack * sizeof(int));
  }
  
  void push(int N,int val){
    
    if(freespot == -1){
        cout << "Stack Overflow" << endl;
    }
    else{

        int index = freespot;
        freespot = next[index];
        arr[index] = val;
        next[index] = top[N - 1];
        top[N-1] = index;
    }
  }

 void pop(int N){
    
    if(top[N-1] == -1){
        cout << "Stack Underflow" << endl;
    }
    else{

        int index = top[N-1];
        top[N-1] = next[index] ;
        next[index] = freespot;
        freespot = index;
    
    }
  }

  void update(int N,int val){
    
    if(top[N-1] == -1 ){
        cout << "Stack Underflow" << endl;
    }
    else{

        int index = top[N-1] ;
        arr[index] = val;
        
    }
  }

  int topElement(int N){

    if(top[N-1] == -1){
        return -1;
    }
    return arr[top[N-1]];;
  }
};


int main(){

        Stack stacks(5,3);
        stacks.push(1, 10);
        stacks.push(2, 20);
        stacks.push(3, 30);
        

        cout << "Top element of stack 1: " << stacks.topElement(1) << std::endl;
        cout << "Top element of stack 2: " << stacks.topElement(2) << std::endl;
        cout << "Top element of stack 3: " << stacks.topElement(3) << std::endl;


        stacks.pop(3);
        stacks.pop(1);
        stacks.pop(2);

        cout << "Top element of stack 1: " << stacks.topElement(1) << std::endl;
        cout << "Top element of stack 2: " << stacks.topElement(2) << std::endl;
        cout << "Top element of stack 3: " << stacks.topElement(3) << std::endl;
         
       
       


}