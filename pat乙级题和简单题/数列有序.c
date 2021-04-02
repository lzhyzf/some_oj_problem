#include <stdio.h>

#define MAXSIZE 101

int main(){
    int N, X, i;
    int A[MAXSIZE];

    scanf("%d %d", &N, &X);
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    for(i = N; A[i - 1] > X && i > 0; i--){
        A[i] = A[i - 1];
    }
    A[i] =  X;
    for(i = 0; i <= N; i++)
        if(i == 0)
            printf("%d", A[i]);
        else
            printf(" %d", A[i]);
    return 0;
}
