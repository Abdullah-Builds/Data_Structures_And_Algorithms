#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool Celebirity(vector<vector<int>>&celeb){

    stack<int>st;

    for(int i=0; i<celeb.size(); i++){
        st.push(i);
    }

    while( st.size( )>=2 ){

        int A = st.top();
        st.pop();

        int B = st.top();
        st.pop();
              
      // Suppose if person 1  knows 2 it is not a celebirity 
      //and hence person 1 cant be a celebirity so it is popped 

        if( celeb[A][B] == 1  ) st.push(B);

        else st.push(A);

    }

    int temp = st.top();  // May be the Celebirity (Potential Candidate)
    int row_count = 0;
    int col_count = 0;

    // Check  that it contains all zeros in rows and ones at columns ignoring the diagonal
    for(int i=0; i<celeb.size(); i++){

        if( celeb[temp][i] == 1 ) row_count++;

        if( celeb[i][temp] ) col_count++;
    }

    if( row_count == celeb.size()  && col_count == celeb.size()-1) return true;

    return false;
}

int main(){
                              // 1 2 3 4  
    vector<vector<int>>celeb = {{0,0,1,0},    //person 1
                                {0,0,1,0},    //person 2
                                {0,0,1,0},    //person 3
                                {0,0,0,0}};   //person 4

    //person 4 does not know 1,2,3 and hence whole row is zero and person 1,2,3 knows 4 indicated by 1

      bool found = Celebirity(celeb);

      if(found) cout << "The Given Matrix Is A Celebrity Matrix " << endl;

      else cout << "The Given Matrix Is Not A Celebrity Matrix" ;                     


}