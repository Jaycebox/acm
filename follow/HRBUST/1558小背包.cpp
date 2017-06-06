#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int mmax = 100000;

struct item
{
	int val;
	int w;
};
item a[mmax];

int main()
{
	int v,n;
	int dp[mmax];
	while(scanf("%d%d",&v,&n) == 2)
	{
		//提前判断
		if(v>16*2012)
			v = 16*2012;
		memset(dp,0,sizeof(dp));
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d",&a[i].w,&a[i].val);
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = v;j >= a[i].w;j--)
			{
				if(dp[j-a[i].w]+a[i].val > dp[j])
					dp[j] = dp[j - a[i].w] + a[i].val;
			}
		}
		printf("%d\n",dp[v]);
	}

	return 0;
}