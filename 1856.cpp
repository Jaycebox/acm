//并查集+人数
#include <iostream>
#include <stdio.h>
#define MAX 200000

int bin[MAX+2];
int num[MAX+2];
int max = 0;
//int fx(int r)
//{
//    while(r != bin[r])
//        r = bin[r];
//    return r;
//}

//递归就是路径压缩
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

	//a!=b才加
	if(a != b)
		num[a] += num[b];
	if (num[a]>max)
		max = num[a];
	if (num[b]>max)
		max = num[b];

    bin[b] = a;
}

int main()
{
    int n;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			printf("1\n");
			continue;
		}
		max = 0;
        int a,b;
        for(int i = 1; i <= MAX; i++)//到n即可
        {
            bin[i] = i;
            num[i] = 1;
        }
        while(n--)
        {
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        printf("%d\n",max);
    }
    
    return 0;
}