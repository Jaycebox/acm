#include <iostream>
#include <string.h>

using namespace std;
const int mmax = 101;
int main()
{
    int c1[mmax];
    int c2[mmax];
    struct num
    {
        int min;
        int max;
    }a[mmax];
    int n,m;

    while(scanf("%d%d",&n,&m) != EOF)
    {
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        memset(a,0,sizeof(a));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d",&a[i].min,&a[i].max);
        }
		for (int i = a[1].min; i <= a[1].max; i++)
		{
			c1[i] = 1;
		}
        
        for(int k = 2; k <= n; k++)
        {
            // for(int i = a[k].min; i <= a[k].max; i++)
            // {
            //     for(int j = 0; j+i <= m; j++)
            //     {
			// 		if (c1[j] == 0)
			// 			continue;
            //         c2[i+j] += c1[i];
            //     }
            // }
            for(int i=0;i<=m;i++)//与c1匹配
			{
				for(int j=a[k].min;j+i<=m && j<=a[k].max;j++)
				{
					c2[j+i]+=c1[i];   
				}
			}
            for(int i = 0; i <= 100; i++)
            {
                c1[i] = c2[i];
                c2[i] = 0;
            }
        }

        printf("%d\n",c1[m]);
    }
    return 0;
}