#include <stdio.h>
#include <stdlib.h>

int main(){
    char jia, yi;
    int maxindex1 = 0, maxindex2 = 0, jiawin[3] = {}, yiwin[3] = {},cnt = 0;
    int N, i;
    char a[3] = {'C', 'J', 'B'};

    scanf("%d", &N);
    getchar();                   //！！！！后面是读一个字符，所以一定要清掉空格，不然会被读成空格！！！
    for(i = 0; i < N; i++){
        scanf("%c %c", &jia, &yi);
        getchar();                       //同理！！！
        if(jia == 'C' && yi == 'J') jiawin[0]++;
        if(jia == 'J' && yi == 'B') jiawin[1]++;
        if(jia == 'B' && yi == 'C') jiawin[2]++;
        if((jia == 'C' && yi == 'C') || (jia == 'J' && yi == 'J') || (jia == 'B' && yi == 'B')) cnt++;
        if(jia == 'C' && yi == 'B') yiwin[2]++;
        if(jia == 'J' && yi == 'C') yiwin[0]++;
        if(jia == 'B' && yi == 'J') yiwin[1]++;
    }
    printf("%d %d %d\n", jiawin[0]+jiawin[1]+jiawin[2], cnt, yiwin[0]+yiwin[1]+yiwin[2]);
    printf("%d %d %d\n", yiwin[0]+yiwin[1]+yiwin[2], cnt, jiawin[0]+jiawin[1]+jiawin[2]);
    for(i = 0; i <= 2; i++){
        if(jiawin[i] == jiawin[maxindex1] && a[i] < a[maxindex1]) maxindex1 = i;
        else if(jiawin[i] > jiawin[maxindex1]) maxindex1 = i;
    }
    for(i = 0; i <= 2; i++){
        if(yiwin[i] == yiwin[maxindex2] && a[i] < a[maxindex2]) maxindex2 = i;
        else if(yiwin[i] > yiwin[maxindex2]) maxindex2 = i;
    }
    printf("%c %c", a[maxindex1], a[maxindex2]);
    return 0;
}
