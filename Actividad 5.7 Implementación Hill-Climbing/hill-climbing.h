// =========================================================
// File: hill-climbing.h
// Author: Eduardo Rodríguez Gil - A01274913
// Date: 28/11/2021
// Activity: Actividad 5.7 Implementación Hill-Climbing
// =========================================================

/*
  El algoritmo de Hill-Climbing es de complejidad O(n²)
*/

#include <bits/stdc++.h>

using namespace std;

bool V(int f, int c, vector< vector<bool>> a) {
    for(int i = 0; i < c; i++) {
      if(a[f][i])
        return false;
    }

    for(int i = f, j = c; i < a.size() and j >= 0; i++, j--) {
       if(a[i][j])
        return false;

    }

    for(int i = f, j = c; i >= 0 and j >= 0; i--, j--) {
      if(a[i][j])
        return false; 
    }
  
    return true; 
}

bool Pos(int n, int q, vector< vector<bool>> &a) {
    if(q == n)
    return true;

    for(int i = 0; i < n; i++) {
      if(V(i, q, a)) {
        a[i][q] = true;

        if(Pos(n, q + 1, a)) {
          return true;
        }

        else {
          a[i][q] = false;
        }
      }
    }

    return false;
}

void Res(vector< vector<bool>> a) {
    for(int i = 0; i < a.size(); i++) {
        cout << "{ ";

        for(int j = 0; j < a.size(); j++) {
            if(j == a.size() - 1) {
              cout << a[i][j];
            }

            else {
              cout << a[i][j] << ", "; 
            }
        }

        cout << "}" << endl;
    }
}