    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    #define Naxsize 1000

    void solve(int Aleft, int Aright,int TRoot, int A[],int T[]);
    int compare(const void *a, const void *b);
    int Get_Left_Nodes(int n);
    int Min(int a, int b);



    int main()
    {
        //一共多少个节点
        int N;
        scanf("%d\n",&N);
        //接收收入的节点
        int A[N],T[N];
        for(int i = 0; i < N; i++)
        {
            scanf("%d",&A[i]);
        }
        //调整为完全二插搜索树,

        //排序成中序遍历
        qsort(A,N,sizeof(int),compare);
        int ALeft = 0, ARight = N -1, TRoot = 1;
        solve(ALeft, ARight, TRoot, A, T);

        //输出
        for (int i = 1; i <= N; ++i){
            if(i == 1){
                printf("%d", T[i]);
            }
            else
                printf(" %d", T[i]);
        }

        return 0;
    }

    int compare(const void *a, const void *b)
    {
        return *(int*)a - *(int*)b;
    }


    void solve(int Aleft, int Aright, int TRoot,int A[],int T[])
    {
        /*初始调用为*solve(0,N-1,0)*/
        int n;
        //看这里面还有元素嘛
        n = Aright - Aleft+1;
        if(n == 0)
        {
            return;
        }
        //计算出n个节点的树其左子树有多少个节点
        int L,LeftRoot,RightRoot;
        L = Get_Left_Nodes(n);
        T[TRoot] = A[Aleft + L];//根节点的值
        //在堆里面，开始的下标是1，0不存在真实值，所以左儿子是2i，这里是2i+1
        LeftRoot = TRoot * 2;
        RightRoot = LeftRoot + 1;
        solve(Aleft,Aleft+L-1,LeftRoot,A,T);
        solve(Aleft+L+1,Aright,RightRoot,A,T);
    }

    int Get_Left_Nodes(int n)
    {
        int H = 1, temp, L = 0;
        int N = n;
        while(N > 1){
            N /= 2;
            H++;//树的高度
        }
        temp = pow(2, H - 2) - 1;
        if ((n - (pow(2, H - 1) - 1)) <= (pow(2, H - 2)))
            L = temp + n - (pow(2, H - 1) - 1);
        else
            L = temp + pow(2, H - 2);
        return L;
    }
