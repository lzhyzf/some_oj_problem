#include<stdio.h>
int main()
{
    int n,m,a[100][100],i,j;
    int max=0,min=100,maxx,maxy,minx,miny;
    double sum=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<n+1;i++)
    for(j=1;j<m+1;j++)
        scanf("%d",&a[i][j]);
        for(i=1; i<n+1; i++)
        for(j=1; j<m+1; j++){
        if(a[i][j]>max){
        max=a[i][j];
        maxx=i;
        maxy=j;}
        if(a[i][j]<min){
        min=a[i][j];
        minx=i;
        miny=j;}
        sum+=a[i][j];}
        sum=sum/(n*m);
        printf("%d %d %d\n",max,maxx,maxy);
        printf("%d %d %d\n",min,minx,miny);
        printf("%.2lf",sum);
        return 0;
}
