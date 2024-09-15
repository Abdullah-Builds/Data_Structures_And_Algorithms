#include<iostream>
#include<stack>
using namespace std;

void Delete(stack<int>&s,int count,int size){

    if( count == size/2){
        s.pop();
        return;
    }

    int store = s.top();
    s.pop();

    Delete(s,count+1,size);
    s.push(store);
}


int main(){

    stack<int>s;

    for(int i=0; i<5; i++){
        s.push(i+1);
    }
     
    int size = s.size(); 
    Delete(s,0,size);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}