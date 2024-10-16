#include<iostream>
using namespace std;

void print(string curr){

    curr[0] -= 32;
    for(int i=0; i<curr.size(); i++){
        cout << curr[i];
    }
    curr[0] += 32;
    
    cout << endl;
    curr[curr.size()-1] -= 32;
    for(int i=0; i<curr.size(); i++){
        cout << curr[i];
    }

    cout << endl;
}

void combinations(string nums, int index, string curr, int k){

    if(curr.length() == k){
        print(curr);
        return;
    }

    for(int i=index; i<nums.length(); i++){
        curr.push_back(nums[i]);
        combinations(nums,i+1,curr,k);
        curr.pop_back();
    }

}
int main(){
   string nums = "abc";
   string curr;
   int index = 0;
   int k = 2;
   combinations(nums,index,curr, k);

}