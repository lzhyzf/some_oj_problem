#include <stdio.h>
#include <stdlib.h>

int main()
{
    char hand[100][10], eye[100][10], mouth[100][10], a[1000], *p;
    int i, hands, eyes, mouths, N, t1, t2, t3, t4, t5;

    hands = mouths = eyes = 0;
    gets(a);
    p = a;
    while(*p)
    {
        if(*p == '[')
        {
            hands++;
            i = 0;
        }
        else if(*p == ']')
            hand[hands][i++] = '\0';
        else
            hand[hands][i++] = *p;
        p++;
    }
    gets(a);
    p = a;
    while(*p)
    {
        if(*p == '[')
        {
            eyes++;
            i = 0;
        }
        else if(*p == ']')
            eye[eyes][i++] = '\0';
        else
            eye[eyes][i++] = *p;
        p++;
    }
    gets(a);
    p = a;
    while(*p)
    {
        if(*p == '[')
        {
            mouths++;
            i = 0;
        }
        else if(*p == ']')
            mouth[mouths][i++] = '\0';
        else
            mouth[mouths][i++] = *p;
        p++;
    }
    scanf("%d", &N);
    for(i = 0; i < N ; i++)
    {
        scanf("%d %d %d %d %d", &t1, &t2, &t3, &t4, &t5);
        if((t1 > 0 && t1 <= hands) && (t2 > 0 && t2 <= eyes) && (t3 > 0 && t3 <= mouths) && (t4 > 0 && t4 <= eyes) && (t5 > 0 && t5 <= hands))
            printf("%s(%s%s%s)%s\n", hand[t1], eye[t2], mouth[t3], eye[t4], hand[t5]);
        else
            printf("Are you kidding me? @\\/@\n");
    }
    return 0;
}
