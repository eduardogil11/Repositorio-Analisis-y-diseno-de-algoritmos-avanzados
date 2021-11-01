#include <bits/stdc++.h>

using namespace std;

int main () {
    const int m = 302;
    int q[m][m];
    int n, k, a, b, c;
    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            cin >> q[i][j];
        }

        for (int d = 1; d <= n; d++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    q[i][j] = min(q[i][j], q[i][d] + q[d][j]);
        cin >> k;

        for(int p = 0; p < k; p++) {
            cin >> a >> b >> c;
            long long r = 0;

            if(c  < q[a][b]) {
                q[a][b] = q [b][a] = c;
                for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++) {
                    q[i][j] = min(q[i][j], min(q[i][a] + q[a][j], q[i][b] + q[b][j]));
                    q[j][i] = q[i][j];
                }
            }

            for(int i = 1; i < n; i++)
            for(int j = i + 1; j <= n; j++)
            r += q[i][j];
            cout << r << endl;
        }

        return 0;
}