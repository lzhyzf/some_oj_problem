#include <stdio.h>

#define C 5

int x=1,y=C;

void main( )

{

  int x;

  x=y++;  printf("%d %d\n", x,y);

  if(x>4) { int x ; x=++y; printf("%d %d\n",x,y) ;  }

  x+=y--;

  printf("%d %d\n",x,y);

}
