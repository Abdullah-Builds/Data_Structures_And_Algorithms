#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = NULL;
    }
    Node() {}
};

class Graph {
public:
    Node** arr;
    int vertex;

    Graph(int s) {
        vertex = s;
        arr = new Node*[vertex];
        for (int j = 0; j < vertex; j++) {
            arr[j] = NULL;
        }
    }

    void addEdge(int v, int e, int direction) {
        Node* temp = new Node(e);
        temp->next = arr[v];
        arr[v] = temp;

        if (direction == 0) {
            temp = new Node(v);
            temp->next = arr[e];
            arr[e] = temp;
        }
    }

    void bfs(int start) {
        bool* visited = new bool[vertex] { false };
        int* queue = new int[vertex];
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        while (front < rear) {
            int current = queue[front++];
            cout << current << " ";

            Node* temp = arr[current];
            while (temp) {
                if (!visited[temp->val]) {
                    visited[temp->val] = true;
                    queue[rear++] = temp->val;
                }
                temp = temp->next;
            }
        }

        delete[] visited;
        delete[] queue;
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(2, 5, 0);
    g.addEdge(2, 6, 0);

    cout << "BFS Traversal starting from node 0: ";
    g.bfs(0);

    return 0;
}
