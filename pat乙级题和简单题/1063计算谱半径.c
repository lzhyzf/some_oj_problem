#include <stdio.h>
#include <math.h>

int main()
{
    int N, i, max = 0, temp1, temp2, sum;

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d %d", &temp1, &temp2);
        sum = pow(temp1, 2) + pow(temp2, 2);
        if(max < sum) max = sum;
    }
    printf("%.2f", sqrt((double)max));
    return 0;
}
