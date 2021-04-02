#include <stdio.h>
int abs(int a)
{
    return a > 0 ? a : -a;
}
int main()
{
    int N, temp, a[10000] = {}, i;

    scanf("%d", &N);
    for(i = 1; i <= N; i++){
        scanf("%d", &temp);
        a[abs(temp - i)]++;
    }
    for(i = 9999; i >= 0; i--)
        if(a[i] >= 2) printf("%d %d\n", i, a[i]);
    return 0;
}
