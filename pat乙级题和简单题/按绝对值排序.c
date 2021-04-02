#include <stdio.h>

int abs_val(int x);

int main(void)
{
  int a[10], n, temp, i, j;

  scanf("%d", &n);
  for (i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  /* Ã°ÅÝÅÅÐò */
  for (i = n - 1; i >= 1; --i) {
    for (j = 0; j < i; ++j) {
      if (abs_val(a[j]) > abs_val(a[j + 1])) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }

  for (i = 0; i < n; ++i)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}

int abs_val(int x)
{
  return x > 0 ? x : -x;
}
