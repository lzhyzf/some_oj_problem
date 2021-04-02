#include <stdio.h>
#include <stdlib.h>

int flag = 0, b[100];       //全局变量flag判断是否达到某个排序算法，b数组是排序算法进行到某一步的时候

void InsertionSort(int a[], int N)
{
    int i, j, k, m, temp, cnt = 9999;
    for(j = 1; j < N; j++)               //从第一个元素有序开始，排列剩下的元素
    {
        temp = a[j];    //将要排序的元素保存在temp中
        for(i = j; i > 0 && a[i - 1] > temp; i--)
        {
            a[i] = a[i - 1];      //将元素右移
        }
        a[i] = temp;
        if(flag == 1)                           //如果和b数组已经达成重合，则之前也已经多进行了一步，退出循环
            break;
        for(k = 0; k < N && a[k] == b[k]; k++)
            if(k == N - 1) flag = 1;
        if(flag == 1)
            printf("Insertion Sort\n");
    }
    if(flag == 1)                            //打印排序多一步的数组
        for(m = 0; m < N; m++){
            if (m == 0) printf("%d", a[m]);
            else printf(" %d", a[m]);
        }
}

typedef int ElementType;

/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
     int LeftEnd, NumElements, Tmp;
     int i;

     LeftEnd = R - 1; /* 左边终点位置 */
     Tmp = L;         /* 有序序列的起始位置 */
     NumElements = RightEnd - L + 1;

     while( L <= LeftEnd && R <= RightEnd ) {
         if ( A[L] <= A[R] )
             TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
         else
             TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
     }

     while( L <= LeftEnd )
         TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
     while( R <= RightEnd )
         TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */

     for( i = 0; i < NumElements; i++, RightEnd -- )
         A[RightEnd] = TmpA[RightEnd]; /* 将有序的TmpA[]复制回A[] */
}

void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length )
{ /* 两两归并相邻有序子列 */
     int i, k;

     for(i = 0; i < N - 2 * length; i += 2 * length)
         Merge(A, TmpA, i, i+length, i+2*length-1);
     if(i + length < N)
        Merge(A, TmpA, i, i+length, N - 1);
     for(k = 0; k < N && A[k] == b[k]; k++)
            if(k == N - 1) flag = 1;
}

void Merge_Sort( ElementType A[], int N )
{
     int length, cnt = 0, x = 9999, m;
     ElementType *TmpA;

     length = 1; /* 初始化子序列长度*/
     TmpA = malloc( N * sizeof( ElementType ) );
     while( length < N ) {
         Merge_pass( A, TmpA, N, length);
         length *= 2;
         cnt++;
         if(flag == 1)
         {
            if(cnt == x + 1) break;
            x = cnt;
         }
         }
     free( TmpA );
     for(m = 0; m < N; m++){
            if (m == 0) printf("%d", A[m]);
            else printf(" %d", A[m]);
     }
}

int main(){
    int N, i, a[100], c[100];

    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < N; i++)
        scanf("%d", &b[i]);
    for(i = 0; i < N; i++)
        c[i] = a[i];
    InsertionSort(a, N);
    if(flag == 0){
        printf("Merge Sort\n");
        Merge_Sort(c, N);
    }
    return 0;
}
