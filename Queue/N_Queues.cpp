#include <iostream>
#include<cstring>
using namespace std;

class queue
{

    int Num_of_Queue;
    int *front;
    int *rear;
    int *arr;
    int *next;
    int freespot;
    int Queue_Size;

public:
    queue(int num, int s)
    {
        Queue_Size = s;
        Num_of_Queue = num;
        front = new int[num];
        rear = new int[num];
        arr = new int[s];
        next = new int[s];
        freespot = 0;

        memset(front,-1,num*sizeof(int));
        memset(rear,-1,num*sizeof(int)); 

        for(int i=0; i<s-1; i++){
            next[i] = i+1; 
        }
        next[s-1] = -1;
    }

    void push( int val , int num ){

        if( freespot == -1 ){
            cout << "Queue Overflow " << endl;
        }    
        
        else{

            int index = freespot;
            freespot = next[index];  //updating the freespot position

            if( front[num-1] == -1 ) front[num-1] = index;  // checking if a stack is empty
            else next[rear[num-1]] = index;                 // linking next to queue i.e, if q1,q2,q1 and then link q1 to q1;

            rear[num-1] = index;     
            arr[index] = val;       //Assign value 
            next[index] = -1;       //Optionally step

        }
        }

        void pop( int num ){

           if( front[num-1] == -1 ){
            cout << "Queue Underflow " << endl;
           }

           else{

               int index = front[num-1];      //In queue pop starts from front
               front[num-1] = next[index];    //setting front to the next of index
               next[index] = freespot;        //Linking freespot  ( most Imp  step ) 
               freespot = index;              //i,e if pos 1 is popped and freespot at 3 then assign 3 at pos 1 
                                                           
           }
        }

        int Front( int num ){

            if( front[num-1] == -1  ){
            cout << "Queue Underflow " << endl;
            return -1;
           }
           else{
               return  arr[front[num-1]];
           }
        }

};

int main(){
   queue q(3,5);

   q.push(1,2);
   q.push(2,1);
   q.push(3,3);
   q.push(4,2);
   q.push(5,1);

   cout << " Top Element : " << q.Front(1) << endl;
   cout << " Top Element : " << q.Front(2) << endl;
   cout << " Top Element : " << q.Front(3) << endl;

   q.pop(2);
   q.pop(3);
   q.pop(1);

   cout << " Top Element : " << q.Front(1) << endl;
   cout << " Top Element : " << q.Front(2) << endl;
   cout << " Top Element : " << q.Front(3) << endl;

}