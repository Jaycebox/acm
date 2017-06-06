//bfs
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int mmax = 20;
int n, m;
char map[mmax + 5][mmax + 5];
struct dot
{
	int x;
	int y;
}queue[5000];

int bfs(int startx, int starty)
{
	int step = 1;
	int head = 0, tail = 0;
	queue[head].x = startx;
	queue[head].y = starty;
	int next[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };

	while (head <= tail)
	{
		int x = queue[head].x;
		int y = queue[head].y;
		for (int k = 0; k < 4; k++)
		{
			int xx = x + next[k][0];
			int yy = y + next[k][1];
			if (xx <= 0 || yy <= 0 || xx > n || y > m)
				continue;
			if (map[xx][yy] == '.')
			{
				tail++;
				queue[tail].x = xx;
				queue[tail].y = yy;
				map[xx][yy] = '#';
				step++;
			}
		}
		head++;
	}
	return step;
}

int main()
{
	int startx, starty;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		memset(map, 0, sizeof(map));
        //不初始化死全家系列
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= n; i++)
		{
			getchar();
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &map[i][j]);			
               
				if (map[i][j] == '@')
				{
					startx = i;
					starty = j;
				}
			} 
		}
        map[startx][starty] = '#';
		int step = bfs(startx, starty);
		printf("%d\n", step);
	}

	return 0;
}