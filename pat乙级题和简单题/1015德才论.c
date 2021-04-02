#include <stdio.h>
#include <stdlib.h>

struct decailun
{
    int number;
    int de;
    int cai;
};

int cmp(const void *b, const void *a)
{
    struct decailun *c = (struct decailun *)a;
    struct decailun *d = (struct decailun *)b;
    int ret = 0;

    if((c->de + c->cai) != (d->de + d->cai))
    {
        ret = (c->de + c->cai) - (d->de + d->cai);
    }
    else if(c->de != d->de)
    {
        ret = (c->de) - (d->de);
    }
    else
        ret = (d->number) - (c->number);
    return ret;
}

int main(){
    int N, L ,H, i, num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    struct decailun input;
    scanf("%d %d %d", &N, &L, &H);
    struct decailun first[N], second[N], third[N], fourth[N];
     for(i=0;i<N;i++)
    {
        scanf("%d %d %d",&input.number,&input.de,&input.cai);
        if(input.de>=L&&input.cai>=L)
        {
            if(input.de>=H&&input.cai>=H)
            {
                first[num1]=input;
                num1++;
            }else if(input.de>=H)
            {
                second[num2]=input;
                num2++;
            }else if(input.de>=input.cai)
            {
                third[num3]=input;
                num3++;
            }else
            {
                fourth[num4]=input;
                num4++;
            }
        }
    }
    qsort(first, num1, sizeof(struct decailun), cmp);
    qsort(second, num2, sizeof(struct decailun), cmp);
    qsort(third, num3, sizeof(struct decailun), cmp);
    qsort(fourth, num4, sizeof(struct decailun), cmp);
    printf("%d\n", num1 + num2 + num3 + num4);
    for(i = 0; i < num1; i++) printf("%d %d %d\n", first[i].number, first[i].de, first[i].cai);
    for(i = 0; i < num2; i++) printf("%d %d %d\n", second[i].number, second[i].de, second[i].cai);
    for(i = 0; i < num3; i++) printf("%d %d %d\n", third[i].number, third[i].de, third[i].cai);
    for(i = 0; i < num4; i++) printf("%d %d %d\n", fourth[i].number, fourth[i].de, fourth[i].cai);
    return 0;
    }

