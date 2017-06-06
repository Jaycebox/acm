#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

//法一
//有几个老大
//tree是有向图
#include <stdio.h>

#define MAX 10000

int bin[MAX + 5];
int book[MAX + 5];
int in[MAX + 5];
int wrong = 0;
int fx(int r)
{
	while (r != bin[r])
		r = bin[r];
	return r;
}
void merge(int a, int b)
{
	a = fx(a);
	b = fx(b);

	if (a == b)
		wrong = 1;
	else
		bin[b] = a;
}
int main()
{
	int a, b;
	int first;
	int t = 0;

	while (scanf("%d%d", &a, &b) == 2)
	{
		//初始化
		if (a < 0 && b < 0)
			break;
		for (int i = 1; i <= MAX; i++)
		{
			book[i] = 0;
			bin[i] = i;
			in[i] = 0;
		}

		//读取
		while (1)
		{
			if (a == 0 && b == 0)
				break;
			book[a] = 1;
			book[b] = 1;

			//入度
			in[b]++;
			if (in[b] > 1)
				wrong = 1;

			merge(a, b);
			first = a;
			scanf("%d%d", &a, &b);
		}

		//处理
		//可以直接遍历，有几个father，只能有一个。直接遍历连wrong都不用。对1325不行
		//可以搞个count表示处理了几个，前面还要判断一下重复的
		//可以搞个one，就比较每一个的老大是不是它，不是就break;
		first = fx(first);
		for (int i = 1; i <= MAX; i++)
		{
			if (wrong)
				break;
			if (book[i] == 0)
				continue;
			if (fx(i) != first)
			{
				wrong = 1;
				break;
			}
		}

		if (wrong != 1)
			printf("Case %d is a tree.\n", ++t);
		else
			printf("Case %d is not a tree.\n", ++t);
		wrong = 0;
	}

	return 0;
}

//法二：
//判断是不是树，只要节点等于边+1；同时每个节点的入度小于2；
//可惜不能两棵树