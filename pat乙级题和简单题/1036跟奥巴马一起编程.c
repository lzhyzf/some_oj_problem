#include <stdio.h>

int main(){
    int N, i, j;
    char a;

    scanf("%d %c", &N, &a);
    for(i = 1; i <= (N + 1) / 2; i++)           //行数,下标从1开始
    {
        if(i == 1 || i == (N + 1) / 2 ){
            for(j = 0; j < N; j++)
                printf("%c", a);
            printf("\n");
        }
        else
        {
            for(j = 0; j < N; j++)
                if(j == 0 || j == N - 1) printf("%c", a);
                else printf(" ");
            printf("\n");

        }
    }
    return 0;
}
