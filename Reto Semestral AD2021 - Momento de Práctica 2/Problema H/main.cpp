#include <bits/stdc++.h>

using namespace std;

int n;

void P() {
    string x(200, 'a');
    cout << x << endl;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        x[k] = x[k] == 'a'?'b':'a';
        cout << x << endl;
    }
}

int main() {
    int m;
    cin >> m;
    while(m--) {
        cin >> n;
        P();
    }
    return 0;
}