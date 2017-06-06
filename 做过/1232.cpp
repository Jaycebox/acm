//畅通工程
//老大数减一
#include <iostream>
#include <string.h>
#define mmax 1000

using namespace std;

int bin[mmax+2];
int fx(int r)
{
    if(bin[r] != r)
        bin[r] = fx(bin[r]);
    return bin[r];
}
void merge(int a,int b)
{
    a = fx(a);
    b = fx(b);

    if(b != a)
        bin[b] = a;
}
int main()
{
    int m,n;
    while(scanf("%d",&m) == 1)
    {
		if (m == 0)
			break;
		scanf("%d", &n);
		for (int i = 1; i <= m; i++)
			bin[i] = i;
		
        for(int i = 1; i <= n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            merge(a,b);
        }

        int count = 0;
        for(int i = 1; i <= m; i++)
        {
            if(bin[i] == i)
            {
                count++;
            }
        }
        printf("%d\n",count-1);
    }

    return 0;
}