#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

class node {
    public:
    node* der; 
    node* izq; 
    int x; 
    node(int y) {
        x = y;
        der = NULL;
        izq = NULL;
    }    
};

class nuevoNode{
    public:
    node* insert(node* root, int x) {
        if(root == NULL) {
            return new node(x);
        }
        else {
            node* n;
            if(root -> x <= x) {
                n = insert(root -> der, x);
                root -> der = n;
            }
            else {
                n = insert(root -> izq, x);
                root -> izq = n;
            }
            return root;
        }
    }
    void topView(node * root);
};

void nuevoNode::topView(node * root) {
    queue<pair<int, node* >> m;
    m.push(make_pair(0, root));
    map <int, node*> ans;
    for(auto i = m.front(); ! m.empty(); m.pop(), i = m.front()) {
        if(! i.second) continue;
        ans.insert(i);
        m.push(make_pair(i.first + 1, i.second -> der));
        m.push(make_pair(i.first - 1, i.second -> izq));
        }
        for(auto a:ans) 
        cout <<a.second -> x << " ";
    }

int main(int argc, char * argv[]) {
    nuevoNode BTS;
    node* root = NULL;
    int x;
    int z;
    cin >> z;

    for(int i = 0; i < z; i++) {
        cin >> x;
        root = BTS.insert(root, x);
    }
    BTS.topView(root);
    return 0;
}