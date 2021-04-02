#include <stdio.h>
#include <string.h>

int main()
{
    int i, carry = 0, temp = 0, m[21], b[21], c[21], d[21], len1, len2, flag;
    char a[25], *A;

    a[0] = '0';
    gets(a + 1);
    len1 = strlen(a);
    for(A = a + len1 - 1; A != a - 1; A--)
    {
        if(*A == '0') m[temp++] = 10;
        else m[temp++] = *A - 48;
    }
    gets(a);
    len2 = strlen(a);
    for(A = a + len2 - 1, temp = 0; A != a - 1; A--)
        b[temp++] = *A - 48;
    for(i = 0; i < len1 - len2; i++)
        b[temp++] = 0;
    gets(a);
    len2 = strlen(a);
    for(A = a + len2 - 1, temp = 0; A != a - 1; A--)
        c[temp++] = *A - 48;
    for(i = 0; i < len1 - len2; i++)
        c[temp++] = 0;
    for(i = 0; i < len1; i++)
    {
        d[i] = (carry + b[i] + c[i]) % m[i];
        carry = (carry + b[i] + c[i]) / m[i];
    }
    for(i = len1 - 1, flag = 0; i >= 0; i--)
    {
        if(d[i] != 0) flag = 1;
        if(flag) printf("%d", d[i]);
    }
    if(!flag)
        printf("0");
    return 0;
}
