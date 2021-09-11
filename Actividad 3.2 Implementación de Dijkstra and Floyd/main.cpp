/*
Daniel Cruz Arciniega A01701370
Eduardo Rodriguez A01274913
*/

#include <bits/stdc++.h>

using namespace std;

int INF = 99999;

/*
  El algoritmo de Dijkstra 
  es de complejidad O(n²) en nuestra implementacion
*/

void Dijkstra(vector <int> &G, int x) {
    printf("\nDijkstra: \n");
    for(int d = 0; d < x; ++d) {
        int v = 0;
        vector <int> N(x, INF);
        N[d] = 0;
        for(int n = 0; n < x; ++n) {
            v = d + n;
            if(v >= x) {
                v = v - x;
            }
            for(int m = 0; m < x; ++m) {
                if((G[v * x + m] > 0) && (G[v * x + m] + N[v] < N[m])) {
                    N[m] = G[v * x + m] + N[v];
                }
            }
        }
        for(int i = 0; i < x; ++i) {
            if(i != d) {
                cout << "node " << d + 1 << " to node " << i + 1 << " : " << N[i] << endl;
            }
        }
    }
}

/*
  El algoritmo de Floyd es de complejidad O(n³)
*/

void Floyd(vector <int> &G, int x) {
    int t[x][x], y = 0;
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < x; ++j) {
            t[i][j] = G[y];
            y++;
        }
    }
    for(int f = 0; f < x; ++f) {
        for(int i = 0; i < x; ++i) {
            for(int j = 0; j < x ; ++j) {
                if(t[i][j] > (t[f][j] + t[i][f]) && (t[f][j] != INF && t[i][f] != INF)) t[i][j] = t[f][j] + t[i][f];
            }
        }
    }
    printf("\nFloyd: \n");
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < x; ++j) {
            if(t[i][j] == INF)
            cout << "-1" << " ";
            else
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int x;
    vector <int> G;
    cin >> x;

    for(int i = 0; i < x * x; ++i) {
        int o = 0;
        cin >> o;
        G.push_back(o);
    }
    Dijkstra(G, x);

    for(int i = 0; i < G.size(); ++i) {
        if(G[i] == -1)
        G[i] = INF;
    }
    Floyd(G, x);
    return 0;
}