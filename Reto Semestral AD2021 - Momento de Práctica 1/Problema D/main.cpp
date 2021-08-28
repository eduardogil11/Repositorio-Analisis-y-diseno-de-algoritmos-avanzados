#include <bits/stdc++.h>

using namespace std;

struct node {
    node* der;
    node* izq;
    int x;
    int y;    
};

node * nuevoNode(int a) {
    node* Node = new node();
    Node -> y = a;
    Node -> izq = Node -> der = NULL;
    return Node;
}

void topView(node * root) {
    if(root == NULL)
       return;
    queue <node* > m;
    map <int, int> n;
    int x = 0;
    root -> x = x;
    m.push(root);

    while(m.size()) {
        x = root -> x;

        if(n.count(x) == 0)
           n[x] = root -> y;
        if(root -> der) {
           root -> der-> x = x + 1;
           m.push(root -> der);
        }
        if(root -> izq) {
           root -> izq -> x = x - 1;
           m.push(root -> izq);
        }
        m.pop();
        root = m.front(); 
    }
    for(auto i = n.begin(); i != n.end(); i++) {
        cout << i->second << " ";
    }
}

int main() {
    node* root = nuevoNode(1);
    root -> der = nuevoNode(2);
    root ->der->der = nuevoNode(5);
    root->der->der -> izq = nuevoNode(3);
    root ->der->der -> der = nuevoNode(6);
    root->der->der -> izq -> der = nuevoNode(4);
    topView(root);
    return 0;
}