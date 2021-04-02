    #include <stdio.h>
    #include <math.h>
    typedef struct {
        double x, y;
    }Coord;
    int reachCenter(double distance, Coord point) {     //判断一只鳄鱼是否能从岛上一步跳至
        return (15 + distance)*(15 + distance) >= point.x*point.x + point.y*point.y;
    }
    int reachBetween(double distance, Coord p1, Coord p2) { //判断两只鳄鱼间能否一步跳到
        return distance*distance >= (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    }
    int reachBank(double distance, Coord p) {           //判断从这个鳄鱼头上能否跳到岸上
        return p.x <= -50 + distance || p.x >= 50 - distance || p.y >= 50 - distance || p.y <= -50 + distance;
    }
    int DFS(double distance, Coord *croc, int v, int *visited, int n) {     //递归进行深度优先搜索，找到路径返回1
        if (reachBank(distance, croc[v]))
            return 1;
        for (int i = 0; i < n; ++i)
            if (!visited[i] && reachBetween(distance, croc[v], croc[i])) {
                visited[i] = 1;
                if (DFS(distance, croc, i, visited, n))
                    return 1;
            }
        return 0;
    }
    int main() {
        int n;
        double distance;
        scanf("%d%lf", &n, &distance);
        if (distance >= 35) {            //如果能直接跳到岸上，直接返回结果
            printf("Yes\n");
            return 0;
        }
        Coord croc[102];                //保存鳄鱼的坐标
        for (int i = 0; i < n; ++i)
            scanf("%lf%lf", &croc[i].x, &croc[i].y);
        int visited[100] = {};          //节点已访问标记
        int flag = 0;                   //是否已找到路径标记
        for (int i = 0; i < n; ++i)
            if (!visited[i] && reachCenter(distance, croc[i])) {    //遍历能从岛上一步跳到的鳄鱼
                visited[i] = 1;
                if (DFS(distance, croc, i, visited, n)) {           //从当前鳄鱼开始深度优先搜索
                    printf("Yes\n");
                    flag = 1;
                    break;
                }
            }
        if (flag == 0)
            printf("No\n");

        return 0;
    }
