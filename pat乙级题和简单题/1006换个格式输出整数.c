#include <stdio.h>

int main(){
    int bai, shi, ge, temp, i;

    scanf("%d", &temp);
    ge = temp % 10;
    if(temp >= 100)
    {
        bai = temp / 100;
        shi = temp % 100 / 10;
        for(i = 0; i < bai; i++)
            printf("B");
        for(i = 0; i < shi; i++)
            printf("S");
        for(i = 1; i <= ge; i++)
            printf("%d", i);
    }
    else if(temp >= 10)
    {
        shi = temp / 10;
        for(i = 0; i < shi; i++)
            printf("S");
        for(i = 1; i <= ge; i++)
            printf("%d", i);
    }
    else
    {
        for(i = 1; i <= ge; i++)
            printf("%d", i);
    }
    return 0;
}
