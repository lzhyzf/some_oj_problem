#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100001

int main(){
    int i, K, m, ThisSum, MaxSum;
    int a[MAXSIZE];

    scanf("%d", &K);
    for (i=0; i<K; i++){
        scanf("%d", &m);
        a[i] = m;
    }
    for (i=0; a[i] < 0 && i < K; i++)
         if (i == K)
            printf("0");
    ThisSum = MaxSum = 0;
    for (i=0; i<K; i++){
        ThisSum += a[i];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        if (ThisSum < 0)
            ThisSum = 0;
    }
    printf ("%d", MaxSum);
    return 0;
}
