 #include <stdio.h>

main(){

    int i,j,n=0,a[31][31]={0};

    scanf("%d",&n);
    for(i = 0;i < n; i++)
    a[i][0]=1; /*��һ��ȫ��Ϊһ*/

    for(i = 1;i < n;i++)
        for(j = 1;j <= i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];/*ÿ��������������֮��*/
    for(i = 0;i < n;i++) /*����������*/
        { for(j = 0;j <= i;j++)
                 printf("%d ",a[i][j]);
             printf("\n");
}
}
