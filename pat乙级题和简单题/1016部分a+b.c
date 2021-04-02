#include <stdio.h>
#include <math.h>

int main(){
  char a[12], b[12], A, B;
  int cnt1 = 0, cnt2 = 0, PA, PB, i, sum1 = 0, sum2 = 0;

  scanf("%s %c %s %c", a, &A, b, &B);
  for(i = 0; a[i] != '\0'; i++){
    if(a[i] == A) cnt1++;
  }
  for(i = 0; b[i] != '\0'; i++){
    if(b[i] == B) cnt2++;
  }
  for(i = 0; i < cnt1; i++) sum1 += (int)(A - '0') * pow(10, i);
  for(i = 0; i < cnt2; i++) sum2 += (int)(B - '0') * pow(10, i);
  printf("%d\n", sum1 + sum2);
  return 0;
}
