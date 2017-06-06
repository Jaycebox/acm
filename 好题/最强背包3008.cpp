//气死
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int mmax = 105;

struct item
{
	int val;
	int w;
};
item a[mmax];
int main()
{
	int n, t, q;
	int dp[mmax][mmax];
	int flag = 0;
	while (scanf("%d%d%d", &n, &t, &q) == 3)
	{
		if (!n && !t && !q)
			break;

		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i].w, &a[i].val);
		}
		//把死的时间背
		int dead = 100 / q;
		if (100 % q != 0)
			dead++;

		//背包剪枝
		memset(dp, -1, sizeof(dp));
		dp[0][100] = 0;

		flag = 0;//判断
		for (int i = 1; i <= dead; i++)
		{
			for (int j = 0; j <= 100; j++)
			{
				if (dp[i - 1][j] == -1)//剪枝
					continue;
				for (int k = 0; k < n; k++)
				{
					if (j - a[k].w < 0)
						continue;

					int temp = j - a[k].w + t;
					if (temp > 100)
						temp = 100;
					
					if (dp[i][temp] < dp[i - 1][j] + a[k].val)
						dp[i][temp] = dp[i - 1][j] + a[k].val;
					if (dp[i][temp] >= 100)
					{
						 if(i>dead)
						     printf("My god\n");
						 else
						     printf("%d\n",i);
						 flag = 1;
						 break;
					}
				}
				if (flag)
					break;
				//普通攻击
				int tempp = j + t;
				if (tempp > 100)
					tempp = 100;
				if (dp[i - 1][j] + 1 > dp[i][tempp])
					dp[i][tempp] = dp[i - 1][j] + 1;
				if (dp[i][tempp] >= 100)
				{
					 if(i>dead)
					     printf("My god\n");
					 else
					     printf("%d\n",i);
					 flag = 1;
					 break;
				}
			}
			if (flag)
				break;
		}
		if (!flag)
			printf("My god\n");
	}
	return 0;
}