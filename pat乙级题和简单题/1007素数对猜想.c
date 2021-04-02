#include <stdio.h>
#include <math.h>

int isprime(int a)
{//ÅĞ¶ÏÊÇ·ñÎªËØÊı
    if(a == 1) return 0;
    if(a == 2 || a == 3) return 1;
    for (int i = 2; i < sqrt(a+1); ++i){
        if(a % i == 0) return 0;
    }
    return 1;
}

int main(){
    int N, i, count = 0;

    scanf("%d", &N);
    int b[N+1];
    for(i = 0; i <= N; i++) b[i] = 0;
    for(i = 2; i <= N; i++){
        if(isprime(i)) b[i] = 1;
    }
    if(N < 2) printf("0");
    else
    {
        for (i = 1; i <= N - 2; ++i){
            if(b[i] && b[i + 2]) ++count;
    }
    }
    printf("%d", count);
}
