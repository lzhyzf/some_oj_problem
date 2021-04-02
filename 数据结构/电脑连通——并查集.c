 #include <stdio.h>

 #define MaxN 10001                  /* 集合最大元素个数 */

 typedef int ElementType;           /* 默认元素可以用非负正数表示 */
 typedef int SetName;               /* 默认用根节点下标作为集合名称 */
 ElementType SetType[MaxN]; /* 假设集合元素下标从1开始 */

 void Union( ElementType S[], SetName Root1, SetName Root2 );
 SetName Find( ElementType S[], ElementType X );

 int main()
 {
     int N;
     int computerA,computerB;
     scanf("%d",&N);
     for(int i = 0; i <= N; i++)
         SetType[i] = -1;
     char operation;
     scanf("%c",&operation);
     while(operation != 'S') {
         if(operation == 'I') {                    //inputting a connection
             scanf("%d %d",&computerA, &computerB);
             Union(SetType,Find(SetType,computerA), Find(SetType,computerB));
         }else if(operation == 'C') {            //check
             scanf("%d %d",&computerA, &computerB);
             if(Find(SetType,computerA) == Find(SetType,computerB)) { //是否是同一个根
                 printf("yes\n");
             }else {
                 printf("no\n");
             }
        }
         scanf("%c",&operation);
     }
     int components = 0;
     for(int i = 1; i <= N; i++) {
         if(SetType[i] < 0)
             components++;
     }
     if(components == 1)
         printf("The network is connected.\n");
     else
         printf("There are %d components.\n",components);
     return 0;
 }
 /* 这里默认Root1和Root2是不同集合的根结点 */
 void Union( ElementType S[], SetName Root1, SetName Root2 )
 {
     /* 保证小集合并入大集合 */
     if ( S[Root2] < S[Root1] ) { /* 如果集合2比较大 */
         S[Root2] += S[Root1];     /* 集合1并入集合2  */
         S[Root1] = Root2;
     }
     else {                         /* 如果集合1比较大 */
         S[Root1] += S[Root2];     /* 集合2并入集合1  */
         S[Root2] = Root1;
     }
 }

 SetName Find( ElementType S[], ElementType X )
 { /* 默认集合元素全部初始化为-1 */
     if ( S[X] < 0 ) /* 找到集合的根 */
         return X;
     else
         return S[X] = Find( S, S[X] ); /* 路径压缩 */
 }
