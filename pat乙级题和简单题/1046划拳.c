#include <stdio.h>

int main(){
    int N, i, a1, a2, b1, b2, jia = 0, yi = 0;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
        if(a2 == b2) continue;
        else if(a2 == (a1 + b1)) yi++;
        else if(b2 == (a1 + b1)) jia++;
    }
    printf("%d %d", jia, yi);
    return 0;

}
