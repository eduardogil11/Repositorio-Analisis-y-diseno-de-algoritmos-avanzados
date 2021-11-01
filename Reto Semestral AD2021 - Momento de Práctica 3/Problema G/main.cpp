#include <bits/stdc++.h>

using namespace std;

int m, n; 
int s = 0;
const int k = 2e5 + 5;
vector <int> v[k];
int a[k], b[k];

void d(int x, int y) {
    int f = 0;
    b[x] = 1;
    if(y > m)
    return;

    for(int i = 0; i < v[x].size(); i++) {
        int p = v[x][i];
        if(b[p] == 0) {
            f = 1;
            if(a[p] == 1) {
                d(p, y + 1);
            }

            else {
                d(p, 0);
            }
        }
    }

    if(f == 0) {
        s++;
    }
}

int main() {
    s = 0;
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    d(1, a[1]);
    cout << s << endl;
    return 0;
}