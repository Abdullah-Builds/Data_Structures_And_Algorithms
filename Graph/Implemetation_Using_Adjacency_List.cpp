#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class graph{
  public:
  unordered_map<int,list<int>> adj;

  void addEdge(int m , int n , bool direction){
    /* n = number of nodes
       m = number of edges
       direction = 0  undirected
       direction = 1  directed  */

       adj[n].push_back(m);

       if( direction == 0){
         adj[m].push_back(n);
       }
  }

  void PrintGraph(){

    for( auto Node : adj ){
        cout << Node.first << " -> " ;
        for( auto Edges : Node.second ){
            cout << Edges << " , ";
        }
        cout << endl;
    }
  }
};

int main(){
    graph g;
                                                            /*      0 --- 1
                                                                     \    
                                                                      \   |
                                                                       \       
                                                                        \ 2
                                                                         */
    int Node = 3;
    int Edge = 3;

    for(int i=0; i< Node; i++){
         int u , v;                // u = 0 , 1, 2
         cin >> u >> v;            // v = ( 0 to 1 and 2 ) and so on
         g.addEdge(u,v,0);
    }
    
    g.PrintGraph();

}
