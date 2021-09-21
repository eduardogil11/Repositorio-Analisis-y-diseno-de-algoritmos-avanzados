#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    cin >> m;
    cin.ignore();
    while(m--) {
        string x;
        getline(cin, x);
        stringstream y(x);

        vector <int> S(1, 0);
        int n = 0, k;
        while(y >> k) {
            n += k;
            size_t size = S.size();
            for(size_t i = 0; i < size; ++i)
                S.push_back(S[i] + k);
        }
        if(n % 2 == 0 && find(S.begin(), S.end(), n / 2) != S.end()) {
            cout << "YES" << endl;
        }
        else
        cout << "NO" << endl;
    }
    return 0;
}