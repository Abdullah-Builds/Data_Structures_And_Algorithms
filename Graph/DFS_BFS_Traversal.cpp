#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
    int vertex;
    vector<vector<int>> adjList;

public:
    Graph(int v) : vertex(v)
    {
        adjList.resize(v);
    }

    void addEdge(int m, int n, bool direction)
    {
         /* n = number of nodes
           m = number of edges
           direction = 0  undirected
           direction = 1  directed  */

        adjList[m].push_back(n);

        if (direction == 0)
        {
            adjList[n].push_back(m);
        }
    }

    void bfs(int start)
    {
        cout << "\nBFS TRAVERSAL : \n";
        vector<bool> visited(vertex, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void dfsUtil(int node, vector<bool> &visited, vector<int> &result)
    {
        visited[node] = true;
        result.push_back(node);

        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                dfsUtil(neighbor, visited, result);
            }
        }
    }

    void dfs()
    {
        cout << "\nDFS TRAVERSAL :\n";
        vector<bool> visited(vertex, false);
        vector<int> result;

        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                dfsUtil(i, visited, result);
            }
        }

        for (int node : result)
        {
            cout << node << " ";
        }
    }

    void print()
    {
        for (int i = 0; i < vertex; i++)
        {
            cout << i << ": ";
            for (int neighbor : adjList[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(2, 5, 0);
    g.addEdge(2, 6, 0);

    g.print();
    g.bfs(0);
    g.dfs();

    return 0;
}