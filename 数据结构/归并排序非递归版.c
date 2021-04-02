#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

/* L = �����ʼλ��, R = �ұ���ʼλ��, RightEnd = �ұ��յ�λ��*/
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{ /* �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ���������� */
     int LeftEnd, NumElements, Tmp;
     int i;

     LeftEnd = R - 1; /* ����յ�λ�� */
     Tmp = L;         /* �������е���ʼλ�� */
     NumElements = RightEnd - L + 1;

     while( L <= LeftEnd && R <= RightEnd ) {
         if ( A[L] <= A[R] )
             TmpA[Tmp++] = A[L++]; /* �����Ԫ�ظ��Ƶ�TmpA */
         else
             TmpA[Tmp++] = A[R++]; /* ���ұ�Ԫ�ظ��Ƶ�TmpA */
     }

     while( L <= LeftEnd )
         TmpA[Tmp++] = A[L++]; /* ֱ�Ӹ������ʣ�µ� */
     while( R <= RightEnd )
         TmpA[Tmp++] = A[R++]; /* ֱ�Ӹ����ұ�ʣ�µ� */

     for( i = 0; i < NumElements; i++, RightEnd -- )
         A[RightEnd] = TmpA[RightEnd]; /* �������TmpA[]���ƻ�A[] */
}

void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length )
{ /* �����鲢������������ */
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

     length = 1; /* ��ʼ�������г���*/
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
     else printf( "�ռ䲻��" );
}

int main()
{
    int a[10] = {7, 8, 1, 4, 9, 5, 2, 6, 3, 0}, i;
    Merge_Sort(a, 10);
    for(i = 0; i < 10; i++) printf("%d", a[i]);
    return 0;
}
