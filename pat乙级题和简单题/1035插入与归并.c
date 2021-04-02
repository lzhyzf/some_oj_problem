#include <stdio.h>
#include <stdlib.h>

int flag = 0, b[100];       //ȫ�ֱ���flag�ж��Ƿ�ﵽĳ�������㷨��b�����������㷨���е�ĳһ����ʱ��

void InsertionSort(int a[], int N)
{
    int i, j, k, m, temp, cnt = 9999;
    for(j = 1; j < N; j++)               //�ӵ�һ��Ԫ������ʼ������ʣ�µ�Ԫ��
    {
        temp = a[j];    //��Ҫ�����Ԫ�ر�����temp��
        for(i = j; i > 0 && a[i - 1] > temp; i--)
        {
            a[i] = a[i - 1];      //��Ԫ������
        }
        a[i] = temp;
        if(flag == 1)                           //�����b�����Ѿ�����غϣ���֮ǰҲ�Ѿ��������һ�����˳�ѭ��
            break;
        for(k = 0; k < N && a[k] == b[k]; k++)
            if(k == N - 1) flag = 1;
        if(flag == 1)
            printf("Insertion Sort\n");
    }
    if(flag == 1)                            //��ӡ�����һ��������
        for(m = 0; m < N; m++){
            if (m == 0) printf("%d", a[m]);
            else printf(" %d", a[m]);
        }
}

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

     length = 1; /* ��ʼ�������г���*/
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
