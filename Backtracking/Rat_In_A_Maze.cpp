#include<iostream>
#include<vector>
using namespace std;

bool Check(vector<vector<bool>>&isVisited,int srcx,int srcy,int destination,vector<vector<int>>&maze){

    if(srcx>=0 && srcx < destination && srcy>=0 && srcy < destination &&  isVisited[srcx][srcy] == 0 &&  maze[srcx][srcy] == 1){
        return true;
    }
    return false;
}

void find(vector<string>&answer,vector<vector<int>>&maze,string &current,int srcx,int srcy,vector<vector<bool>>&isVisited,int destination){

    if(srcx == destination-1 && srcy == destination-1 ){
        answer.push_back(current);
        return;
    }


    isVisited[srcx][srcy] = true;

    int new1x = srcx-1;
    int new1y = srcy;
    if(Check(isVisited,new1x,new1y,destination,maze)){
        current.push_back('U');
        find(answer,maze,current,new1x,new1y,isVisited,destination);
        current.pop_back();
    }


    int new2x = srcx+1;
    int new2y = srcy;
    if(Check(isVisited,new2x,new2y,destination,maze)){
        current.push_back('D');
        find(answer,maze,current,new2x,new2y,isVisited,destination);
        current.pop_back();
    }

    int new3x = srcx;
    int new3y = srcy - 1;
    if(Check(isVisited,new3x,new3y,destination,maze)){
        current.push_back('L');
        find(answer,maze,current,new3x,new3y,isVisited,destination);
        current.pop_back();
    }


    int new4x = srcx;
    int new4y = srcy + 1;
    if(Check(isVisited,new4x,new4y,destination,maze)){
        current.push_back('R');
        find(answer,maze,current,new4x,new4y,isVisited,destination);
        current.pop_back();
    }


     isVisited[srcx][srcy] = false;

}
int main(){

    vector<string>answer;
    vector<vector<int>>maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    string current = "";
    int srcx = 0;
    int srcy = 0;
    int destination = 4; 
    
   vector<vector<bool>> isVisited (destination,vector<bool>(destination));


   for(int i=0; i<destination; i++){
    for(int j=0; j<destination; j++){
        isVisited[i][j] = false;
    }
   }

    find(answer,maze,current,srcx,srcy,isVisited,destination);

    cout << "Bactracking answer : " << endl ;
    for(string num : answer){
        cout << "PATH : ";
        cout << num << endl;
    }
}