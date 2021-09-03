#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int a = 1e5 + 10;
typedef pair <int, int> sub;

void solve() {
    int k;
    int n;
    cin >> n >> k;
    vector <sub> x(n);

    for(int i = 0; i < n; i++) {
        cin>>x[i].first;
        x[i].second = i;
    }
    int m = 1;
    sort(x.begin(), x.end());
    
    for(int i = 0; i < n-1; i++)
    if(x[i].second + 1 != x[i + 1].second)
    m++;
    if(m <= k)
    puts("Yes");
    else
    puts("No");
}

int main() {
    int y;
    cin >> y;

    while(y--)
    solve();
    return 0;
}