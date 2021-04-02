#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1001
#define MINH -10000

int H[MAXSIZE], size;

void Insert(int X);
void myprint(int index);

int main(){
    int N, M, i, X, index;

    scanf("%d %d", &N, &M);
    //≥ı ºªØ∂—
    size = 0;
    H[0] = MINH;
    for(i = 0; i < N; i++){
        scanf("%d", &X);
        Insert(X);
    }
    for(i = 0; i < M; i++){
        scanf("%d", &index);
            myprint(index);
    }
    return 0;
}

void Insert(int X){
    int i;

    if (size == MAXSIZE)
        return;
    else
        for(i = ++size; X < H[i/2]; i /= 2){
            H[i] = H[i/2];
        }
    H[i] = X;
}

void myprint(int index){
    int i;

    for(i = index; i>=1; i /= 2){
        if(i == index)
            printf("%d", H[i]);
        else
            printf(" %d", H[i]);
    }
    printf("\n");
}
