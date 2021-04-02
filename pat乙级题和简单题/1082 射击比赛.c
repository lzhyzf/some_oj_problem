#include <stdio.h>

int main()
{
    int N, maxid, minid, max = 0, min = 10000, dis, i, id, x, y;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d %d %d", &id, &x, &y);
        dis = x*x + y*y;
        if(dis > max){
            max = dis;
            maxid = id;
        }
        if(dis < min){
            min = dis;
            minid = id;
        }
    }
    printf("%04d %04d", minid, maxid);
    return 0;
}
