#include <stdio.h>
#include <stdlib.h>

int compare(const void *p, const void *q)
{
    return *(int *) q - *(int *) p;
}

int main(){
    int N, i, temp ,k = 0;
    int b[30000] = {0};                         //开300就越界了啊哈哈哈

    scanf("%d", &N);
    int a[N];
    for(i = 0; i < N; i++){
        scanf("%d", &a[i]);
        temp = a[i];
        while(temp != 1){
            if (temp % 2 == 0){
                temp /=2;
                b[temp] = 1;
            }
            else{
                temp = (3 * temp + 1) / 2;
                b[temp] = 1;
            }
        }
    }
    qsort(a, N, sizeof(int), compare);
    for(i = 0; i < N; i++){
        if(b[a[i]] == 0)
        {
            if(k == 0){
            printf("%d", a[i]);
            ++k;
            }
            else printf(" %d", a[i]);
        }
    }
    return 0;
}
