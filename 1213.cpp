#include<iostream>
#include<stdio.h>
using namespace std;

//并查集裸题
int bin[1002];
int findx(int r)
{
	while (bin[r] != r)
		r = bin[r];//别忘了
	return r;
}
void merge(int a, int b)
{
	a = findx(a);
	b = findx(b);
	bin[a] = b;
}
int main()
{
	int t;
	int n, m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			bin[i] = i;
		}
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			merge(a, b);
		}
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			if (bin[i] == i)
				count++;
		}
		printf("%d\n", count);
	}

	return 0;
}