#include <stdio.h>
#define CLK_TCK 100
int main(){
    int c1, c2, time, hour, min, sec;

    scanf("%d %d", &c1, &c2);
    time = (c2 - c1 + 50) / CLK_TCK;               //处理四舍五入的方法加50
    hour = time /3600;
    min = time %3600 / 60;
    sec = time % 60;
    printf("%02d:%02d:%02d", hour, min, sec);
    return 0;
}
