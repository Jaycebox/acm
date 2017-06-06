#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int mmax = 100;

int bin[mmax + 2];
int s[mmax + 2];
int n, m;
struct dot
{
	int start;
	int end;
	int f;
}town[6000];
int fx(int r)
{
	if (r != bin[r])
		bin[r] = fx(bin[r]);
	return bin[r];
}
int kruskal()
{
	int fare = 0;
	int count = 0;

	for (int i = 0; i < m; i++)//headwei0
	{
		int a = fx(town[i].start);
		int b = fx(town[i].end);

		if (a != b)
		{
			bin[b] = a;
			fare += town[i].f;
			count++;
		}

	}
	return 999;
}
int comp(dot a, dot b)
{
	return a.f < b.f;
}
int main()
{
	//int n;
	//fruskal要用
	while (scanf("%d", &n) == 1, n)
	{
		for (int i = 1; i <= n; i++)
		{
			bin[i] = i;
			s[i] = 1;
		}
		int head = 0;
		over = 0;
		for (int i = 1; i <= n; i++)
		{
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if (d == 0)
			{
				//town[head] = { a,b,c };
				town[head].start = a;
				town[head].end = b;
				town[head].f = c;
				head++;
			}
			else
			{
				int p = fx(a);
				int q = fx(b);
				if (p != q)
				{
					bin[q] = p;
				}
			}
		}

		m = head;
		sort(town, town + m, comp);

		int fare = kruskal();

		printf("%d\n", fare);
	}

	return 0;
}