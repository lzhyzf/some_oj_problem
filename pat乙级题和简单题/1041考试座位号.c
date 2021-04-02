#include <stdio.h>

struct Student
{
    long rn;
    int tn, en;
}Stu[1001];

int main(){
    int i, N, tn, en;
    long rn;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%ld %d %d", &rn, &tn, &en);
        Stu[tn].rn = rn;                                     //以测试机号为索引存入结构数组
        Stu[tn].tn = tn;
        Stu[tn].en = en;
    }
    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &tn);
        printf("%ld %d\n", Stu[tn].rn, Stu[tn].en);
    }
    return 0;
}
