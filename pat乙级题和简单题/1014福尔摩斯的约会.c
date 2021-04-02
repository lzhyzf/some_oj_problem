#include <stdio.h>              //有段错误，未能发现在哪里
#include <stdlib.h>

int main(){
    char a[61], b[61], c[61], d[61];
    int i, count = 0;

    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    scanf("%s", d);
    for(i = 0; ; i++){
        if(count == 2) break;
        if((count == 1) && (a[i] == b[i]) && (('A' <= a[i] && 'N' >= a[i]) || ('0' <= a[i] && '9' >= a[i]))){
            count = 2;
            if('0' <= a[i] && '9' >= a[i]) printf("0%s", a[i]);
            else printf("%d", a[i] - 'A' + 10);
        }
        if((count == 0) && (a[i] == b[i]) && ('A' <=a[i] && 'G' >= a[i])){
            count = 1;
            switch(a[i]){
                case 'A': printf("MON ");break;
                case 'B': printf("TUE ");break;
                case 'C': printf("WED ");break;
                case 'D': printf("THU ");break;
                case 'E': printf("FRI ");break;
                case 'F': printf("SAT ");break;
                case 'G': printf("SUN ");break;
            }
        }
    }
    for(i = 0; ; i++){
        if(c[i] == d[i] && ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z')))
        {
            if(i >= 0 && i <= 9) {
                printf(":0%d", i);
                break;
            }
            else {
                printf(":%d", i);
                break;
            }
        }
    }
    return 0;

}
