#include<iostream>
using namespace std;

class graph {
private:
    int vertex;
    int edge;
    int** arr;

public:
    graph(int v, int e) {
        vertex = v;
        edge = e;
        arr = new int*[v];
        for (int i = 0; i < v; i++) {
            arr[i] = new int[v];
            for (int j = 0; j < v; j++) {
                arr[i][j] = 0;
            }
        }
    }

    void addEdge(int m, int n, bool direction) {

    /* n = number of nodes
       m = number of edges
       direction = 0  undirected
       direction = 1  directed  */

        arr[m][n] = 1;
        if (direction == 0) {
            arr[n][m] = 1;
        }
    }

    void bfs(int start) {
         cout <<  endl << "BFS TRAVERSAL : " << endl;
        bool* visited = new bool[vertex];
        for (int i = 0; i < vertex; i++) {
            visited[i] = false;
        }

        int* queue = new int[vertex];
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        while (front < rear) {
            int node = queue[front++];
            cout << node << " ";
            for (int i = 0; i < vertex; i++) {
                if (arr[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }

        delete[] visited;
        delete[] queue;
    }

    void print() {

        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~graph() {
        for (int i = 0; i < vertex; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

int main() {

    graph g(5, 6);
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.print();
    g.bfs(0);

}
