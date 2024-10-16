#include<iostream>
using namespace std;

void print( string ans ){
     cout << ans << endl;
}
void solve(string nums, string ans, int index){

    if( nums.length() == index){
        print(ans);
        return;
    }

    ans.push_back(nums[index]);
    solve(nums,ans,index+1);

    ans.pop_back();
    solve(nums,ans,index+1);
}

int main(){
    string nums = "123";
    string ans;
    int index = 0;

    solve(nums,ans,index);
}