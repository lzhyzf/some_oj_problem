#include <stdio.h>
#include <stdlib.h>
/*要成为主元那么位置一定和排序后的位置一样，并且它一定是包含它前面数中最大的那个数*/
int cmp(const void *a, const void *b)
{
    return (*(long *)a -*(long *)b);
}

int main(){
    long a[100000], b[100000], c[100000], max = 0;
    int  i, j, N, cnt = 0;

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%ld", &a[i]);
        b[i] = a[i];
    }
    qsort(b, N, sizeof(long), cmp);
    for(i = 0; i < N; i++){
        if(a[i] > max){
            if(a[i] == b[i])
                c[cnt++] = a[i];
            max = a[i];
        }
    }
    printf("%d\n", cnt);
    for(i = 0; i < cnt; i++){
        if(i == 0) printf("%ld", c[i]);
        else printf(" %ld", c[i]);
    }
    return 0;
}
