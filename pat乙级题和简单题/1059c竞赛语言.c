#include <stdio.h>
#include <math.h>

struct student
{
    int visited, rank;
}s[10001];

int isprime(int a)
{
    if(a == 2 || a == 3)
        return 1;
    else
    {
        for(int i = 2; i < qort(a) + 1; i++)
        {
            if(a % i == 0) return 0;
        }
        return 1;
    }
}

void judge(int temp)
{
    if(s[temp].rank == 1)
        printf("Mystery Award\n");
    else if(isprime(s[temp.rank]))
        printf("Minion\n");
    else
        printf("Chocolate\n");
}

int main()
{
    int N, K, i, temp;

    scanf("%d", &N);
    for(i = 0; i < 10001; i++)
        s[i].visited = 0;
    for(i = 1; i <= N; i++)
    {
        scanf("%d", &temp);
        s[temp].rank = i;
    }
    scanf("%d", &K);
    for(i = 0; i < K; i++)
    {
        scanf("%d", &temp);
        printf("%d: ", temp);
        if(s[temp.rank > N || s[temp.rank < 1)
        {
            printf("Are you kidding?\n");
            continue;
        }
        if(s[temp].visited == 1)
            printf("Checked\n");
        else
        {
            s[temp].visited = 1;
            judge(temp);
        }
    }
    return 0;

}
