//1250大菲波
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int mmax = 2100;

int main()
{
    char a[mmax],b[mmax],c[mmax],d[mmax],s[mmax];
    int digit;
    int n;
    while(scanf("%d",&n) != EOF)
    {
        digit = 1;
        memset(a,'0',sizeof(a));
        memset(b,'0',sizeof(b));
        memset(c,'0',sizeof(c));
        memset(d,'0',sizeof(d));
        memset(s,'0',sizeof(s));
        a[0] = b[0] = c[0] = d[0] = s[0] = '1';
		if (n <= 4)
		{
			printf("1\n");
			continue;
		}
		n -= 4;
        for(int i = 0; i < n; i++)
        {
            int flag = 0;
            for(int k = 0; k < digit; k++)
            {
                s[k] += b[k]-'0' + c[k]-'0' + d[k]-'0';
                if(s[k]>=10)
                {
                    if(k == digit-1 && (s[k]-'0') >= 10)
                        flag = 1;
                    s[k+1] += (s[k]-'0') / 10;
					s[k] = (s[k]-'0') % 10 +'0';
                }
            }
            if(flag == 1)
                digit++;
            for(int k = 0; k < digit; k++)
            {
                d[k] = c[k];
                c[k] = b[k];
                b[k] = a[k];
                a[k] = s[k];
            }
        }
        for(int i = digit-1; i >= 0; i--)
        {
            printf("%c",s[i]);
        }
        printf("\n");
    }

    return 0;
}
