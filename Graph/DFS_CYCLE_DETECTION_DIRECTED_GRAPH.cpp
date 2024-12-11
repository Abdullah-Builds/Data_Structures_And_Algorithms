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
    vector<vector<int>> mat;

    graph(int v)
    {
        vertex = v;
        mat.resize(v, vector<int>(v, 0));
    }
    void addEdge(int u, int v, int direction)
    {
        mat[u][v] = 1;

        if (direction == 0)
        {
            mat[v][u] = 1;
        }
    }
    void dfsUtil(int node, vector<bool> &visited, vector<bool> &dfsCall, bool &CycleDetected)
    {
        visited[node] = true;
        dfsCall[node] = true;

        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i] && mat[node][i] == 1)
                dfsUtil(i, visited, dfsCall, CycleDetected);

            else if (dfsCall[i] == true && mat[node][i] == 1)
            {
                CycleDetected = true;
                return;
            }
        }
        dfsCall[node] = false;
    }
    void dfs()
    {
        vector<bool> visited(vertex, false);
        vector<bool> dfsCall(vertex, false);
        bool CycleDetected = false;

        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                dfsUtil(i, visited, dfsCall, CycleDetected);
            }
            if (CycleDetected)
                break;
        }
        if (CycleDetected)
        {
            cout << "Cycle Found : " << endl;
        }
        else
        {
            cout << "Cycle Not  Found : " << endl;
        }
        
    }
    void PrintGraph()
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
    g.dfs();
}