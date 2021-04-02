#include <stdio.h>

int main(){
    int N, i, j, flag = 0, sum = 0;
    char a[19];
    int b[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5 ,8, 4, 2};
    char c[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    scanf("%d", &N);
    getchar();                           //³Ôµô»»ÐÐ·û
    for(i = 0; i < N; i++){
        gets(a);
        for( j = sum = 0; j < 17; j++)
        {
            if(!(a[j] >= '0' && a[j] <= '9'))
            {
                flag = 1;
                printf("%s\n", a);
                break;
            }
            else{
                sum += ((a[j] - '0') * b[j]);
                if(j == 16)
                    if(a[17] != c[sum % 11])
                    {
                        flag = 1;
                        printf("%s\n", a);
                    }
            }
        }
    }
    if(flag == 0)
        printf("All passed");
    return 0;
}
