//dfs，加一减一，多练，好题
//素数环
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
const int mmax = 100;
int n;
int visit[25];
int a[25];

bool isprime(int n)
{
    double k = sqrt(n);
    for(int i = 2; i<=k;i++)
    {
        if(!(n%i)) return 0;
    }
    return 1;
}
void dfs(int x)//x为循环节
{
    if(x == n && isprime(a[n-1]+1))
    {
        for(int i = 0; i< n-1; i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n-1]);        
    }
    for(int i = 2; i <= n; i++)//可以奇偶判断一下//1已有
    {
        if(visit[i] == 0)
        {
            if(isprime(a[x-1]+i))//为减一
            {
                visit[i] = 1;
                a[x] = i;
                dfs(x+1);
                visit[i] = 0;
            }
        }
    }
}

int main()
{
	int t = 0;
    memset(visit,0,sizeof(visit));
    while(scanf("%d",&n) == 1)
    {
        a[0] = 1;
		t++;
        printf("Case %d:\n",t);
        dfs(1);
        printf("\n");
    }
    
    return 0;
}