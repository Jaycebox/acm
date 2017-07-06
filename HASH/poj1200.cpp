//hash第一题
#include <iostream>
#include <cstdio>

using namespace std;
const int mmax = 16000002;

bool hash1[mmax];
char a[mmax];
int id[500];

int main()
{
	int n, nc;
	while (scanf("%d%d", &n, &nc) == 2)
	{
		memset(hash1, false, sizeof(hash1));
		memset(id, -1, sizeof(id));
		scanf("%s", a);
		int len = strlen(a);
		int cnt = 0;
		for (int i = 0; i < len; i++)
		{
			if (id[a[i]] != -1)continue;
			id[a[i]] = cnt++;
		}//给每个不同字符编号

		int count = 0;
		for (int i = 0; i < len - n + 1; i++)
		{
			int s = 0;
			for (int j = i; j < i + n; j++)
			{
				s = s * nc + id[a[j]];//变成nc位数
				//printf("%d ", id[a[j]]);
			}
			//printf("\n%d\n", s);
			if (hash1[s])
			{
				continue;
			}
			count++;
			hash1[s] = true;
		}
		printf("%d\n", count);
	}


	return 0;
}