#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        char str[110];
        int np=0,nt=0,other=0,lp,lt;
        scanf("%s",str);
        int len=strlen(str);
        for(int i=0;i<len;i++){                     //��¼P,T��������ĸ�ĸ����Լ�P��T��λ��
            if(str[i]=='P'){
                np++;
                lp=i;
            }else if(str[i]=='T'){
                nt++;
                lt=i;
            }else if(str[i]!='A')
                other++;
        }
        if((np!=1)||(nt!=1)||(other!=0)||(lt-lp<=1)){//P��T�ĸ�������Ϊһ��û��������ĸ��P��T�м�������һ��A
            printf("NO\n");
            continue;
        }
        int x=lp,y=lt-lp-1,z=len-lt-1;
        if(x*y==z)
        printf("YES\n");
        else printf("NO\n");
    }
    return 0;

}

