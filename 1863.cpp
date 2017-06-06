//a畅通工程,还是畅通工程加一个判断
//krusal
#include <iostream>
#include <stdio.h>
#include <algorithm>
const int mmax=100;
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
    while(scanf("%d%d",&m,&n) == 2 && m)
    {
        for(int i = 1; i <= n; i++)
        {
            bin[i] = i;
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&r1[i].start,&r1[i].end,&r1[i].s);
        }

        sort(r1+1,r1+m+1,comp);

		int num = 0;
		int flag = 0;
        int distance = krusal();//bin好了
		for (int i = 1; i <= n; i++)
		{
			if (bin[i] == i)
				num++;
			if (num > 1)
			{
				flag = 1;
				break;
			}
		}

		if (flag)
		{
			printf("?\n");
		}
		else
			printf("%d\n",distance);
    }

    return 0;
}