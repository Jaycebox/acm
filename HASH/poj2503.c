/*poj2503
*.c文件,编码gbk
*
*状态：尝试多次未果
*/
//#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#define ll long long
#define ull unsigned long long
//using namespace std;
const int mmax = 100002;

//int id[mmax];
char hash1[100000002][12];
bool hashbook[100000002];
//26����ĸ
ull hashx(char* p)
{
	int len = strlen(p);
	ull sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum = 26 * sum + (*p - 'a');
	}
	return sum;
}

int main()
{
	memset(hashbook, false, sizeof(hashbook));
	//memset(id,0,sizeof(id));
	char s[40];
	char a[40];
	char b[40];
	while (1)
	{
		gets(s);
		if (s[0] == '\n')
			break;
		sscanf(s, "%s %s", a, b);
		int x = hashx(b);
		for (int i = 0; i < strlen(a); i++)
		{
			hash1[x][i] = a[i];
		}
		hashbook[x] = true;
	}
	while (1)
	{
		gets(s);
		if (s[0] == '\n')
			break;
		ull x = hashx(s);
		if (hashbook[x])
		{
			printf("%s\n", hash1[x]);
		}
		else
		{
			printf("eh\n");
		}
	}

	return 0;
}