#include <stdio.h>

struct Node//�������Ԫ��ֵ����һ������ַ���������±���Ϊ��ַ����
{
    int data, nextadd;
}L[100000];

struct LNode//�������Ԫ��ֵ�͵�ǰ����ַ
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
    {//change�����ȴ���������С��0�Ľ��
        if(L[thisadd].data < 0)
        {
            change[tempadd].data = L[thisadd].data;
            change[tempadd].add = thisadd;
            tempadd++;
        }
    }
    for(thisadd = firstadd; thisadd != -1; thisadd = L[thisadd].nextadd)
    {//change�����ٴ���������С�ڵ���K���ڵ���0�Ľ��
        if(L[thisadd].data >= 0 && L[thisadd].data <= K)
        {
            change[tempadd].data = L[thisadd].data;
            change[tempadd].add = thisadd;
            tempadd++;
        }
    }
    for(thisadd = firstadd; thisadd != -1; thisadd = L[thisadd].nextadd)
    {//change�������������������K�Ľ��
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
