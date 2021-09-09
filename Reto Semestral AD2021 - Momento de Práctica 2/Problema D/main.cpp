#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int n = 100005;
int k[n];
int N[n];
int l[n];
char m[n];

int main() {
    int i;
    int j;
    int x;
    int y = 0;
    scanf("%s", m + 1);
    x = strlen(m + 1);
    for(i = 0, j = 2; j <= n; ++j) {
        while(i && m[j] != m[i + 1]) i = k[i];
        if(m[i + 1] == m[j]) ++i;
        k[j] = i; 
    }
    for(i = x; i; i = k[i]) 
    l[++y] = i;
    for(i = x; i; --i) 
    N[k[i]] += ++N[i];
    printf("%d\n", y);
    for(i = y; i; --i) 
    printf("%d %d\n", l[i], N[l[i]]);
    return 0;
}