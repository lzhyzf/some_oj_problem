#include <stdio.h>

int main(){
    int a[129] = {}, temp, i, rem = 0, lack = 0;

    while((temp = getchar()) != '\n')
        a[temp] += 1;
    while((temp = getchar()) != '\n')
        a[temp] -= 1;
    for(i = 0; i < 129; i++)
    {
        if(a[i] > 0) rem += a[i];
        if(a[i] < 0) lack -= a[i];
    }
    if(lack > 0) printf("No %d\n", lack);
    else printf("Yes %d\n", rem);
    return 0;
}
