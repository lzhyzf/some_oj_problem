#include <stdio.h>

int main()
{
    int N, i, j, k;
    double temp, sum = 0;

    scanf("%d", &N);
    for(i = 1; i <= N; i++)
    {
        scanf("%lf", &temp);
        sum += (double)i * (double)(N - i + 1) * temp;
    }
    printf("%.2f", sum);
    return 0;
}
