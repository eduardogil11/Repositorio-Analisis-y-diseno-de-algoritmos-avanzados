#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    Node* right;
    Node* left;
    int data;
};

vector <int> x;

void nuevoNode(Node * node) {
    if(node == NULL) {
        return;
    }
    nuevoNode(node -> left);
    x.push_back(node -> data);
    nuevoNode(node -> right);
}

bool checkBST(Node * root) {
    nuevoNode(root);
    for(int i = 1; i < x.size(); i++) {
        if(x[i] <= x [i - 1]) {
            return false;
        }
    }
    return true;
}