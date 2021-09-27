#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define T ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
    T;
    int n;
    cin >> n;
    while(n--) {
        int x = 0;
        int y = 0;
        int z = 0;
        string a;
        string b;
        cin >> a;
        cin >> b;
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < b.size(); j++) {
                int z = i;
                int m = j;
                int x = 0;
                while(m < b.size() && z < a.size() && a[z] == b[m]) {
                    z++;
                    m++;
                    x++;
                }
                y = max(x, y);
            }
        }
        cout << (a.size() - y) + (b.size() - y) << endl;
    }
}