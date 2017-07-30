//树状数组第一题，可以当做模板了

#include <iostream>
#include <cstring>

using namespace std;
const int mmax = 50002;
int a[50002];
int n;

int lowbit(int k)
{
    return k&(-k);
}

void add(int x, int i)
{
    while(i <= n)
    {
        a[i] += x;
        i += lowbit(i);
    }
}

void sub(int x,int i)
{

    while(i <= n)
    {
        a[i] -= x;
        i += lowbit(i);
    }
}//其实只要abb(-x,i);

int sum(int i)
{
    int s = 0;
    while(i >= 1)
    {
        s += a[i];
        i -= lowbit(i);
    }
    return s;
}   

int query(int a, int b)
{
    return sum(b)-sum(a-1);//注意包含左端点
}

int main()
{
    int t;

    while(scanf("%d",&t) == 1)
    {
        int tt = 1;
        while(t--)
        {
            memset(a,0,sizeof(a));
            scanf("%d",&n);
            for(int i = 1; i <= n; i++)
            {
                int temp;
                scanf("%d",&temp);
                add(temp,i);
            }
            int aa,bb;
            char order[10];
            printf("Case %d:\n",tt++);
            while(1)
            {
                scanf("%s",order);
				getchar();
				
				if(order[0] == 'E')
					break;
				scanf("%d%d", &aa, &bb);
                if(order[0] == 'A')
                    add(bb,aa);
                else if(order[0] == 'S')
                    sub(bb,aa);
                else if(order[0] == 'Q')
                    printf("%d\n",query(aa,bb));
            }
        }
    }

    return 0;
}