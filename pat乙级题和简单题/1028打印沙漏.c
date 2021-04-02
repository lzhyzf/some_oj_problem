#include <stdio.h>
#define ABS(X) ((X) >= 0 ? (X) : -(X))

int main(){
    int i, j, N, m, cnt = 0;
    char c;

    scanf("%d %c", &N, &c);
    for(m = 1; 2*m*m - 1 <= N; m++); m--; //找到M阶的沙漏
    for(i = 1; i <= 2*m - 1; i++){                     //打印2m-1排
        for(j = 0; j < m - 1 - ABS(i - m); j++) printf(" ");                 //打印m - 1减去i到m距离的空格
        for(j = 0; j < 2 * ABS(m - i) + 1; j++) {printf("%c", c); cnt++;}           //打印2*m到i距离 + 1 的星星
        printf("\n");
    }
    printf("%d", N - cnt);
    return 0;
}
