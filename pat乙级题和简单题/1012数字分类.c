#include <stdio.h>
#include <math.h>

int main(){
    int i, N, temp, SumA1 = 0, SumA2 = 0, A2Num = 0, A3Num = 0, A4Num = 0, max = 0;
    double SumA4 = 0;

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &temp);
        if((temp % 5 == 0) && (temp % 2 == 0)) SumA1 += temp;
        if(temp % 5 == 1){
            SumA2 += (pow(-1, A2Num) * temp);
            ++A2Num;
        }
        if(temp % 5 == 2) ++A3Num;
        if(temp % 5 == 3){
            SumA4 += temp;
            ++A4Num;
        }
        if((temp % 5 == 4) && temp > max) max = temp;
    }
    if (SumA1 == 0) printf("N");
    else printf("%d", SumA1);
    if (SumA2 == 0) printf(" N");
    else printf(" %d", SumA2);
    if (A3Num == 0) printf(" N");
    else printf(" %d", A3Num);
    if (SumA4 == 0) printf(" N");
    else printf(" %.1f", SumA4/A4Num);
    if (max == 0) printf(" N");
    else printf(" %d", max);
    return 0;
}
