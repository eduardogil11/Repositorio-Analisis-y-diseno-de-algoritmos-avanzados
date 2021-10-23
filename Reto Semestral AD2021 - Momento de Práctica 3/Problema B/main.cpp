#include <bits/stdc++.h>

using namespace std;

int main (){
    int a, b, x, y;
    int n[10001] = {0};
    vector <int> s;
    vector <vector <int> > f(10001);
    priority_queue <int, vector <int>, greater <int> > q;
    cin >> a >> b;

    while(b--) {
        cin >> x >> y;
        f[x].push_back(y);
        ++n[y];
    }

    for(int i = 1; i <= a; ++i) {
        if(!n[i])
        q.push(i);
    }

    while(!q.empty()) {
        int t = q.top();
        s.push_back(t);
        q.pop();
        for(auto i(f[t].begin()); i != f[t].end(); ++i) {
            if(--n[* i] == 0)
            q.push(* i);
        }
    }

    if(s.size() < a)
    cout << "Sandro fails.";
    else for(int i = 0; i != s.size(); ++i) {
        if(i)putchar(' ');
        cout << s[i];
    }
    return 0;
}