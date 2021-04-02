#include <stdio.h>
void Swap(int *a, int *b)
{
    int c = *a; *a = *b; *b = c;
}
void PercDown(int a[], int p, int N)
{
    int temp, parent, child;

    temp = a[p];
    for(parent = p; parent * 2+1 < N; parent = child)
    {
        child = parent * 2 + 1;
        if(child != N - 1 && a[child] < a[child + 1]) child++;           //childָ�����бȽϴ����
        if(temp < a[child]) a[parent] = a[child];
        else break;                                                      //�ҵ��˺��ʵ�λ��
    }
    a[parent] = temp;
}

void HeapSort(int a[], int N)
{   /* ������ */
    int i;

    for(i = N/2 - 1; i >= 0; i--)                       //�������������ʼ��Ϊ���ѣ���ΪN/2-1�Ƕѵ���С��Ҷ��㣬�������㿪ʼ������~
        PercDown(a, i, N);
    for(i = N - 1; i > 0; i--)
    {                                                  //ÿ�ν����Ԫ�طŵ���󣨽�������ͷ�����һ��Ԫ��λ�ã���Ȼ���Ե�һ��Ԫ��Ϊ���ڵ����Ϊ����
        Swap(&a[0], &a[i]);
        PercDown(a, 0, i);
    }
}

int main()
{
    int a[10] = {7, 8, 1, 4, 9, 5, 2, 6, 3, 0}, i;
    HeapSort(a, 10);
    for(i = 0; i < 10; i++) printf("%d", a[i]);
    return 0;
}
