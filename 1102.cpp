// 法一
//kruskal算法
//老是错，。。。
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int mmax=10000;
int bin[mmax+2];
int n,m;
int k;
struct road
{
    int s;//记录村庄间的距离 
    int start;//线路起点 
    int end;//终点 
}town[mmax+2];
int fx(int r)
{
	if(r!=bin[r])
		bin[r] = fx(bin[r]);
	return bin[r];
}
void merge(int a,int b)
{
    // 改了
    a = fx(a);
    b = fx(b);
    if(a !=  b)
        bin[b] = a;
} 
bool comp(road a,road b)
{
    return a.s<b.s;
}
//不能count
//搞死我了
int kruskal()
{
	int distance = 0;
	for(int i = 0; i < m; i++)
	{
		int a = fx(town[i].start);
		int b = fx(town[i].end);
		if(a != b)
		{
			merge(a,b);
			distance += town[i].s;
		}
	}
	return distance;
}
int main()
{
    int d;//村庄数和相互间的距离 
    int i,j,x,y;
    int head;
    while(scanf("%d",&n)!=EOF)
    {
        head = 0;
        for(i=1;i<=n;i++)
        {
            bin[i]=i;
            for(j=1;j<=n;j++)
            {
                scanf("%d",&d);
                if(j>i)
                {
                    town[head].start=i;
                    town[head].end=j;
                    town[head].s=d;
                    head++;
                }
            }
        }

        scanf("%d",&k);
        for(int i = 1; i <= k; i++)
        {
            scanf("%d%d",&x,&y);
            merge(x,y);//合并已有道路 
        }

        m = head;
        sort(town,town+m,comp);//排序 

        int distance = kruskal();
		printf("%d\n", distance);      

    }
    return 0;
}

// 法二
// prime算法
#include <iostream>
#include <stdio.h>
using namespace std;

const int mmax = 100;
const int INF = 0x3f3f3f;
int n,m;
int map[mmax+2][mmax+2];
int visit[mmax+2];
int dis[mmax+2];

int prime()
{
    int min;
    int mincost = 0;
    int next;
    memset(visit,0,sizeof(visit));
    //初始化
    for(int i = 1; i <= n; i++)
    {
        dis[i] = map[1][i];
    }
    visit[1] = 1;

    for(int i = 1; i < n; i++)//n-1次
    {
        min = INF;
        for(int j = 1; j <= n; j++)
        {
            if(!visit[j] && min > dis[j])
            {
                min = dis[j];
                next = j;
            }
        }
        mincost += min;
        visit[next] = 1;
        //优化全部
        for(int j = 1; j <= n; j++)
        {
            if(!visit[j] && dis[j] > map[next][j])
            {
                dis[j] = map[next][j];
            }
        }
    }
    return mincost;
}

int main()
{
    while(scanf("%d",&n) == 1)
    {
        memset(map,INF,sizeof(map));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        scanf("%d",&m);
        for(int i = 1; i <= m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            map[a][b] = map[b][a] = 0;
        }
        int distance = prime();
        printf("%d\n",distance);
    }

    return 0;
}