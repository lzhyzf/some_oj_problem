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
//反转单链表函数
LNode ListReverse(LNode head,int k);
//输出单链表
void PrintList(LNode head);

int main()
{
    int first_addr,k=0;
    int n =0;
    int temp_addr;//输入的时候用
    int i,j;
    int num;//统计链表建好后，链表中节点的数目
    int Data[MAX_SIZE];//存data值，节点位置作为索引
    int Next_addr[MAX_SIZE];//存next_addr值，节点位置作为索引
    scanf("%d %d %d",&first_addr,&n,&k);
    struct Node a[n+1];
//    设置a[0]为头结点
    a[0].next_addr = first_addr;
    for(i = 0;i<n;i++)
    {
         scanf("%d",&temp_addr);
        scanf("%d %d",&Data[temp_addr],&Next_addr[temp_addr]);
    }
    i =1;
//    将链表串起来
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
    //将反转的链表rp连接到数组a中
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
//    移向下一段需要反转的子链表的头结点
                p = p->next;
            }
        }
    }
    //打印链表
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
