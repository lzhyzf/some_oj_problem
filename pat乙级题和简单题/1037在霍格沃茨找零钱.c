#include <stdio.h>

long ABS(long A)
{
    return A < 0? - A: A;
}

int main(){
    long G1, S1, K1, G2, S2, K2, G3, S3, K3;

    scanf("%ld.%ld.%ld", &G2, &S2, &K2);
    scanf("%ld.%ld.%ld", &G1, &S1, &K1);
    K3 = G1*17*29 + S1*29 + K1 -(G2*17*29 + S2*29 + K2);
    if(K3 < 0)
    {
        printf("-");
        K3 = ABS(K3);
    }
    G3 = K3 / (17*29);
    S3 = (K3 - G3*17*29) / 29;
    K3 = K3 - G3*17*29 - S3*29;
    printf("%ld.%ld.%ld", G3, S3, K3);
}
