#include <stdio.h>

#define MAXSIZE 1001

typedef struct SqStack{
  int data[MAXSIZE];
  int top;
}SqStack;

int InitStack (SqStack *s);
int push (SqStack *s, int x);
int pop (SqStack *s);

int main(){
    int M, N, K, i;
    SqStack a, b;

    scanf("%d%d%d", &M, &N, &K);
    while(K--){
        InitStack (&a);
        InitStack (&b);
        for(i = N-1; i >= 0; i--){
            scanf("%d", &(b.data[i]));
        }
        b.top = N-1;
        i = 0;
        while(i <= N){
            if(a.data[a.top] == b.data[b.top] && a.top != -1){
              pop (&a);
              pop (&b);
            }
            else if(a.top < M-1 && i < N){
                i++;
                push(&a, i);
            }
            else
                break;
        }
        if(a.top == -1 && b.top == -1)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}

int InitStack (SqStack *s){
    s->top = -1;
    return 0;
}

int push (SqStack *s, int x){
    if(s->top == MAXSIZE)
        return -1;
    s->top++;
    s->data[s->top] = x;
    return 0;
}

int pop (SqStack *s){
    int e;
    if(s->top == -1)
        return -1;
       e = s->data[s->top];
       s->top--;
    return e;
}


