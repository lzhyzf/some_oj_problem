int main()
{
    int N,i,a,x,count=0,f;
    scanf("%d",&N);
    if(N>=1&&N<=100){
    for(i=0;i<N;i++){
    scanf("%d",&x);
    f=1;
    if (x>1){
        for(a=2; a<sqrt(x);a++){
               if(x%a==0){
                f=0;
                break;}
              }
        if (f==1){
        count++;}
      }
     }
    }
    printf("%d",count);
    return 0;
}
