#include <stdio.h>
#include <string.h>

int main(){
    char a[81], b[81], *p, *q;
    int visited[129] = {};            //visited���飬128��ASCII��

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
                if (*p >= 'a' && *p <= 'z'){                              //����ҵ�����������û�������Сд��ĸ�������д��ĸ��������visited�����еĴ�Сд��
                    printf("%c", *p + 'A'- 'a');
                    visited[*p + 'A' - 'a'] = visited[*p] = 1;
                }
                else if(*p >= 'A' && *p <= 'Z')
                {                                                         //����ҵ�����������û������Ĵ�д��ĸ�������������visited�����еĴ�Сд��
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
