#include <stdio.h>
#include <math.h>

int isprime(int temp)
{
    for(int i = 2; i < sqrt(temp + 1); i++){
        if(temp % i == 0) return 0;
    }
    return 1;
}

int main()
{
    int prime[10000], cnt = 2, temp = 3, M, N, i, geshi = 0;

     prime[0] = 2;
     prime[1] = 3;
     while(1){
        ++temp;
        if(isprime(temp)){
        prime[cnt] = temp;
        cnt++;
        }
        if (cnt == 10000) break;
     }
     scanf("%d %d", &M , &N);
     for(i = M; i <= N; i++){
        geshi++;
        printf("%d%c",prime[i - 1],(geshi % 10 == 0||i == N)?'\n':' ');
     }
     return 0;
}
