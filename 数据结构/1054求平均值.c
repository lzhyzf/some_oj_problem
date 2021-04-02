#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, i, j, flag, cnt = 0;
    char a[50], b[50];
    double temp, sum = 0;

    scanf("%d", &N);
    for(i = 0 ; i < N; i++)
    {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2lf", temp);
        flag = 0;
        for(j = 0; a[j]; j++)
        {
            if(a[j] != b[j] || temp > 1000 || temp < -1000)
                flag = 1;
            if(flag){
                printf("ERROR: %s is not a legal number\n", a);
                break;
            }
        }
        if(!flag){
            cnt++;
            sum += temp;
        }
    }
    if(cnt == 1)
        printf("The average of 1 number is %.2lf", sum);
    else if(cnt == 0)
        printf("The average of 0 numbers is Undefined\n");
    else
        printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
    return 0;
}
