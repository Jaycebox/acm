//测试数据有毒
//youdu
//dfs

#include <iostream>
#include <stdio.h>
using namespace std;
const int mmax = 100;
char map[mmax+2][mmax+2];
int n, m;

void dfs(int x,int y)
{
    int k;
	int xx, yy;
	int next[8][2] = { {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };

    for(int k = 0; k < 8; k++)
    {
        xx = x + next[k][0];
        yy = y + next[k][1];
        if(map[xx][yy] == '*')
            continue;
        if(xx <= 0 || yy <= 0 || xx > n || yy > m)
            continue;
		map[xx][yy] = '*';
        dfs(xx,yy);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m) == 2)
    {
        if(n == 0 && m == 0)
            break;

        for(int i = 1; i <= n; i++)
        {
			char ch = getchar();
            for(int j = 1; j <= m; j++)
            {
                scanf("%c",&map[i][j]);
            }
        }
        int count = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(map[i][j] == '@')
				{
					map[i][j] = '*';
					dfs(i,j);
					count++;
				}
            }
        }

        printf("%d\n",count);
    }

    return 0;
}