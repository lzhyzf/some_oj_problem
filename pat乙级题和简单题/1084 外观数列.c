//1 11 12 1121 122111 112213 12221131 1123123111
#include <stdio.h>
#include <string.h>
int main()
{
  char a[100000], b[100000];
  int N, i, len, j, cnt, temp;

  scanf("%s %d", a, &N);
  for(i = 0; i < N - 1; i++)
  {
    len = strlen(a);
    for(j = 0, temp = 0; j < len; j++){
        cnt = 1;
        while(a[j] == a[j + 1]){
            cnt++;
            j++;
        }
        b[temp++] = a[j]; b[temp++] = cnt + '0';
    }
    b[temp] = '\0';
    strcpy(a, b);
  }
  printf("%s", a);
  return 0;
}
