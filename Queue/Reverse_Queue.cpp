#include<iostream>
#include<queue>
using namespace std;

void reverse(queue<int>&q,int num){
   q.push(num);
}
void solve(queue<int>&q){

    if( q.empty() ) return;

    int num = q.front();
    q.pop();
    solve(q);

    reverse(q,num);
}

int main(){

    queue<int>q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    solve(q);

    while( !q.empty() ){

        cout << q.front() << " ";
        q.pop();
    }
}