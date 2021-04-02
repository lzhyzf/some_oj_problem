#include <stdio.h>
/*要想知道构成多少个PAT，那么遍历字符串后对于每一A，
它前面的P的个数和它后面的T的个数的乘积就是能构成的PAT的个数。
然后把对于每一个A的结果相加即可~~辣么就简单啦
只需要先遍历字符串数一数有多少个T~~然后每遇到一个T呢~countt–;每
遇到一个P呢，countp++;然后一遇到字母A呢就countt * countp~~~
把这个结果累加到result中~~~~最后输出结果就好啦~~对了别忘记要对10000000007取余哦~~~~*/
int main(){
    char s[100001], *a;
    int np = 0, nt = 0;
    long cnt = 0;

    a = s;
    gets(s);
    while(*a){
        if(*a == 'T') nt++;
        a++;
    }
    a = s;
    while(*a)
    {
        if(*a == 'P') np++;
        if(*a == 'T') nt--;
        if(*a == 'A') cnt += np*nt;
        a++;
    }
    printf("%ld", cnt % 1000000007);
    return 0;
}
