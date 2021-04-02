#include <stdio.h>

/*算法一：保留求出所有子列和，找出其最大值
int main()
{
    int i, j, k, max = 0, a[100000], N, sum;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < N; i++)
        for(j = i, sum = 0; j < N; j++)
        {
            sum += a[j];
            if(max < sum) max = sum;
        }
    printf("%d", max);
    return 0;
}
*/
//算法二：在线处理
int main()
{
    int i, thissum = 0, summax = 0, N, temp;

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &temp);
        thissum += temp;
        if(thissum > summax) summax = thissum;
        if(thissum < 0) thissum = 0;
    }
    printf("%d", summax);
    return 0;
}
