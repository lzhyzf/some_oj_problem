#include <stdio.h>
int main()
{
    int A, B, C, D;
    int num[31]={0},i = 0;
    scanf("%d%d%d",&A,&B,&D);
    C = A+B;
    if( C==0 ) printf("0");
    while(C){
        num[i++] = C%D;
        C = C/D;
    }
    while( i>0 ){
        printf("%d",num[--i]);
    }
    return 0;
}
