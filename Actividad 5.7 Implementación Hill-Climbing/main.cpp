// =========================================================
// File: main.cpp
// Author: Eduardo Rodríguez Gil - A01274913
// Date: 28/11/2021
// Activity: Actividad 5.7 Implementación Hill-Climbing
// =========================================================

#include <bits/stdc++.h>
#include "hill-climbing.h"

using namespace std;

int main() {
    int n;
    int q = 0;
    cin >> n;
    vector < vector<bool>> a(n, vector <bool>(n, false));
    Pos(n, q, a); Res(a);
}