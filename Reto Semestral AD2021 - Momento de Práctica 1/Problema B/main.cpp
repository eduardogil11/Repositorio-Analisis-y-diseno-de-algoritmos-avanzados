#include <iostream>
#include <string>

using namespace std;

int main() {
    int x[1000];
    int y[1000];
    int team = 0;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        cin >> y[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(x[i] == y[j]){
                team++;
            }
        }
    }
    cout << team << endl;
}