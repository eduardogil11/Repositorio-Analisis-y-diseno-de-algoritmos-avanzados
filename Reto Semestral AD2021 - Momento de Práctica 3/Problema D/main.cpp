#include <bits/stdc++.h>

using namespace std;

int p[100000];
int q(int x) {
    if(p[x] == x)
    return x;
    else
    return q(p[x]);
}

void c(int a, int b) {
    int x = q(a), y = q(b);
    if(x != y)
    p[x] = y;
}

int main() {
    int u[100000], v[100000];
    int x, y, n, m, k;

    while(cin >> n >> m >> k) {
        memset(v, 0, sizeof(v));

        for(int i = 1; i <= n; i++)
        p[i] = i;
        for(int i = 1; i <= k; i++)
        cin >> u[i];
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            c(x, y);
        } 

        for(int i = 1; i <= n; i++)
        v[q(i)]++;

        int t = 0, o = 0; 
        int z = n;

        for(int i = 1; i <= k; i++) {
            v[u[i]] = v[q(u[i])];
            t = max(t, v[u[i]]);
            o += (v[u[i]]) * (v[u[i]] - 1) / 2;
            z -= v[u[i]];
        }

        o += (z + t) * (z + t - 1) / 2;
        o -= t * (t - 1) / 2 + m;
        cout << o << endl;
    }

    return 0;
}