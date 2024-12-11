#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <list>

using namespace std;
class graph
{
public:
    int vertex;
    unordered_map<int, list<int>> adj;

    graph(int v ){
        vertex = v;
    }
    void addEdge(int u, int v, int direction)
    {
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void bfs()
    {
        queue<int> q;
        vector<int> ans;
        vector<int> indegree(vertex,0);

        // calculate indegree
         for (auto &node : adj)
        {
            for (int neighbor : node.second)
            {
                indegree[neighbor]++;
            }
        }

        // If indegree is zero push into queue
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        // do BFS

        while (!q.empty())
        {
            int front = q.front();
            ans.push_back(front);
            q.pop();

            for (int i :  adj[front])
            {
                indegree[i]--;

                if (indegree[i] == 0)
                    q.push(i);
            }
        }

        for(int i=0; i<ans.size(); i++){
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
    g.bfs();
}