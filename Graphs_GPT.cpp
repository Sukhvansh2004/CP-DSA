#include <iostream>

using namespace std;

const int MAXN = 100; 

struct Node {
    int data;
    Node* next;
};

class Graph {
public:
    Node* vertices[MAXN];
    int num_vertices;
    Graph() {
        for (int i = 0; i < MAXN; i++) {
            vertices[i] = nullptr;
        }
        num_vertices = 0;
    }

    void add_vertex(int v) {
        if (num_vertices < MAXN) {
            Node* new_node = new Node;
            new_node->data = v;
            new_node->next = nullptr;
            vertices[num_vertices++] = new_node;
        } else {
            cerr << "Graph has reached maximum capacity." << endl;
        }
    }

    void add_edge(int u, int v) {
        Node* new_node = new Node;
        new_node->data = v;
        new_node->next = vertices[u];
        vertices[u] = new_node;
    }

    void print() {
        for (int i = 0; i < num_vertices; i++) {
            cout << "Vertex " << i << ": ";
            Node* cur_node = vertices[i];
            while (cur_node != nullptr) {
                cout << cur_node->data << " ";
                cur_node = cur_node->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    g.add_edge(3, 4);

    g.print();

    return 0;
}
