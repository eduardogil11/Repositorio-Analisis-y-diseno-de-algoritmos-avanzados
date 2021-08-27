#include <iostream>
#include <string>

using namespace std;

int main() {

    char player[100];
    int x = 0;
    int y = 0;
    bool sit = false;
    cin >> player;

    while(player[y] != '\0') {
        if(player[y] == '1') {
            while(player[y] == '1') {
                x++;
                y++;
            }
        }
        else {
            while(player[y] == '0') {
                x++;
                y++;
            }
        }
        if(x>=7) {
            sit = true;
            break;
        }
        x = 0;
    }
    if(sit) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}