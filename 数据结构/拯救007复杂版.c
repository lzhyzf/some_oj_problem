#include <stdio.h>

#define MaxN 103    /* 最大顶点数设为100 */
#define R 7.5

typedef struct {
    int x, y;
}Coord;

int n, cnt = 0, temp;
int distance;
int G[MaxN][MaxN];
int d[MaxN], Path[MaxN], t[MaxN];
Coord croc[MaxN];

int Escape(int x, int y) {
    if(x < 0) x = -x;
    if(y < 0) y = -y;
    if(x + distance >= 50 || y + distance >= 50) return 1;
    else return 0;
}
int Distance(int a, int b, int c, int d) {
    return (a - c) * (a - c) + (b - d) * (b - d);
}

void SortFirst()
{//第一跳，用冒泡排序
    int i, j;
    for(i = 0; i < n; i++)
        if(Distance(croc[i].x, croc[i].y, 0, 0) <= (distance + R) * (distance + R) && Distance(croc[i].x, croc[i].y, 0, 0) >= R * R) t[cnt++] = i;
    for(i = 0; i < cnt; i++) {
        for(j = i; j < cnt; j++) {
            if(Distance(croc[t[j]].x, croc[t[j]].y, 0, 0) <  Distance(croc[t[i]].x, croc[t[i]].y, 0, 0)) {
                temp = t[j];
                t[j] = t[i];
                t[i] = temp;
            }
        }
    }
}

void BuildGraph() {
    int i, j, k;
    for(i = 0; i <= n; i++){
        d[i] = -1;
        Path[i] = -1;
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(Distance(croc[i].x, croc[i].y, croc[j].x, croc[j].y) <= distance * distance)
                G[i][j] = G[j][i] = 1;
        }
        G[i][n] = G[n][i] = Escape(croc[i].x, croc[i].y);
    }
}

void BFS(int s)
{
    int Q[MaxN], front, real, i, v;

    front = real = 0;
    Q[front++] = s;
    d[s] = 0;
    while(front != real){
        v = Q[real++];
        for(i = 0; i <= n; i++){
            if(G[v][i] == 1 && d[i] == -1){
                Q[front++] = i;
                d[i] = d[v] + 1;
                Path[i] = v;
            }
        }
    }
}

int main() {
    int i, j, k, real = 0, p;
    int stack[MaxN];
    scanf("%d %d", &n, &distance);
    for (i = 0; i < n; ++i)
        scanf("%d%d", &croc[i].x, &croc[i].y);
    if (distance >= 35) {            //如果能直接跳到岸上，直接返回结果
        printf("1\n");
        return 0;
    }
    SortFirst();
    BuildGraph();
    for(i = 0; i < cnt; i++){
        BFS(t[i]);
    }
    if (d[n] == -1) printf("0\n");
    else{
        p = Path[n];
        while(p != -1){
            stack[++real] = p;
            p = Path[p];
        }
        printf("%d\n", real + 1);
    }
    while(real){
        p = stack[real--];
        printf("%d %d\n", croc[p].x, croc[p].y);
    }
    return 0;
}
