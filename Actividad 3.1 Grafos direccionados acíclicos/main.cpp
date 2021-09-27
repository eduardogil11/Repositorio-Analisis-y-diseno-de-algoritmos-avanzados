#include <bits/stdc++.h>

using namespace std;

bool f;
const int n = 35;
int K, E, x, y, d[n];

struct boxes {
    int m[12];
    bool operator <(const boxes & r) const {
        for(int i = 0; i < E; i++) {
            if(m[i] >= r.m[i]) {
                return false;
            }
        }
        return true;
    }
}
b[n];

void I() {
    memset(d, -1, sizeof(d));
    f = true; x = -1; 
    cin >> E;
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < E; j++) {
            cin >> b[i].m[j];
        }
        sort(b[i].m, b[i].m + E);
    }
}

int s(int i, const vector <int> *p) {
    int & x = d[i], t;
    if(x != -1) {
        return x;
    }
    x = 1;
    for(int j = 0; j < p[i].size(); j++) {
        t = s(p[i][j], p) + 1;
        x = max(t, x);
    }
    return x;
}

void A(int i, const vector <int> *p) {
    if(f) {
        cout << i + 1;
        f = false;
    }
    else {
        cout << ' ' << i + 1;
    }
    for(int j = 0; j < p[i].size(); j++) {
        if(d[p[i][j]] == d[i] - 1) {
            A(p[i][j], p);
            break;
        }
    }
}

void S() {
    vector <int> p[n];
    for(int i = 0; i < K - 1; i++) {
        for(int j = i + 1; j < K; j++) {
            if(b[i] < b[j]) {
                p[i].push_back(j);
            }
            else if(b[j] < b[i]) {
                p[j].push_back(i);
            }
        }
    }
    for(int i = 0; i < K; i++) {
        int t = s(i, p);
        if(t > x) {
            x = t; y = i;
        }
    }
    cout << x << endl; A(y, p); cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    while(cin >> K) {
        I(); S();
    }
    return 0;
}