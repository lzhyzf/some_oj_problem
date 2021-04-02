#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(){
    int a[10], i, j, b[51], sum = 0;

    for(i = 0; i < 10; i++){
        scanf("%d", a + i);
        for(j = 0; j < a[i]; j++)
            b[sum++] = i;
    }
    qsort(b, sum, sizeof(int), cmp);
    if(b[0] == 0){
        for(i = 1; i < sum; i++){
            if(b[i] != 0){
                b[0] = b[i];
                b[i] = 0;
                break;
            }
        }
    }
    for(i = 0; i < sum; i++)
        printf("%d", b[i]);
    return 0;
}
