#include <stdio.h> /* ϣ������ - ��Sedgewick�������� */

int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

void ShellSort(int a[], int N)
{
    int i, D, P, si, temp;
    for(si = 0; Sedgewick[si] >= N; si++);   /* ��ʼ������Sedgewick[Si]���ܳ����������г��� */
    for(D = Sedgewick[si]; D > 0; D = Sedgewick[++si]){
        for(P = D; P < N; P++)               /* ��������*/
        {
            temp = a[P];    //��Ҫ�����Ԫ�ر�����temp��
            for(i = P; i >= D && a[i - D] > temp; i -= D)
            {
                a[i] = a[i - D];      //��Ԫ������
            }
            a[i] = temp;
        }
    }
}

int main()
{
    int a[10] = {7, 8, 1, 4, 9, 5, 2, 6, 3, 0}, i;
    ShellSort(a, 10);
    for(i = 0; i < 10; i++) printf("%d", a[i]);
    return 0;
}

