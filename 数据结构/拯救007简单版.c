    #include <stdio.h>
    #include <math.h>
    typedef struct {
        double x, y;
    }Coord;
    int reachCenter(double distance, Coord point) {     //�ж�һֻ�����Ƿ��ܴӵ���һ������
        return (15 + distance)*(15 + distance) >= point.x*point.x + point.y*point.y;
    }
    int reachBetween(double distance, Coord p1, Coord p2) { //�ж���ֻ������ܷ�һ������
        return distance*distance >= (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    }
    int reachBank(double distance, Coord p) {           //�жϴ��������ͷ���ܷ���������
        return p.x <= -50 + distance || p.x >= 50 - distance || p.y >= 50 - distance || p.y <= -50 + distance;
    }
    int DFS(double distance, Coord *croc, int v, int *visited, int n) {     //�ݹ������������������ҵ�·������1
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
        if (distance >= 35) {            //�����ֱ���������ϣ�ֱ�ӷ��ؽ��
            printf("Yes\n");
            return 0;
        }
        Coord croc[102];                //�������������
        for (int i = 0; i < n; ++i)
            scanf("%lf%lf", &croc[i].x, &croc[i].y);
        int visited[100] = {};          //�ڵ��ѷ��ʱ��
        int flag = 0;                   //�Ƿ����ҵ�·�����
        for (int i = 0; i < n; ++i)
            if (!visited[i] && reachCenter(distance, croc[i])) {    //�����ܴӵ���һ������������
                visited[i] = 1;
                if (DFS(distance, croc, i, visited, n)) {           //�ӵ�ǰ���㿪ʼ�����������
                    printf("Yes\n");
                    flag = 1;
                    break;
                }
            }
        if (flag == 0)
            printf("No\n");

        return 0;
    }
