#include <stdio.h>

int main()
{
    char a[100001], *p;
    int b[6] = {};

    gets(a);
    p = a;
    while(*p)
    {
        switch(*p)
        {
            case 'P':b[0]++; break;
            case 'A':b[1]++; break;
            case 'T':b[2]++; break;
            case 'e':b[3]++; break;
            case 's':b[4]++; break;
            case 't':b[5]++; break;
            default: break;
        }
        p++;
    }
    while(1)
    {
        if(b[0]){
            printf("P");
            b[0]--;
        }
        if(b[1]){
            printf("A");
            b[1]--;
        }
        if(b[2]){
            printf("T");
            b[2]--;
        }
        if(b[3]){
            printf("e");
            b[3]--;
        }
        if(b[4]){
            printf("s");
            b[4]--;
        }
        if(b[5]){
            printf("t");
            b[5]--;
        }
        if(b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == 0 && b[4] == 0 && b[5] == 0) break;
    }
    return 0;
}
