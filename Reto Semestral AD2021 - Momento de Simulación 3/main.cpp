#include <bits/stdc++.h>

using namespace std;

int main() {
  const int m = 520;
  long long r[m];
  int n,d[m][m],a[m];
  cin >> n;
  
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++)
    cin >> d[i][j];
  for (int i = 1; i <= n; i++)
    cin >> a[n - i + 1];
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (d[a[i]][a[j]] > d[a[i]][a[k]] + d[a[k]][a[j]])
          d[a[i]][a[j]] = d[a[i]][a[k]] + d[a[k]][a[j]];
          }

          for (int i = 1; i <= k; i++)
          for (int j = 1; j <= k; j++)
          r[k] += d[a[i]][a[j]];
          }
          
          for (int i = n; i >= 1; i--)
          cout << r[i] << " ";
          return 0;
}