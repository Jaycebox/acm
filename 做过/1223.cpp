//还是畅通工程
//krusal
//bin作为一种辅助
#include <iostream>
#include <stdio.h>
#include <algorithm>
const int mmax=10000;
using namespace std;
int bin[mmax+2];
int n;
int m;
/*int fx(int r)  
{  
    if(bin[r]==r) return r;  
	  return bin[r]=fx(bin[r]);  
} */
//还是我的快
struct road
{
    int start;
    int end;
    int s;
}r1[mmax];
int fx(int r)
{
	if (r != bin[r])
		bin[r] = fx(bin[r]);
	return bin[r];
}
void merge(int a,int b)
{
    a = fx(a);
    b = fx(b);

    if(a!=b)
        bin[b] = a;
}
int krusal()
{
    int distance = 0;
	int count = 0;
    for(int i = 1; i <= m;i++)
    {
        if(fx(r1[i].end) != fx(r1[i].start))
        {
            distance+=r1[i].s;
            merge(r1[i].start,r1[i].end);
			count++;
        }
		if (count == n - 1)
			break;
    }

    return distance;
}
int comp(road a,road b)
{
    return a.s<b.s;
}
int main()
{
    while(scanf("%d",&n) == 1 && n)
    {
        m = n*(n-1)/2;
        for(int i = 1; i <= n; i++)
        {
            bin[i] = i;
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&r1[i].start,&r1[i].end,&r1[i].s);
        }

        sort(r1+1,r1+m+1,comp);

        printf("%d\n",krusal());
    }

    return 0;
}