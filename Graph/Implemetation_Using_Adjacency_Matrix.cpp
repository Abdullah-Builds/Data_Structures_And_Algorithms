#include<iostream>
#include<vector>
using namespace std;

class graph{
  public:
  vector<vector<int>> adj;

  graph(int r , int c){
    adj.resize(r, vector<int>(c, 0));
  }

  void addEdge(int m , int n , bool direction){
    /* n = number of nodes
       m = number of edges
       direction = 0  undirected
       direction = 1  directed  */

       adj[n][m] = 1;

       if( direction == 0){
         adj[m][n] = 1;
       }
  }

  void PrintGraph(){

     for(int i=0; i<adj.size(); i++){
           cout << i << " -> ";
       for(int j=0; j<adj[i].size(); j++){
             if( adj[i][j] == 1){
            cout << j << " , ";
          }
       }
       cout << endl;
     }
  }
};

int main(){

    int Node = 3;
    int Edge = 3;
    graph g(Node,Edge);
                                                            /*      0 --- 1
                                                                     \    
                                                                      \   |
                                                                       \       
                                                                        \ 2
                                                                         */


    for(int i=0; i<Node; i++){
         int u , v;                // u = 0 , 1, 2
         cin >> u >> v;            // v = ( 0 to 1 and 2 ) and so on
         g.addEdge(u,v,0);
      }
    
    g.PrintGraph();

}
