#include <stdio.h>
#include <string.h>

int main(){
    char str[10010];
    int pos = 0, i, exp = 0, cnt = 0;

    gets(str);
    if(str[0] == '-') printf("-");
    int len = strlen(str);
    while(str[pos] != 'E') pos++;                   //找到E的位置
    for(i = pos + 2; i < len; i++) exp = exp * 10 + str[i] - '0';                      //求出指数
    if(exp == 0)
        for(i = 1; i < pos; i++) printf("%c", &str[i]);
    if (str[pos + 1] == '-'){                           //科学计数法是乘以十的负数次方，那么最终结果一定是小数
        printf("0.");
        for(i = 0; i < exp - 1; i++) printf("0");   //一开始0的个数
        printf("%c", str[1]);
        for(i = 3; i < pos; i++) printf("%c", str[i]);
    }
    else{
        for(i = 1; i < pos; i++){
        if(str[i] == '.') continue;
        printf("%c", str[i]);
        if(i == exp+2&& pos - 1 > i){
            printf(".");
        }
    }
        for(i = 0;i < exp- (pos - 3);i++){
            printf("0");
    }
    }
    return 0;
}
