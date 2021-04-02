#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float stock, priv;           //库存，总价，单价
    float tolprice;
}YueBing;

int cmp(const void *a, const void *b)
{
    if(((YueBing *)b)->priv == ((YueBing *)a)->priv) return 0;
    else return ((YueBing *)b)->priv > ((YueBing *)a)->priv ? 1: -1;  //降序排列,！！！注意此时计算的是float型，而返回值要求int！！！会有误差！
}

int main(){
    int N, D, i;
    float sum = 0, profit = 0;

    scanf("%d%d", &N, &D);
    YueBing Y[N];
    for(i = 0; i < N; i++)
        scanf("%f", &Y[i].stock);

    for(i = 0; i < N; i++){
        scanf("%f", &Y[i].tolprice);
        Y[i].priv = Y[i].tolprice / Y[i].stock;
    }
    qsort(Y, N, sizeof(YueBing), cmp);
    for(i = 0; i < N; i++){
        if(sum + Y[i].stock > D)
        {
            profit += (D - sum) * Y[i].priv;
            break;
        }
        else{
            sum += Y[i].stock;
            profit += Y[i].tolprice;
        }
    }
    printf("%.2f", profit);
    return 0;
}
