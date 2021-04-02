#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[9];
    int height;
}people[10002];


int cmp(const void *a, const void *b)     //先根据身高，再根据名字序列升序，对数据进行降序排列
{
    if(((struct Node *)a)->height == (( struct Node *)b)->height)
        return strcmp(((struct Node *)a)->name, ((struct Node *)b)->name);
    else
        return ((struct Node *)b)->height - ((struct Node *)a)->height;
}

int main()
{
    int N, i, K, m, temp, j;
    people p;
    char a[10002][9];
    scanf("%d %d", &N, &K);                                       //人数，排数
    for(i = 1; i <= N; i++)
        scanf("%s %d", p[i].name, &p[i].height);                  //存入N个人的身高姓名
    qsort(p + 1, N, sizeof(struct Node), cmp);                    //排序
    temp = 1;
    for(i = 1; i <= K; i++)
    {
        if(i == 1)
        {
            m = N - (K - 1) * (N / K);                                 //最高一排人数
            for(j = 1; j <= m; j++)
            {
                if(j % 2 == 1)
                    strcpy(a[m / 2 + 1 + j / 2], p[temp++].name);
                else
                    strcpy(a[m / 2 + 1 - (j / 2)], p[temp++].name);
            }
            for(j = 1; j <= m; j++)
            {
                if(j == 1)
                    printf("%s", a[j]);
                else
                    printf(" %s", a[j]);
                if(j == m)
                    printf("\n");
            }
        }
        else
        {
            m = N / K;
            for(j = 1; j <= m; j++)
            {
                if(j % 2 == 1)
                    strcpy(a[m / 2 + 1 + j / 2], p[temp++].name);
                else
                    strcpy(a[m / 2 + 1 - (j / 2)], p[temp++].name);
            }
            for(j = 1; j <= m; j++)
            {
                if(j == 1)
                    printf("%s", a[j]);
                else
                    printf(" %s", a[j]);
                if(j == m)
                    printf("\n");
            }
        }
    }
    return 0;
}
