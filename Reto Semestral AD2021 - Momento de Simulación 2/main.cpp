#include <bits/stdc++.h> 

using namespace std;

const int n = 1000101;
char p[n];
int s[n];
int t[n];

void A(int k) {
    int a;
    int b;
    a = 0;
    b = t[0] = -1;
    while(a < k) {
        if(b == -1 || p[a] == p[b]) {
            a++;
            b++;
            t[a] = b;
        }
        else
        b = t[b];
    }
}

int main(void) {
    int m;
    cin >> p;
    memset(s, 0, sizeof(s));
    m = strlen(p);
    A(m);
    for(int a = 1; a < m; a++) {
        s[t[a]] = 1;
    }
    int x = t[m];
    while(!s[x]) {
        x = t[x];
        if(x == -1)
        break;
    }
    if(x <= 0)
    cout << "Just a legend" << endl;
    else {
        for(int a = 0; a < x; a++)
        cout << p[a];
        puts("");
    }
    return 0;
}