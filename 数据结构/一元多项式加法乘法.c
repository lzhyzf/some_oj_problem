#include <stdio.h>

struct Poly{
    int co;
    int ex;
}Poly[1000];

int main()
{
    int a, b, i, j, A[2000] = {0}, B[1000] = {0};
    int temp1, temp2;

    scanf("%d", &a);
    for(i = 0; i < a; i++){
        scanf("%d%d", &Poly[i].co, &Poly[i].ex);
        B[Poly[i].ex] = Poly[i].co;
    }

    scanf("%d", &b);
    for(i = 0; i < b; i++){
        scanf("%d%d", &temp1, &temp2);
        B[temp2] += temp1;
        for(j = 0; j < a; i++)
            A[Poly[j].ex + temp2] = temp1 * Poly[j].co;
    }

    int flag = 0, isfirst = 1;

    for(i = 1000; i >= 0; i--){
          if(A[i]!= 0){
            if(!isfirst)    printf(" %d %d",A[i],i);
            if(isfirst){
                isfirst = 0;
                printf("%d %d",A[i],i);
            }
            flag = 1;
        }
    }
    if (flag = 0)
        printf("0 0");
    putchar('\n');
    flag = 0, isfirst = 1;
    for(i = 1000; i >= 0; i--){
          if(B[i] != 0){
            if(!isfirst)    printf(" %d %d",B[i],i);
            if(isfirst){
                isfirst = 0;
                printf("%d %d",B[i],i);
            }
            flag = 1;
        }
    }
    if (flag = 0)
        printf("0 0");
        return 0;
}
