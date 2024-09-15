#include<iostream>
#include<stack>
using namespace std;

void Insert_Bottom(stack<int>&s, int num){

    if(s.empty()){
        s.push(num);
        return;
    }

    int store = s.top();
    s.pop();

    Insert_Bottom(s,num);

    s.push(store);
}

void Reverse(stack<int>&s){

    if(s.empty()){
        return;
    }

    int store = s.top();
    s.pop();

    Reverse(s);

    Insert_Bottom(s,store);
}

int main(){

    stack<int>s;

    for(int i=0; i<5; i++){
        s.push(i+1);
    }

    Reverse(s);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}

