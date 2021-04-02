#include <stdio.h>
#define MaxSize 100

struct Student
{
    char Name[11], Sn[11];
    int Grade;
}Student[MaxSize];

int main(){
    int N, i, max = 0, min = 0;

    scanf("%d", &N);
    for(i = 0; i < N; ++i){
        scanf("%s %s %d", Student[i].Name, Student[i].Sn, &Student[i].Grade);
        if (Student[max].Grade < Student[i].Grade) max = i;
        if (Student[min].Grade > Student[i].Grade) min = i;
    }
    printf("%s %s\n", Student[max].Name, Student[max].Sn);
    printf("%s %s\n", Student[min].Name, Student[min].Sn);


}
