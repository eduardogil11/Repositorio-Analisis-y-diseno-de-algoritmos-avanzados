#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string n;
        cin >> n;
        int a = n.size(), b = 0;
        for(int i = 0; i < a; i++) {
            if(i < a - 1; n[i] != '0' && n[i] == n[i + 1]) {
                n[i + 1] = '0';
                b++;
            }
            else if(i > 0; i < a - 1 && n[i -1] == n[i + 1]) {
                n[i + 1] = '0';
                b++;
            }
        }
        cout << b << endl;
    }
}