#include <bits/stdc++.h>

using namespace std;

struct P {
    double n, m;
};

struct S {
    P x, y;
};

int segments(S i, P j) {
    return min(i.x.n, i.y.n) <= j.n && max(i.x.n, i.y.n) >= j.n &&
           min(i.x.m, i.y.m) <= j.m && max(i.x.m, i.y.m) >= j.m;
}
P k;
int res(S i, S j) {
    double a, b, c, d, e, f;
    double X;
    double Y;
    double Z;
    a = i.x.m - i.y.m, b = -i.x.n + i.y.n;
    c = j.x.m - j.y.m, d = -j.x.n + j.y.n;
    e = a * i.x.n + b * i.x.m;
    f = c * j.x.n + d * j.x.m;
    X = a * d - c * b;
    Y = e * d - f * b;
    Z = a * f - c * e;

    if(!X && (Y || Z))
        return 0;
    else if(!X && !Y && !Z)
        return 0;
    else {
        k.n = Y/X; 
        k.m = Z/X;

        if (fabs(k.n - i.x.n) < 1e-6 && fabs(k.m - i.x.m) < 1e-6)
            return 0;
        if (fabs(k.n - i.y.n) < 1e-6 && fabs(k.m - i.y.m) < 1e-6)
            return 0;
        if (fabs(k.n - j.x.n) < 1e-6 && fabs(k.m - j.x.m) < 1e-6)
            return 0;
        if (fabs(k.n - j.y.n) < 1e-6 && fabs(k.m - j.y.m) < 1e-6)
            return 0;
        if(segments(i, k) && segments(j, k));
        else
            return 0;
    }
    return 1;
}

int main() {
    int n1, n2, n3, i, j;
    cin >> n1;
    while(n1--) {
        S s[100];
        cin >> n2;
        for(i = 0; i < n2; i++)
            cin >> s[i].x.n >> s[i].x.m >> s[i].y.n >> s[i].y.m;
            do {
                n3 = n2;
                for(i = 0; i < n2; i++) {
                    for(j = i + 1; j < n2; j++) {
                    if(res(s[i], s[j])) {
                        s[n3] = s[i];
                        s[i].y = k, s[n3].x = k;
                        n3++;
                        s[n3] = s[j];
                        s[j].y = k, s[n3].x = k;
                        n3++;
                    }
                }
            }
            if(n3 != n2) n2 = n3;
            else break;
        }
        while(1);
        cout << n2 << endl;
        if(n1) puts("");
    }
    return 0;
}