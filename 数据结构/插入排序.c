#include <stdio.h>

void InsertionSort(int a[], int N)
{
    int i, j, temp;
    for(j = 1; j < N; j++)               //�ӵ�һ��Ԫ������ʼ������ʣ�µ�Ԫ��
    {
        temp = a[j];    //��Ҫ�����Ԫ�ر�����temp��
        for(i = j; i > 0 && a[i - 1] > temp; i--)
        {
            a[i] = a[i - 1];      //��Ԫ������
        }
        a[i] = temp;
    }
}

int main()
{
    int a[10] = {7, 8, 1, 4, 9, 5, 2, 6, 3, 0}, i;
    InsertionSort(a, 10);
    for(i = 0; i < 10; i++) printf("%d", a[i]);
    return 0;
}
