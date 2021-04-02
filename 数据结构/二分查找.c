#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};

Position BinarySearch( List L, ElementType X );

int main()
{
    List L = {"12, 31, 55, 89, 20",
               4};
    ElementType X;
    Position P;

    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

Position BinarySearch( List L, ElementType X )
{
  int left = 1;
  int right = L->Last;
  int middle = 0;

  while(left <= right){
    middle = (left+right) / 2;
    if(L->Data[middle] = X)
      return middle;
    else if (L->Data[middle] < X)
      left = middle + 1;
    else if (L->Data[middle] > X)
      right = middle - 1;
}
  return NotFound;
}



}
