#include<stdio.h>
#define MaxTree 10
#define Null -1     //��Null����Ϊ-1��������0����Ϊ�����±�Ϊ0�ĵط��Ա����нڵ�
typedef char ElementType;
typedef int Tree;
struct TreeNode{    //����������ڵ�
    ElementType Data;
    Tree Left;
    Tree Right;
}T1[MaxTree],T2[MaxTree];
int N,check[MaxTree];   //check��������Ѱ�����ĸ��ڵ�

Tree BuildTree(struct TreeNode T[]){
    int Root=Null,i;    //�տ�ʼ���ڵ���Ϊ�գ���Ϊ������ʱ��ɷ���Null
    char cl,cr;
    scanf("%d",&N);
    if(N){              //�����Ϊ�����Ļ�
        for(i=0;i<N;i++) check[i]=0;    //��check������Ϊ0
        for(i=0;i<N;i++){
            scanf("\n%c %c %c",&T[i].Data,&cl,&cr); //�ѻ��з�����ǰ��Ե�ǰ��scanf��Ļس��������һ��scanf�����лس���һ������
            if(cl!='-'){
                T[i].Left=cl-'0';
                check[T[i].Left]=1;
            }
            else
                T[i].Left=Null;

            if(cr!='-'){
                T[i].Right=cr-'0';
                check[T[i].Right]=1;
            }
            else
                T[i].Right=Null;

        }
        for(i=0;i<N;i++)
            if(!check[i])   break;
        Root=i;
    }
    return Root;
}
int Isomorphic(Tree R1,Tree R2){
    if((R1==Null)&&(R2==Null))      //���Ϊ��������ͬ����
        return 1;
    if(((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null)))//���һ��Ϊ��һ����Ϊ������ͬ����
        return 0;
    if((T1[R1].Data)!=(T2[R2].Data))//������ݲ�ͬ����ͬ����
        return 0;
    //�������Ӷ�Ϊ���ж��Ҷ����Ƿ�ͬ������Ҫ�������������棨1���Ҷ����Ƿ�Ϊ�գ�2���Ƿ�һ�����Ҷ���һ��û�У�3���Ҷ��������Ƿ���ͬ
    if((T1[R1].Left==Null)&&(T2[R2].Left==Null))
        return Isomorphic(T1[R1].Right,T2[R2].Right);
    /* �������������Ӷ���Ϊ�ղ������ݻ���һ���ģ�������ӽ��еݹ�*/
    if ( ((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&((T1[T1[R1].Left].Data)==(T2[T2[R2].Left].Data)) )
        return ( Isomorphic( T1[R1].Left, T2[R2].Left )&&Isomorphic( T1[R1].Right, T2[R2].Right ) );
    /* �������������ӣ�һ����һ�����ջ��߶����գ��������ݲ�һ������ô�жϵ�һ���������ң������Ƿ���ڶ��������ң��󣩶���ͬ�� */
    else
        return ( Isomorphic( T1[R1].Left, T2[R2].Right)&&Isomorphic( T1[R1].Right, T2[R2].Left ) );

}
int main(){
    Tree R1,R2;     //���Ƚ�����������R1��R2Ϊ���ĸ��ڵ�
    R1=BuildTree(T1);
    R2=BuildTree(T2);
    if(Isomorphic(R1,R2))   //Isomorphic�����ж��Ƿ�ͬ��
        printf("Yes\n");
    else printf("No\n");
    return 0;
}
