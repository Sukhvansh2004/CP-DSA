#include <iostream>
#include <cmath>
using namespace std;

class heap {
public:
    pair<int, int> *arr;
    int heapsize = 0;
    int capacity = 1;

    heap() {
        this->arr = new pair<int, int>[capacity];
    }

    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }
    int parent(int i) {
        return ceil(float(i) / 2.0) - 1;
    }

    void heapify(int i) {
        int minimum = i;
        if (left(minimum) < heapsize && arr[left(minimum)].first < arr[minimum].first) {
            minimum = left(minimum);
        }
        if (right(minimum) < heapsize && arr[right(minimum)].first < arr[minimum].first) {
            minimum = right(minimum);
        }
        if (minimum != i) {
            swap(arr[minimum], arr[i]);
            heapify(minimum);
        }
    }

    void decreaseKey(int i, int val) {
        if (arr[i].first < val) {
            return;
        }
        arr[i].first = val;
        while (arr[i].first < arr[parent(i)].first && i > 0) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void insertKey(int key) {
     if (heapsize == capacity) {
         pair<int, int> *temp = new pair<int, int>[2 * capacity];
         capacity = 2 * capacity;
         for (int i = 0; i < heapsize; i++) {
             temp[i] = arr[i];
         }
         temp[heapsize++] = make_pair(INT_MAX, key);
         delete[] arr;
         this->arr = temp;
        } else {
             arr[heapsize++] = make_pair(INT_MAX, key);
          }
    }


    pair<int, int> extractMin() {
        pair<int, int> t = arr[0];
        arr[0].first = INT_MAX;
        heapify(0);
        return t;
    }

    int index(int val) {
        for (int i = 0; i < heapsize; i++) {
            if (arr[i].second == val) {
                return i;
            }
        }
        return -1;
    }
};

class Node {
public:
    int data;
    int key;
    int parent;
};

class Graph {
public:
    pair<Node, heap> *adj;
    int elements;
    int maxe;
    Graph(int n) {
        this->maxe = n;
        this->adj = new pair<Node, heap>[maxe];
        this->elements = 0;
    }

    void addVertex(int u) {
        if (elements < maxe) {
            Node t;
            t.data = u;
            adj[elements++].first = t;
        }
    }

    void addEdge(int u, int v, int w) {
        int index1 = search(u);
        int index2 = search(v);
        adj[index1].second.insertKey(w);
        adj[index2].second.insertKey(w);
    }

    int search(int u) {
        for (int i = 0; i < elements; i++) {
            if (adj[i].first.data == u) {
                return i;
            }
        }
        return -1;
    }

    void print() {
        for (int i = 0; i < elements; i++) {
            if (adj[i].first.parent != -1) {
                cout << "Data: " << adj[i].first.data << " " << "Key: " << adj[i].first.key << " " << "Parent: " << adj[i].first.parent << endl;
            } else {
                cout << "Data: " << adj[i].first.data << " " << "Key: " << adj[i].first.key << " " << "Parent: None" << endl;
            }
        }
    }
};

void dijkstra(Graph& G, int src) {
    heap queue;
    for (int i = 0; i < G.elements; i++) {
        G.adj[i].first.key = INT_MAX;
        G.adj[i].first.parent = -1;
        queue.insertKey(G.adj[i].first.data);
    }
    int index = G.search(src);
    int iq = queue.index(src);
    queue.decreaseKey(iq, 0);
    G.adj[index].first.key = 0;
    while (true) {
        pair<int, int> var = queue.extractMin();
        if (var.first == INT_MAX) {
            break;
        }
        int gindex = G.search(var.second);
        heap v = G.adj[gindex].second;
        for (int i = 0; i < v.heapsize; i++) {
            int weight = v.arr[i].first;
            int vertex = v.arr[i].second;
            int j = G.search(vertex);
            if (G.adj[j].first.key > weight + G.adj[gindex].first.key) {
                G.adj[j].first.key = weight + G.adj[gindex].first.key;
                G.adj[j].first.parent = G.adj[gindex].first.data;
                int qs = queue.index(vertex);
                queue.decreaseKey(qs, G.adj[j].first.key);
            }
        }
    }
}

int main() {
    Graph G(4);
    G.addVertex(1);
    G.addVertex(2);
    G.addVertex(3);
    G.addVertex(4);

    G.addEdge(1, 2, 1);
    G.addEdge(2, 4, 2);

    G.addEdge(1, 3, 4);
    G.addEdge(3, 4, 1);

    dijkstra(G, 1);

    G.print();

    return 0;
}
