#include <bits/stdc++.h>

using namespace std;

int main () {
    long long n, m, s;

    while(cin >> n >> m >> s) {
        long long x = n % s, y = m % s, a = n / s, b = m / s;

        if(x == 0)
        x = s;
        else
        a++;
        if(y == 0) 
        y = s;
        else b++;

        long long r = x * y * a * b;
        cout << r << endl;
    }

    return 0;
}