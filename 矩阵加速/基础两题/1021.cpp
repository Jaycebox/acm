//不管，先膜高神。
//另：F(a+b+1)=F(a+1)*F(b+1)+F(a)*F(b)
#include <iostream>
#include <string.h>
using namespace std;

const int mmax = 100;
struct matrix
{
    int a[15][15];
};
matrix mat1;
matrix mat2;

matrix fun(matrix mat1,matrix mat2,int mod)
{
    matrix T;
    memset(T.a,0,sizeof(T.a));
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                T.a[i][j] = (T.a[i][j]+mat1.a[i][k]*mat2.a[k][j]%mod)%mod;
            }
        }
    }
    return T;
}

int main()
{
    int aa = 11,bb = 7;
    int n;
    int mod = 3;
    int result;
    while(scanf("%d",&n) == 1)
    {
        mat1.a[0][0] = 1;mat1.a[0][1] = 1;
        mat1.a[1][0] = 1;mat1.a[1][1] = 0;
        mat2.a[0][0] = 1;mat2.a[0][1] = 1;
        mat2.a[1][0] = 1;mat2.a[1][1] = 0;

        if(n == 0)printf("no\n");
        else if(n == 1)printf("no\n");
        else
        {
            n = n-2;
            while(n!=0)
            {
                if(n&1)
                    mat1 = fun(mat1,mat2,mod);
                mat2 = fun(mat2,mat2,mod);
                n>>=1;
            }
            result = (aa*mat1.a[0][0]+bb*mat1.a[0][1])%mod;
            if(result%3 == 0)printf("yes\n");
            else if(result%3>0)printf("no\n");
        }
    }

    return 0;
}