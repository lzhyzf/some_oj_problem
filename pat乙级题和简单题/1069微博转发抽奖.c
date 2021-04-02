#include <stdio.h>
#include <string.h>

int main()
{
    int M, N, S, i, j, cnt = -1, s1 = 0;
    char name[21];
    char award[1000][21];

    scanf("%d %d %d", &M, &N, &S);
    if(S > M)
        printf("Keep going...\n");
    else{
        for(i = 1; i <= M; i++)
        {
            scanf("%s", name);
            if((++s1 - S) % N == 0 && s1 >= S){
                for(j = 0; j <= cnt; j++)
                {
                    if(strcmp(name, award[j]) == 0)
                    {
                        --s1;
                        break;
                    }
                }
                if(j == cnt + 1){
                    cnt++;
                    printf("%s\n", name);
                    strcpy(award[j], name);
                }
            }
        }
    }
    return 0;
}
