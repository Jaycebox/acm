#include<iostream>

using namespace std;
const int mmax = 100;
typedef long long ll;

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
int quickpower(int a,int b,int n)
{
    int ans = 1;
    a = a % n;
    while (b)
    {
        if (n&1)
            ans = ans * a % n;
        b =b/ 2;
        a = a * a % c;
    }
    return t1;
}
int quickpower(matrix a,matrix b,int n)
{
    while (b)
    {
        if (n&1)
            a = fun(a,b,n);
        b = fun(b,b,n);
        n>>= 1;
    }
    return t1;
}
int main()
{
    int result;
    int r1,r2,r3;
    int t;
    int a,b,n,p;
    while(scanf("%d",&t) == 1)
    {
        while(t--)
        {
            scanf("%d%d%d%d",&a,&b,&n,&p);
            int mod = p;
            r1 = (quickpower(a,(p-1)/2)+1,mod)%mod;
            r2 = (quickpower(b,(p-1)/2)+1,mod)%mod;
            if(!r1||!r2)
            {
                printf("0\n");
                continue;
            }
            mat1.a[0][0] = 2*(a+b);mat1.a[0][1] = 0;
            mat1.a[1][0] = 2      ;mat1.a[1][1] = 0;
            mat2.a[0][0] = 2*(a+b);mat2.a[0][1] = -(a-b)*(a-b);
            mat2.a[1][0] = 1      ;mat2.a[1][1] = 0;

            quickpower(mat1,mat2,mod);
            
        }
    }


    return 0;
}