#include <stdio.h>

int main(){
    int index, coefficient, k = 0;

    while (scanf("%d%d", &coefficient, &index) != EOF)
    {
        if(k == 0 && index == 0) printf("0 0");
        if(index == 0) break;
        if(coefficient == 0) continue;
        if(k == 0){
            printf("%d %d", coefficient * index , index - 1);
            k++;
        }
        else printf(" %d %d", coefficient * index , index - 1);
    }
    return 0;
}
