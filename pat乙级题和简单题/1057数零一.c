#include <stdio.h>

int main()
{
    int i, sum = 0, rem, n1 = 0, n0 = 0;
    char a[100001], *p;

    gets(a);
    p = a;
    while(*p)
    {
        if(*p >= 'a' && *p <= 'z')
            sum += (*p - 'a' + 1);
        else if(*p >= 'A' && *p <= 'Z')
            sum += (*p - 'A' + 1);
        p++;
    }
    while(sum)
    {
        rem = sum % 2;
        if(rem == 1)
            n1++;
        else
            n0++;
        sum /= 2;
    }
    printf("%d %d", n0, n1);
    return 0;
}
