#include <stdio.h>

int main(){
    char a[1001], *p;
    int b[129] = {}, i, max = 0, index = 0;

    gets(a);
    p = a;
    while(*p)
    {
        if(*p >= 'A' && *p <= 'Z')
            b[*p - 'A' + 'a'] += 1;
        else if(*p >= 'a' && *p <= 'z')
            b[*p] += 1;
        p++;
    }
    for(i = 128; i >= 0; i--)
        if(b[i] >= max) {
            max = b[i];
            index = i;
        }
    printf("%c %d", index, max);
    return 0;
}
