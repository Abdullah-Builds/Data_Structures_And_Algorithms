#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int vertex;
    vector<vector<int>> adjMatrix;

public:
    Graph(int v) : vertex(v), adjMatrix(v, vector<int>(v, 0)) {}

    void addEdge(int m, int n, bool direction) {
        /*
        n = number of nodes
        m = number of edges
        direction = 0  undirected
        direction = 1  directed
        */
        adjMatrix[m][n] = 1;
        if (direction == 0) {
            adjMatrix[n][m] = 1;
        }
    }

    void bfsCycleDetection(int start) {
        cout << endl << "BFS TRAVERSAL WITH CYCLE DETECTION: " << endl;

        vector<bool> visited(vertex, false);
        vector<int> parent(vertex, -1);
        queue<int> q;
        bool cycleDetected = false;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < vertex; i++) {
                if (adjMatrix[node][i] == 1) { // Edge exists
                    if (!visited[i]) {
                        visited[i] = true;
                        parent[i] = node; // Mark current node as parent
                        q.push(i);
                    } else if (parent[node] != i) {
                        // If visited and not the parent, a cycle is detected
                        cycleDetected = true;
                    }
                }
            }
        }

        if (cycleDetected) {
            cout << endl << "Cycle detected in the graph!" << endl;
        } else {
            cout << endl << "No cycle detected in the graph!" << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 2, 0);

    g.bfsCycleDetection(0);

    return 0;
}
