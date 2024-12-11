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

    void bfsCycleDetection(int start)
    {
        cout << endl
             << "BFS TRAVERSAL WITH CYCLE DETECTION: " << endl;

        bool *visited = new bool[vertex];
        for (int i = 0; i < vertex; i++)
        {
            visited[i] = false;
        }

        int *queue = new int[vertex];
        int *parent = new int[vertex]; // Array to track parent of each node
        int front = 0, rear = 0;

        // Initialize parents as -1 (no parent)
        for (int i = 0; i < vertex; i++)
        {
            parent[i] = -1;
        }

        // A flag to indicate if a cycle is detected
        bool cycleDetected = false;

        visited[start] = true;
        queue[rear++] = start;

        while (front < rear)
        {
            int node = queue[front++];
            cout << node << " ";
            for (int i = 0; i < vertex; i++)
            {
                if (arr[node][i] == 1) // Edge exists
                {
                    if (!visited[i])
                    {
                        visited[i] = true;
                        parent[i] = node; // Mark current node as parent
                        queue[rear++] = i;
                    }
                    else if (parent[node] != i && visited[i])
                    {
                        // If visited and not the parent, a cycle is detected
                        cycleDetected = true;
                    }
                }
            }
        }

        delete[] visited;
        delete[] queue;
        delete[] parent;

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
    graph g(5);
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 2, 0);
   
    g.bfsCycleDetection(0);

    return 0;
}
