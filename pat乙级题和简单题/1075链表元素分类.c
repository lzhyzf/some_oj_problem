#include <stdio.h>

struct Node//结点链表元素值和下一个结点地址，用数组下标作为地址索引
{
    int data, nextadd;
}L[100000];

struct LNode//结点链表元素值和当前结点地址
{
    int data, add;
}change[100000];
int main()
{
    int firstadd, N, K, i, tempadd, thisadd;

    scanf("%d %d %d", &firstadd, &N, &K);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &tempadd);
        scanf("%d %d", &L[tempadd].data, &L[tempadd].nextadd);
    }
    tempadd = 0;
    for(thisadd = firstadd; thisadd != -1; thisadd = L[thisadd].nextadd)
    {//change数组先存入链表结点小于0的结点
        if(L[thisadd].data < 0)
        {
            change[tempadd].data = L[thisadd].data;
            change[tempadd].add = thisadd;
            tempadd++;
        }
    }
    for(thisadd = firstadd; thisadd != -1; thisadd = L[thisadd].nextadd)
    {//change数组再存入链表结点小于等于K大于等于0的结点
        if(L[thisadd].data >= 0 && L[thisadd].data <= K)
        {
            change[tempadd].data = L[thisadd].data;
            change[tempadd].add = thisadd;
            tempadd++;
        }
    }
    for(thisadd = firstadd; thisadd != -1; thisadd = L[thisadd].nextadd)
    {//change数组最后存入链表结点大于K的结点
        if(L[thisadd].data > K)
        {
            change[tempadd].data = L[thisadd].data;
            change[tempadd].add = thisadd;
            tempadd++;
        }
    }
    for(i = 0; i < N; i++)
    {
        printf("%05d %d", change[i].add, change[i].data);
        if(i == N - 1) printf(" -1");
        else printf(" %05d", change[i+1].add);
        printf("\n");
    }
    return 0;
}
