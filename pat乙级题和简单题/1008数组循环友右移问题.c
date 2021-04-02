#include <stdio.h>

int main(){
    int N, M, i, k = 0;

    scanf("%d %d", &N, &M);
    int a[N];
    M = M % N;
    for(i = 0; i < N; ++i){
        scanf("%d", &a[i]);
    }

    if(M == 0){
       for(i = 0; i < N; i++)
        {
            if(k == 0){
                printf("%d", a[i]);
                k++;
            }
            else
                printf(" %d", a[i]);
        }
    }
    else{
    for(i = N - M; i <= N - 1;i++)
    {
        if(k == 0){
            printf("%d", a[i]);
            k++;
        }
        else
            printf(" %d", a[i]);
    }
    for(i = 0; i < N - M; i++) printf(" %d", a[i]);
    }
    return 0;
}
