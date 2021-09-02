#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int BusX(const void * x, const void * y) {
    return(*(int*)x - *(int*)y);
}

int BusY(const void * x, const void * y) {
    return(*(int*)y - *(int*)x);
}

int main() {
    while(1) {
        int morning[10000];
        int evening[10000];
        int n;
        int d;
        int r;
        int i;
        int j;
        int t;
        int a = 0;

        scanf("%d%d%d", &n, &d, &r);
        if(!n && !d && !r) 
        return 0;

        for(i = 0; i < n; i++)
        scanf("%d", &morning[i]);
        for(i = 0; i < n; i++)
        scanf("%d", &evening[i]);

        qsort(morning, n, sizeof(int), BusX);
        qsort(evening, n, sizeof(int), BusY);

        for(i = 0; i < n; i++) {
            if(morning[i] + evening[i] > d) {
                t = morning[i] + evening[i] - d;
                a += t * r;
            }
        }
        printf("%d\n", a);
    }
    return 0;
}