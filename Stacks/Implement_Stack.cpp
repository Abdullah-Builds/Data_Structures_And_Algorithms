#include<iostream>
using namespace std;
class stack{
    int top;
    int size;
    int *arr;

    public:
    stack(int s){
        size = s;
        top = -1;
        arr = new int [size];
    }

    void push(int val){

        if( size - top > 1){
            top++;
            arr[top] = val;
        }
        else {
            cout << "Stack Overflow " << endl;
        }
    }

    void pop(){

        if( top != -1 ){
           top--;
        }
        else{

            cout << "Stack Underflow " << endl;
        }
    }

    int peek(){
        if( top !=- 1 ){
            return arr[top];
        }
        else{
            cout << "Stack is Empty " << endl;
        }
    }

    bool empty(){

        if ( top == -1) return false;
        return true;
    }
};

int main(){

    stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4); // overflow

    s.pop();
    s.pop();
    s.pop();
    s.pop(); //underflow
    s.peek();//empty
}