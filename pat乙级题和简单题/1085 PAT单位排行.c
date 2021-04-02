#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct School
{
    char name[7];
    int score, parnum, scorea, scoreb, scoret;
}S[100000];

int cmp(const void *a, const void *b)
{
    struct School *c = (struct School *)a;
    struct School *d = (struct School *)b;

    if(c->score == d->score){
        if(c->parnum == d->parnum) return strcmp(c->name, d->name);
        else return c->parnum - d->parnum;
    }
    else return d->score - c->score;
}

int main()
{
    int N, score, schcnt = 0, i, j, rank = 1;
    char regnum[7], schname[7], *p;
    scanf("%d", &N);
    for(i = 0; i < N; i++){//对N个学生进行处理
        scanf("%s %d %s", regnum, &score, schname);//读入他们的准考证号，分数，学校
        p = schname;
        while(*p){//将学校全部改为小写
            if(*p >= 'A' && *p <= 'Z') *p -= ('A' - 'a');
            p++;
        }
        for(j = 0; j < schcnt; j++){//找到该学生学校
            if(strcmp(S[j].name, schname) == 0){
                S[j].parnum++;
                if(regnum[0] == 'A') S[j].scorea += score;
                if(regnum[0] == 'B') S[j].scoreb += score;
                if(regnum[0] == 'T') S[j].scoret += score;
                break;
            }
        }
        if(j == schcnt){//没找到学校
            strcpy(S[schcnt].name, schname);
            S[schcnt].parnum = 1;
            S[schcnt].score = S[schcnt].scorea = S[schcnt].scoreb = S[schcnt].scoret = 0;
            if(regnum[0] == 'A') S[schcnt].scorea += score;
            if(regnum[0] == 'B') S[schcnt].scoreb += score;
            if(regnum[0] == 'T') S[schcnt].scoret += score;
            schcnt++;
        }
    }
    for(i = 0; i < schcnt; i++)
        S[i].score = S[i].scorea + S[i].scoreb / 1.5 + S[i].scoret * 1.5;
    qsort(S, schcnt, sizeof(struct School), cmp);
    printf("%d\n", schcnt);
    score = S[0].score;
    for(i = 0; i < schcnt; i++){
        if(S[i].score == score)
            printf("%d %s %d %d\n", rank, S[i].name, S[i].score, S[i].parnum);
        else{
            rank = i + 1;
            score = S[i].score;
            printf("%d %s %d %d\n", rank, S[i].name, S[i].score, S[i].parnum);
        }
    }
    return 0;
}
