#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <list>
#include<algorithm>

using namespace std;

class graph
{
public:
    int vertex;
    unordered_map<int, list<int>> adj;

    graph(int v){
        vertex = v;

    }
    void addEdge(int m, int n, bool direction)
    {
        /* n = number of nodes
           m = number of edges
           direction = 0  undirected
           direction = 1  directed  */

        adj[n].push_back(m);

        if (direction == 0)
        {
            adj[m].push_back(n);
        }
    }
    void dfs(int node, stack<int> &s, vector<bool> &visited)
    {   
        visited[node] = true;
        s.push(node);
        for (int i : adj[node])
        {
            if (!visited[i])
                dfs(i, s, visited);
        }
    }
    void Topo_Sort()
    {
        vector<bool> visited(vertex, false);
        stack<int> s;
        vector<int> ans;
        for (int i = 0; i <vertex; i++)
        {
            if (!visited[i])
                dfs(i, s, visited);
        }
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
         reverse(ans.begin(),ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    void PrintGraph()
    {

        for (auto Node : adj)
        {
            cout << Node.first << " -> ";
            for (auto Edges : Node.second)
            {
                cout << Edges << " , ";
            }
            cout << endl;
        }
    }
};
int main()
{
    graph g(3);
    int Node = 3;
    int Edge = 3;
    int u, v;
    for (int i = 0; i < Node; i++)
    {
        cout << "Enter Edge and vertex" << endl;

        cin >> u;
        cin >> v;
        g.addEdge(u, v, 1);
    }
    g.PrintGraph();
    cout << endl;
    g.Topo_Sort();
}
