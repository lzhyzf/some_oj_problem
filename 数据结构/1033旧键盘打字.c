#include <stdio.h>

int main(){
    int huai[129] = {};    //�洢�����ļ����±���ASCII��intֵ����������Ϊ1��û��Ϊ0
    int i, flag = 0, temp;
    char a[100001];

    while((temp = getchar()) != '\n')
    {
        if(temp >='A' && temp <= 'Z')
        {
            huai[temp] = 1;
            huai[temp - 'A' + 'a'] = 1;
        }
        else if(temp >='a' && temp <= 'z')
        {
            huai[temp] = 1;
            huai[temp + 'A' - 'a'] = 1;
        }
        else
            huai[temp] = 1;
    }
    while((temp = getchar()) != '\n')
    {
        if(temp >='A' && temp <= 'Z')
        {
            if(huai[temp] == 0 && huai['+'] == 0) putchar(temp);
        }
        else
        {
            if(huai[temp] == 0) putchar(temp);
        }
    }
    printf("\n");
    return 0;
}
