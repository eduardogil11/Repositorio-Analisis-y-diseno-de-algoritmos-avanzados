// =========================================================
// File: tsp.h
// Author: Eduardo Rodríguez Gil - A01274913
// Date: 14/11/2021
// =========================================================

#include<bits/stdc++.h>

using namespace std;

void TSP(vector<int>& graph, int m, int n) {

    int G[n][n], con = 0;
    for(int i = 0; i< n; i++){
      for(int j = 0; j< n; j++){
        G[i][j] = graph[con];
        con++;
      }
    }

    vector <int> V; vector <int> v;
    v.push_back(0);

    for (int i = 0; i < n; i++){
      if (i != m)
        V.push_back(i);

    }

    int min_path = INT_MAX;
    int res = 0;
    do {
        int current_pathweight = 0;int k = m;
        vector<int> T;

        for (int i = 0; i < V.size(); i++) {
            current_pathweight += G[k][V[i]];
            k = V[i];
            T.push_back(V[i]);
        }

        current_pathweight += G[k][m];
        res = min_path;
        min_path = min(min_path, current_pathweight);

        if(res != min_path){
          v.clear(); v.push_back(m);
          for(int i = 0; i < T.size(); i++)
            v.push_back(T[i]); v.push_back(m);
        }

        T.clear();
 
    } 
    
    while (next_permutation(V.begin(), V.end()));
    if(min_path < 0) {
      cout << "There is no possible route." << endl;
    } 
    
    else {
      cout <<endl<< "Minimum cost: " << min_path << endl; cout << "Path: ";
      for(int i = 0; i < v.size(); i++)
      cout << v[i] << " "; cout << endl;
    }
}