
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            int t;
            scanf("%d",&t);
            sum+=t;
        }
        int num;
        scanf("%d",&num);
        int flag = 0;
        for(int i = 0; i < num; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a <= sum && b >= sum)
            {
                flag = 1;
                break;
            }
            if(a >= sum)
            {
                flag = 1;
                sum = a;
                break;
            }
        }
        if(flag)
            printf("%d\n",sum);
        else
            printf("-1\n");
    }

	return 0;
}