#include <stdio.h>

int main(){
    int sum[100001] = {}, N, i, sn, score, max = 0;

    scanf("%d", &N);
    for(i = 1; i <= N; i++)
    {
        scanf("%d %d", &sn, &score);
        sum[sn] += score;
    }
    for(i = 1; i <= N; i++)
    {
        if(sum[max] < sum[i]) max = i;
    }
    printf("%d %d", max, sum[max]);
    return 0;
}
