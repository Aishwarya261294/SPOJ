//factorial
#include "stdio.h"
#include "stdlib.h"
#define MAXRANGE 100000

long int Display(long int n, long int v);
long int Divide(long int n, long int v);
typedef long int (*fMethod) (long int n, long int v);

fMethod job[2] = { Display, Divide };

long int Display(long int n, long int v) {
    printf("%d\n", n);
    return 0;
}

long int Divide(long int n, long int v) {
    v = (v<<1)/10;
    return job[v==0?0:1](n+v,v);
}

int main() {
    long int nRange;
    long int nArray[MAXRANGE];
    long int i,j,k;

    scanf("%ld", &nRange);

    for(i = 0; i < nRange; i++) {
        scanf("%ld", &k);
        nArray[i] = k;
    }

    for(j = 0; j < nRange; j++) {
        long int n = (nArray[j]<<1)/10;
        job[n==0?0:1](n, n);
    }
    return 0;
}
