#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int a,
    kid[100],
    x = 0,
    y = 0,
    coins = 0;
    cin >> a;

    for(int i = 0; i < a; ++i) {
        cin >> kid[i];
        x += kid[i];
    }
    sort(kid, kid + a);

    for(int i = a - 1; i >= 0; --i) {
        coins += kid [i];
        x -= kid [i];
        y++;
        if(coins>x)
        break;
    }
    cout << y << endl;
    return 0;   
}