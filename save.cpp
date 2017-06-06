//感谢高神，仰望高神，高神给我力量，德玛西亚
//前面没有第三，后面没有第一

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a[4][4];

    while(1)
    {
        int flag = 0;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        for(int i = 0; i < 4; i++)
        {
            if(a[i][3] == 1)
            {
                int next = i+1;
                if(next == 4) next = 0;
                int pre = i-1;
                if(pre == -1) pre = 3;
                
                if(a[next][0] == 1 || a[pre][2] == 1)
                    flag = 1;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}