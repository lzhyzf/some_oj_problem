#include <stdio.h>
#include <stdlib.h>
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
     int i;

     for(i = 0; i <= N - 2 * length; i += 2 * length)
         Merge(A, TmpA, i, i+length, i+2*length-1);
     if(i + length < N)
        Merge(A, TmpA, i, i+length, N - 1);

}

void Merge_Sort( ElementType A[], int N )
{
     int length, m;
     ElementType *TmpA;

     length = 1; /* 初始化子序列长度*/
     TmpA = malloc( N * sizeof( ElementType ) );
     if ( TmpA != NULL ) {
          while( length < N ) {
              Merge_pass( A, TmpA, N, length );
              length *= 2;
              for(m = 0; m < N; m++){
                  if (m == 0) printf("%d", A[m]);
                  else printf(" %d", A[m]);
              }
              printf("\n");
          }
          free( TmpA );
     }
     else printf( "空间不足" );
}

int main()
{
    int a[10] = {7, 8, 1, 4, 9, 5, 2, 6, 3, 0}, i;
    Merge_Sort(a, 10);
    for(i = 0; i < 10; i++) printf("%d", a[i]);
    return 0;
}
