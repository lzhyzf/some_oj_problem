#include <stdio.h>

#define MAX_SIZE 100001

typedef struct Node* LNode;
struct Node
{
    int addr;
    int data;
    int next_addr;
    LNode next;
};
//��ת��������
LNode ListReverse(LNode head,int k);
//���������
void PrintList(LNode head);

int main()
{
    int first_addr,k=0;
    int n =0;
    int temp_addr;//�����ʱ����
    int i,j;
    int num;//ͳ�������ú������нڵ����Ŀ
    int Data[MAX_SIZE];//��dataֵ���ڵ�λ����Ϊ����
    int Next_addr[MAX_SIZE];//��next_addrֵ���ڵ�λ����Ϊ����
    scanf("%d %d %d",&first_addr,&n,&k);
    struct Node a[n+1];
//    ����a[0]Ϊͷ���
    a[0].next_addr = first_addr;
    for(i = 0;i<n;i++)
    {
         scanf("%d",&temp_addr);
        scanf("%d %d",&Data[temp_addr],&Next_addr[temp_addr]);
    }
    i =1;
//    ����������
    while(1)
    {
        if(a[i-1].next_addr == -1)
        {
            a[i-1].next = NULL;
            num = i-1;
            break;
        }
        a[i].addr = a[i-1].next_addr;
        a[i].data = Data[a[i].addr];
        a[i].next_addr = Next_addr[a[i].addr];
        a[i-1].next = a+i;
        i++;
    }
    //����ת������rp���ӵ�����a��
    LNode p = a;
    LNode rp = NULL;
    if(k <= num)
    {
        for (i = 0;i<(num/k);i++)
        {
            rp = ListReverse(p,k);
            p->next = rp;
            p->next_addr = rp->addr;
            for(j=0;j<k;j++)
            {
//    ������һ����Ҫ��ת���������ͷ���
                p = p->next;
            }
        }
    }
    //��ӡ����
    PrintList(a);
    return 0;

}
LNode ListReverse(LNode head,int k)
{
    int count = 1;
    LNode new1,old,temp;
    new1 = head->next;
    old = new1->next;
    while(count < k)
    {
        temp = old->next;
        old->next = new1;
        old->next_addr = new1->addr;
        new1 = old;
        old = temp;
        count ++;
    }
    head->next->next = old;
    if(old != NULL)
    {
        head->next->next_addr = old->addr;
    }
    else{
        head->next->next_addr = -1;
    }
    return new1;
}
void PrintList(LNode head)
{
    LNode p = head;
    while(p->next != NULL)
    {
        p = p->next;
        if(p->next_addr != -1)
            printf("%.5d %d %.5d\n",p->addr,p->data,p->next_addr);
        else
            printf("%.5d %d %d\n",p->addr,p->data,p->next_addr);
    }
}
