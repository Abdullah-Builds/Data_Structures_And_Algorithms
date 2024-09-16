#include<iostream>
using namespace std;
class queue{
    int qfront;
    int qrear;
    int size;
    int *arr;

    public:
    queue(int s){
        size = s;
        qrear = 0;
        qfront = 0;
        arr = new int [size];
    }

    void enqueue(int val){

        if( qrear == size-1){
            cout << "Queue Oveflow " << endl;
        }
        else{
            arr[qrear] = val;
            qrear++;
        }
    }

    void dequeue(){
        if(qrear == qfront){
            cout << "Queue is Empty ";
        }
        else{
            arr[qfront] = -1;
            qfront++;

            if (qfront == qrear){
                size = size - qfront;
                qfront = 0;
                qrear = 0;
            }
        }
    }

    int front(){

        if( qfront == qrear ){
            cout << "Queue is Empty ";
            return -1;
        }
        else{
            return arr[qfront];
        }
    }

    bool empty(){
        return qfront == qrear;
    }
};

int main(){

    queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    cout << "Top element : " << q.front() << endl;
}