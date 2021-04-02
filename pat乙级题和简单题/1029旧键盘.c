#include <stdio.h>
#include <string.h>

int main(){
    char a[81], b[81], *p, *q;
    int visited[129] = {};            //visited数组，128个ASCII码

    gets(a);
    gets(b);
    p = a;
    q = b;
    while(*p)
    {
        if(*p == *q)
        {
            p++;
            q++;
        }
        else
        {
            if(visited[*p] == 0)
                if (*p >= 'a' && *p <= 'z'){                              //如果找到坏键并且是没输出过的小写字母则输出大写字母，并调整visited数组中的大小写；
                    printf("%c", *p + 'A'- 'a');
                    visited[*p + 'A' - 'a'] = visited[*p] = 1;
                }
                else if(*p >= 'A' && *p <= 'Z')
                {                                                         //如果找到坏键并且是没输出过的大写字母则输出，并调整visited数组中的大小写；
                    printf("%c", *p);
                    visited[*p + 'a' - 'A'] = visited[*p] = 1;
                }
                else
                {
                    printf("%c", *p);
                    visited[*p] = 1;
                }
            p++;
        }
    }
    return 0;
}
