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
        if(child != N - 1 && a[child] < a[child + 1]) child++;           //child指向孩子中比较大的数
        if(temp < a[child]) a[parent] = a[child];
        else break;                                                      //找到了合适的位置
    }
    a[parent] = temp;
}

void HeapSort(int a[], int N)
{   /* 堆排序 */
    int i;

    for(i = N/2 - 1; i >= 0; i--)                       //将待排序数组初始化为最大堆，因为N/2-1是堆的最小非叶结点，从这个结点开始堆排序~
        PercDown(a, i, N);
    for(i = N - 1; i > 0; i--)
    {                                                  //每次将最大元素放到最后（交换最大堆头和最后一个元素位置），然后以第一个元素为根节点调整为最大堆
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
