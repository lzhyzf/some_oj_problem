#include <stdio.h>

void InsertionSort(int a[], int N)
{
    int i, j, temp;
    for(j = 1; j < N; j++)               //从第一个元素有序开始，排列剩下的元素
    {
        temp = a[j];    //将要排序的元素保存在temp中
        for(i = j; i > 0 && a[i - 1] > temp; i--)
        {
            a[i] = a[i - 1];      //将元素右移
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
