#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int result;

int cmp1(const void *a, const void *b)
{
    return (*(char*)b - *(char*)a);              //��������
}

int cmp2(const void *a, const void *b)
{
    return (*(char*)a - *(char*)b);              //��������
}

void mystrcacul(char *a, char *b, char *c)
{
    result = b[3] - c[3] + 10 * (b[2] - c[2]) + 100 * (b[1] - c[1]) + 1000 *(b[0] - c[0]);
    a[0] = result % 10 + '0';
    a[1] = result % 100 / 10 + '0';
    a[2] = result % 1000 / 100 + '0';
    a[3] = result / 1000 + '0';
}

int main(){
    char a[5], b[5], c[5];

    scanf("%s", a);
    int len = strlen(a);
    while(len < 4) a[len++] = '0';
    a[len] = '\0';
    while(1)
    {
        if((a[0] == a[1]) && (a[1] == a[2]) &&(a[2] == a[3]))
        {
            printf("%s - %s = 0000", a, a);  //���4��������ȣ�����0000
            break;
        }
        qsort(a, 4, sizeof(char), cmp1);     //������a�������в����Ƶ�����b
        strcpy(b, a);
        printf("%s - ", b);
        qsort(a, 4, sizeof(char), cmp2);     //������a�������в����Ƶ�����c
        strcpy(c, a);
        printf("%s = ", c);
        mystrcacul(a, b, c);                 //���㲢�����ͽ�����浽result���ַ������浽����a
        printf("%04d\n", result);
        if(result == 6174) break;
    }
    return 0;
}
