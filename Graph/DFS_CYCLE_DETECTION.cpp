#include <iostream>
using namespace std;

class graph
{
private:
    int vertex;
    int edge;
    int **arr;

public:
    graph(int v)
    {
        vertex = v;
        edge = v - 1;
        arr = new int *[v];
        for (int i = 0; i < v; i++)
        {
            arr[i] = new int[v];
            for (int j = 0; j < v; j++)
            {
                arr[i][j] = 0;
            }
        }
    }

    void addEdge(int m, int n, bool direction)
    {

        /* n = number of nodes
           m = number of edges
           direction = 0  undirected
           direction = 1  directed  */

        arr[m][n] = 1;
        if (direction == 0)
        {
            arr[n][m] = 1;
        }
    }

    void find(int &node, bool *visited, int &index, int *ans, int parent, bool &cycleDetected)
    {
        visited[node] = true;
        ans[index++] = node;

        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i] && arr[node][i] == 1)
            {
                find(i, visited, index, ans, node, cycleDetected);
            }
            else if (i != parent)
            {
                cycleDetected = true;
            }
        }
    }
    void dfs()
    {
        cout << endl
             << "DFS TRAVERSAL CYCLE DETECTION :" << endl;

        bool *visited = new bool[vertex];
        int parent = -1;
        int *ans = new int[vertex];
        int index = 0;
        bool cycleDetected = false;

        for (int i = 0; i < vertex; i++)
        {
            visited[i] = false;
        }

        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                find(i, visited, index, ans, parent, cycleDetected);
            }
        }
        for (int i = 0; i < vertex; i++)
        {
            cout << ans[i] << " ";
        }
        if (cycleDetected)
        {
            cout << endl
                 << "Cycle detected in the graph!" << endl;
        }
        else
        {
            cout << endl
                 << "No cycle detected in the graph!" << endl;
        }
        delete[] visited;
        delete[] ans;
    }

    ~graph()
    {
        for (int i = 0; i < vertex; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
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
