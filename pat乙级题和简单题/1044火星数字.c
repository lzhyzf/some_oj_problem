#include<stdio.h>
#include<string.h>

int main(){
    char lownum[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    char highnum[13][5] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int N;
    scanf("%d", &N);
    getchar();
    for(int i=0; i<N; ++i){
        char str[10];
        gets(str);
        if(str[0]>='0' && str[0]<='9'){
            int num = 0;
            for(int j=0; str[j]!='\0'; ++j){
                num = num*10 + str[j] - '0';
            }
            if(num/13){
                if(num%13){
                    printf("%s ", highnum[num/13]);
                    printf("%s\n", lownum[num%13]);
                }else{
                    printf("%s\n", highnum[num/13]);
                }
            }else{
                printf("%s\n", lownum[num%13]);
            }
        }else{
            int num = 0;
            for(int j=1; j<13; ++j){
                if( strstr(str, highnum[j]) ){                    //char *strstr（char *str1， char *str2）函数，判断str2是否为str1的子串，是的话返回在str1中的首地址，不是返回NULL
                    num += 13*j;
                    break;
                }
            }
            for(int j=0; j<13; ++j){
                if( strstr(str, lownum[j]) ){
                    num += j;
                    break;
                }
            }
            printf("%d\n", num);
        }
    }

    return 0;
}
