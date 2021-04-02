#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int i, sum = 0, temp, a, b, c;
    char *bai, *shi, *ge;
    char d[102];
    char *pinyin[10] ={"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    gets(d);
    for(i = 0; d[i] !='\0'; i++){
        temp = d[i] - '0';
        sum += temp;
    }
    c = sum % 10;
    if(sum >=100){
        a = sum/100;
        b = sum%100/10;
        printf("%s %s %s", pinyin[a], pinyin[b], pinyin[c]);
    }
    else if(sum >= 10){
        b = sum/10;
        printf("%s %s", pinyin[b], pinyin[c]);
    }
    else printf("%s", pinyin[c]);
    return 0;
}
