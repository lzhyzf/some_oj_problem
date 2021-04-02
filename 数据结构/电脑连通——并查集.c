 #include <stdio.h>

 #define MaxN 10001                  /* �������Ԫ�ظ��� */

 typedef int ElementType;           /* Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ */
 typedef int SetName;               /* Ĭ���ø��ڵ��±���Ϊ�������� */
 ElementType SetType[MaxN]; /* ���輯��Ԫ���±��1��ʼ */

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
             if(Find(SetType,computerA) == Find(SetType,computerB)) { //�Ƿ���ͬһ����
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
 /* ����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ���� */
 void Union( ElementType S[], SetName Root1, SetName Root2 )
 {
     /* ��֤С���ϲ���󼯺� */
     if ( S[Root2] < S[Root1] ) { /* �������2�Ƚϴ� */
         S[Root2] += S[Root1];     /* ����1���뼯��2  */
         S[Root1] = Root2;
     }
     else {                         /* �������1�Ƚϴ� */
         S[Root1] += S[Root2];     /* ����2���뼯��1  */
         S[Root2] = Root1;
     }
 }

 SetName Find( ElementType S[], ElementType X )
 { /* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 */
     if ( S[X] < 0 ) /* �ҵ����ϵĸ� */
         return X;
     else
         return S[X] = Find( S, S[X] ); /* ·��ѹ�� */
 }
