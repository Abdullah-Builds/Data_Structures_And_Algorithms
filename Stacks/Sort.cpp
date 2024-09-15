#include<iostream>
#include<stack>
using namespace std;

void sort(stack<int>&s,int num){

    if(s.empty() || s.top() < num){
        s.push(num);
        return;
    }

    int store = s.top();
    s.pop();

    sort(s,num);
    s.push(store);
}

void solve(stack<int>&s){

    if(s.empty()) return;

    int store = s.top();
    s.pop();

    solve(s);
    sort(s,store);
}


int main(){

    stack<int>s;

    s.push(2);
    s.push(-9);
    s.push(10);
    s.push(8);
    s.push(-5);

    solve(s);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}