#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int mmax = 100;
int bin[mmax + 2];
int n, m;

struct dot
{
	double x;
	double y;
}town[mmax + 2];
struct queue
{
	int starti;
	int endi;
	double s;
}list[6000];

int fx(int r)
{
	if (r != bin[r])
	{
		bin[r] = fx(bin[r]);
	}
	return bin[r];
}

//void merge(int a, int b)
//{
//	a = fx(a);
//	b = fx(b);
//
//	bin[b] = a;
//}
double kruskal()
{
	double distance = 0;
	int count = 0;

	for (int i = 0; i < m; i++)
	{
		int a = fx(list[i].starti);
		int b = fx(list[i].endi);
		if (a != b)
		{
			//�ں�merge�Ĺ���
			distance += list[i].s;
			bin[b] = a;
			count++;
		}
		if (count == n - 1)
			return distance;
	}

	return 0.0;
}
bool comp(queue a, queue b)
{
	return a.s - b.s < 0;
}
int main()
{
	int t;
	while (scanf("%d", &t) == 1)
	{
		while (t--)
		{	
			int head = 0;
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
			{
				bin[i] = i;
			}

			for (int i = 1; i <= n; i++)
			{
				scanf("%lf%lf", &town[i].x, &town[i].y);
				for (int j = 1; j < i; j++)
				{
					//double temp = fabs(town[i].x - town[j].x)*fabs(town[i].x - town[j].x)
					//	+ fabs(town[i].y - town[j].y)*fabs(town[i].y - town[j].y);
					double temp = sqrt(pow(fabs(town[i].x - town[j].x), 2.0)
						+ pow(fabs(town[i].y - town[j].y), 2.0));
					if (temp >= 10 && temp <= 1000)
					{
						list[head].s = temp;
						list[head].starti = i;
						list[head].endi = j;
						head++;
					}
				}
			}

			m = head;
			sort(list, list + m, comp);

			double distance = kruskal()*100;
			if (!distance)
				printf("oh!\n");
			else
				printf("%.1lf\n",distance);
		}
	}

	return 0;
}