#include <iostream>
#include <queue>
#include<vector>
using namespace std;

int solve(vector<int> &nums, int k)
{

     // simple logic of max sliding window of leetcode
     
    deque<int> Max(k);
    deque<int> Min(k);
    int sum = 0;

    for (int i = 0; i < k; i++)
    {

        //Logic to find Max and Min in array
        while (!Max.empty() && nums[Max.back()] <= nums[i])  Max.pop_back();

        while (!Min.empty() && nums[Min.back()] >= nums[i])  Min.pop_back();

        Max.push_back(i);

        Min.push_back(i);

    }

    sum += nums[Max.front()] + nums[Min.front()];

    for (int i = k; i < nums.size(); i++)
    {

        //Both loops Ensures that window cant be greater than k
        while (!Max.empty() && i - Max.front() >= k)  Max.pop_front();

        while (!Min.empty() && i - Min.front() >= k)  Min.pop_front();

        //Logic to find Max and Min in array
        while (!Max.empty() && nums[Max.back()] <= nums[i])  Max.pop_back();

        while (!Min.empty() && nums[Min.back()] >= nums[i])  Min.pop_back();

        Max.push_back(i);

        Min.push_back(i);

        sum += nums[Max.front()] + nums[Min.front()];

    }

    return sum;
}


int main(){

    vector<int>q = { 2,5,-1,7,-3,-1,-2};
    int k = 4;
    cout << solve(q,k) << endl;;
}