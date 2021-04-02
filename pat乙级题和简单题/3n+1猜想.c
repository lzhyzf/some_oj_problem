#include <stdio.h>

int main(){
    int X, n = 0;

    scanf("%d", &X);
    while(X != 1){
        if(X % 2 == 0)
            X /= 2;
        else
            X = (3 * X + 1) / 2;
        ++n;
    }
    printf("%d", n);
    return 0;
}

