#include <iostream>
#include <vector>
using namespace std;

class graph
{
private:
    int vertex;
    vector<vector<int>> adj;

public:
    graph(int v)
    {
        vertex = v;
        adj.resize(v, vector<int>(v, 0));  
    }

    void addEdge(int m, int n, bool direction)
    {
        /* m = source node, n = destination node
           direction = 0  undirected
           direction = 1  directed */

        adj[m][n] = 1;
        if (direction == 0)
        {
            adj[n][m] = 1;
        }
    }

    void dfsUtil(int node, vector<bool>& visited, vector<int>& ans, int parent, bool& cycleDetected)
    {
        visited[node] = true;
        ans.push_back(node);

        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i] && adj[node][i] == 1)
            {
                dfsUtil(i, visited, ans, node, cycleDetected);
            }
            else if (i != parent && adj[node][i] == 1)
            {
                cycleDetected = true;  
                // If we find a visited node that's not the parent, cycle detected
            }
        }
    }

    void dfs()
    {
        cout << "\nDFS TRAVERSAL CYCLE DETECTION :" << endl;

        vector<bool> visited(vertex, false);
        vector<int> ans;
        bool cycleDetected = false;

        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                dfsUtil(i, visited, ans, -1, cycleDetected);
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }

        if (cycleDetected)
        {
            cout << "\nCycle detected in the graph!" << endl;
        }
        else
        {
            cout << "\nNo cycle detected in the graph!" << endl;
        }
    }
};

int main()
{
    graph g(4);
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 3, 0);
    g.dfs();

    return 0;
}
