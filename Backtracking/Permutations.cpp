#include<iostream>
#include<string>
using namespace std;

int r = 0;
int c = 0;
void add2d( string arr[2][2], string curr[], int n){

   for(int i=0; i<n; i++){
      arr[r][c++] = curr[i];
   }
   r++;
   c=0;
}

int j=0;
void permutation(string arr[2][2], string curr[], bool isVisited[], string nums[], int n ){

     if (j == n ){
        add2d( arr, curr, n);
        return;
     }

     for(int i=0; i<n; i++){
        if ( !isVisited[i] ){
            isVisited[i] = true;
            curr[j++]  = nums[i];
            
            permutation(arr,curr,isVisited,nums,n);
            isVisited[i] = false;
            curr[j--];
        }
     }
}

int main(){

    string nums[] = {"a","b"};
    string arr[2][2];
    bool isVisited[2] = {false};
    string curr[2] = {};
    permutation(arr,curr,isVisited,nums,2);
    
    int k=0;
    string str;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            if( i==0 && j==0 || i==1 && j==0)  arr[i][j] =  (char)(arr[i][j][0])-32;
            cout << arr[i][j];
        }
        cout << endl;
    }
}