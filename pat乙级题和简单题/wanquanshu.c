#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,i,a,sum=0;
    scanf("%d",&m);
    i=m;
    for(; i > 1; i--){
        for(a = 1 ;a<i && i%a==0;a++)
             sum += a;
     if (sum==i){
      printf("%d",i);
      break;}
 }
 return 0;
}
