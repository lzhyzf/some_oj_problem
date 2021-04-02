#include <stdio.h>

int main(){
    int N, K, D, i, j, cnt, empty = 0, mayempty = 0;
    double e, temp;

    scanf("%d %f %d", &N, &e, &D);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &K);
        for(j = 0, cnt = 0; j < K; j++)
        {
            scanf("%f", &temp);
            if(temp < e)
                cnt++;
        }
        if(cnt > K / 2 &&  K > D)
            empty++;
        else if(cnt > (K / 2))
            mayempty++;
    }
    printf("%.1f%% %.1f%%", (double)mayempty *100 / N, (double)empty *100 / N);
    return 0;
}
