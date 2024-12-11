#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
public:
    int vertex;
    vector<vector<int>> mat;

    Graph(int v)
    {
        vertex = v;
        mat.resize(v, vector<int>(v, 0));
    }

    void addEdge(int u, int v)
    {
        mat[u][v] = 1; // Directed edge from u to v
    }

    bool bfsCycleDetection()
    {
        vector<int> inDegree(vertex, 0);

        // Step 1: Calculate in-degree of each vertex
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                if (mat[i][j] == 1)
                    inDegree[j]++;
            }
        }

        // Step 2: Initialize the queue with vertices having in-degree 0
        queue<int> q;
        for (int i = 0; i < vertex; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        // Step 3: Process the vertices
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            // Decrease in-degree of adjacent vertices
            for (int i = 0; i < vertex; i++)
            {
                if (mat[node][i] == 1)
                {
                    inDegree[i]--;
                    if (inDegree[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }

        // Step 4: If count of processed nodes is less than the total vertices, cycle exists
        if (count != vertex)
        {
            cout << "Cycle Found!" << endl;
            return true;
        }
        else
        {
            cout << "Cycle Not Found!" << endl;
            return false;
        }
    }

    void printGraph()
    {
        for (int i = 0; i < mat.size(); i++)
        {
            cout << i << " -> ";
            for (int j = 0; j < mat[i].size(); j++)
            {
                cout << mat[i][j] << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(3);
    int Node = 3;
    int u, v;
    for (int i = 0; i < Node; i++)
    {
        cout << "Enter Edge and vertex" << endl;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.printGraph();
    g.bfsCycleDetection();
}
