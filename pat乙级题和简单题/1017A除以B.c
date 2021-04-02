#include <stdio.h>
#include <math.h>

int main(){
    char a[1001];
    int A, k = 0, rem = 0, res, temp;
    char *c = a;

    scanf("%s %d", a, &A);
    while(*c){
        temp = *c - '0' + rem * 10;
        rem = temp % A;
        res = temp / A;
        c++;
        if( k == 0 && res == 0) continue;
        else{
            k++;
            printf("%d", res);
        }
    }
    if(k == 0 && res == 0) printf("0 %d", rem);
    else printf(" %d", rem);
    return 0;
}
