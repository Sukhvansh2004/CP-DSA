#include <iostream>
#include <vector>
using namespace std;

class BST {
public:
    int* root;
    int size;

    BST() {
        this->root = new int[1]{};
        this->size = 1;
    } 

    int mini(int start=0) {
        if(2*start+1 < size && root[2*start+1] != 0) {
            return mini(2*start+1);
        } else {
            return root[start];
        }
    }

    void resize() {
        int* temp = new int[size*2]{};
        for(int i=0; i<size; i++) {
            temp[i] = root[i];
        }
        delete[] root;
        this->size = size*2;
        this->root = temp;
    }
    
    void insert(int d, int start=0) {
        if(start < size) {
            if(root[start] != 0) {
                if(root[start] > d) {
                    this->insert(d, 2*start+1);
                } else {
                    this->insert(d, 2*start+2);
                }
            } else {
                root[start] = d;
            }
        } else {
            resize();
            insert(d, start);
        }
    }

    bool check(int index) {
        if(index < size && root[index] != 0) {
            return true;
        }
        return false;
    }

    void del(int d, int start=0) {
        if(start < size) {
            if(root[start] != d && root[start] != 0) {
                if(root[start] > d) {
                    this->del(d, 2*start+1);
                } else {
                    this->del(d, 2*start+2);
                }
            } else {
                if(root[start] == 0) {
                    cout << "Element not found" << endl;
                }
                if(root[start] == d) {
                    if(check(2*start+1) && check(2*start+2)) {
                        int t = mini(2*start+2);
                        this->root[start] = t;
                        del(t, 2*start+2);
                    } else if(check(2*start+1)) {
                        this->root[start] = root[2*start+1];
                        del(root[2*start+1], 2*start+1);
                    } else if(check(2*start+2)) {
                        this->root[start] = root[2*start+2];
                        del(root[2*start+2], 2*start+2);
                    } else {
                        this->root[start] = 0;
                    }
                }
            }
        } else {
            cout << "Element not found" << endl;
        }
    }

    void search(int t, int start=0) {
        if(start < size) {
            if(root[start] == 0) {
                if(t > root[start]) {
                    search(t, 2*start+2);
                } else if(t < root[start]) {
                    search(t, 2*start+1);
                } else {
                    cout << "Element found in the BST" << endl;
                }
            } else {
                cout << "Element not found in the BST" << endl;
            }
        } else {
            cout << "Element not found in the BST" << endl;
        }
    }
    
    ~BST() {
        delete[] root;
    }

};

int main() {
    BST* tree = new BST();
}