#include <stdio.h>
#include <string.h>
int strdel(char *s)
{ int i,count=0, j=0;
  char a[80];

  for(i=0;s[i]!='\0';i++)
  {
      if(s[i] == ' '){
          count++;
          continue;
      }
      a[j++] = s[i];
  }
  a[j] = '\0';
  strcpy(s, a);
    return count;
}
int main()
{
    char s[80],count;
    printf("Please input a string:\n");
    gets(s);
    count=strdel(s);
    printf("字符串中的空格个数为:%d\n",count);
    printf("删除空格后字符串变为:\n");
    puts(s);
    return 0;
}
