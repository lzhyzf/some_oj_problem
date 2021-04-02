#include <stdio.h>

int main(){
    int N, i;
    long int a, b, c;

    scanf("%d", &N);
    for(i = 1; i <= N; i++){
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a + b > c) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
    return 0;
}
