#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

class Node {
public:
    int value;
    Node **forward;
    Node(int level, int &value) {
        this->value = value;
        forward = new Node*[level+1];
        memset(forward, 0, sizeof(Node*)*(level+1));
    }
    ~Node() {
        delete [] forward;
    }
};

class SkipList {
public:
    int MAX_LEVEL;
    float P;
    int level;
    Node *header;
    SkipList(int MAX_LEVEL, float P) {
        this->MAX_LEVEL = MAX_LEVEL;
        this->P = P;
        level = 0;
        header = new Node(MAX_LEVEL, *(new int(-1)));
    }
    ~SkipList() {
        delete header;
    }
    int randomLevel() {
        float r = (float)rand()/RAND_MAX;
        int lvl = 0;
        while (r < P && lvl < MAX_LEVEL) {
            lvl++;
            r = (float)rand()/RAND_MAX;
        }
        return lvl;
    }
    void insertElement(int &value) {
        Node *current = header;
        Node *update[MAX_LEVEL+1];
        memset(update, 0, sizeof(Node*)*(MAX_LEVEL+1));
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != NULL && current->forward[i]->value < value) {
                current = current->forward[i];
            }
            update[i] = current;
        }
        current = current->forward[0];
        if (current == NULL || current->value != value) {
            int rlevel = randomLevel();
            if (rlevel > level) {
                for (int i = level+1; i < rlevel+1; i++) {
                    update[i] = header;
                }
                level = rlevel;
            }
            Node *n = new Node(rlevel, value);
            for (int i = 0; i <= rlevel; i++) {
                n->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = n;
            }
        }
    }
    void printList() {
        cout<<"Skip List"<<endl;
        for (int i = 0; i <= level; i++) {
            Node *node = header->forward[i];
            cout<<"Level "<<i<<": ";
            while (node != NULL) {
                cout<<node->value<<" ";
                node = node->forward[i];
            }
            cout<<endl;
        }
    }
};

int main() {
    srand((unsigned)time(NULL));
    SkipList skiplist(3, 0.5);
    skiplist.insertElement(*(new int(3)));
    skiplist.insertElement(*(new int(6)));
    skiplist.insertElement(*(new int(7)));
    skiplist.insertElement(*(new int(9)));
    skiplist.insertElement(*(new int(12)));
    skiplist.insertElement(*(new int(19)));
    skiplist.insertElement(*(new int(17)));
    skiplist.insertElement(*(new int(26)));
    skiplist.insertElement(*(new int(21)));
    skiplist.insertElement(*(new int(25)));
    skiplist.printList();
}
