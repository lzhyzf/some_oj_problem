#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(long*)a - *(long*)b;
}

int main(){
    int N, i, j, cnt = 0, max = 0;
    long p;                                           //p����Ҫ��long����
    long a[100000];

    scanf("%d %ld", &N, &p);
    for(i = 0; i < N; i++)
    {
        scanf("%ld", &a[i]);
    }
    qsort(a, N, sizeof(long), cmp);
        for(i = 0; i < N; i++)
    {
        if(a[i] * p >= a[N-1])
        {
            cnt = N - i;
            max = (max > cnt? max : cnt);
            break;
        }
        for(j = i + max; j < N; j++)                         //ǰһ�����ݳ���p�����õ������ں�һ���������ﶼ���ñȽϣ����Գ�ʼjֱ��Ϊi+max
        {
            if(a[j] > a[i] * p){
                cnt = j - i;
                break;
            }
        }
        if(cnt > max) max = cnt;
    }
    printf("%d", max);
    return 0;
}
