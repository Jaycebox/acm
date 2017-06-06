#include <iostream>
#include <string.h>
using namespace std;
const int mmax = 51;
int main()
{
    int c1[mmax],c2[mmax];
    int a[27];
    int n = 50;
    int t;
    while(scanf("%d",&t) == 1)
    {
        while(t--)
        {
			memset(a, 0, sizeof(a));
            for(int i = 1; i <= 26; i++)
            {
                scanf("%d",&a[i]);
            }
            memset(c1,0,sizeof(c1));
            memset(c2,0,sizeof(c2));
            for(int i = 0; i <= a[1]; i++)
            {
                c1[i] = 1;
            }

            for(int k = 2; k <= 26; k++)
            {
                if(a[k] == 0)
                    continue;
                for(int i = 0; i <= n; i++)
                {
                    for(int j = 0; j+i <= n && j <= k * a[k]; j+=k)
                    {
                        c2[i+j] += c1[i];
                    }
                }
                for(int i = 0; i <= n; i++)
                {
                    c1[i] = c2[i];
                    c2[i] = 0;
                }
            }
			int sum = 0;
			for (int i = 1; i <= 50; i++)
			{
				sum += c1[i];
			}
            printf("%d\n",sum);
        }
    }
    return 0;
}