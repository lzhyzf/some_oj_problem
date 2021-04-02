#include <stdio.h>
void fun(int (*p1)[3],int (*p2)[3]);
int main()
{
    int p1[3][3]={0} ,p2[3][3] = {0};//{7,8,9},{4,5,6},{1,2,3}};

    int i = 0, j = 0;

    for(i = 0;i < 3;i++){
        for(j = 0;j < 3;j++){
            scanf("%d",&p2[i][j]);
        }
    }

    fun(p1,p2);
    for(i = 0;i < 3;i++){
        for(j = 0;j < 3;j++){
            printf("%d ",*(*(p1+i)+j));
        }
        printf("\n");
    }


    return 0;
}
void fun(int p1[][3],int p2[][3])  //传二维数组的方法
{
    int i = 0,j = 0;

    for(i = 0;i < 3;i++){
        for(j = 0;j < 3;j++){

            *(p1[j]+i) = *(p2[i]+j);              //对于二维数组来说 p[i] 是他第i行在内存中的地址
        }
    }
}
