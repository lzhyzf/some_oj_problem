#include <stdio.h>

int myisspace(char a)
{
    if (a == ' ') return 1;
    else return 0;
}

int main()
{
    char line[81], *p = line, *i;
    gets(line);

    while(*p++);                                       //惯用法，遍历数组
    while(p > line)
    {
        while(myisspace(*--p)) ;                          /* find the end of a word */
        while(p > line && !myisspace(*(p - 1))) p--;      /* find the start of the word */
        for(i = p; *i && !myisspace(*i); putchar(*i++));  /* print the word */
        putchar(p == line ? '\0' : ' ');
    }

    return 0;
}
