#include <stdio.h>
#define ABS(X) ((X) >= 0 ? (X) : -(X))

int main(){
    int i, j, N, m, cnt = 0;
    char c;

    scanf("%d %c", &N, &c);
    for(m = 1; 2*m*m - 1 <= N; m++); m--; //�ҵ�M�׵�ɳ©
    for(i = 1; i <= 2*m - 1; i++){                     //��ӡ2m-1��
        for(j = 0; j < m - 1 - ABS(i - m); j++) printf(" ");                 //��ӡm - 1��ȥi��m����Ŀո�
        for(j = 0; j < 2 * ABS(m - i) + 1; j++) {printf("%c", c); cnt++;}           //��ӡ2*m��i���� + 1 ������
        printf("\n");
    }
    printf("%d", N - cnt);
    return 0;
}
