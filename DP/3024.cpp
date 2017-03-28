/*
大家都已经学过了01背包问题,现在这个问题稍微有一些变化:
第i种物品可能有pi个,你可以选取任意个(小于pi).给定背包容量m,求背包能达到的最大价值.

第1行有2个整数n, m,表示要有n种物品,背包容量为m
第2到n+1行,每行三个整数pi, wi, vi, 分别表示该种物品有pi个, 每个物品重wi, 价值为vi

输出一个数字, 表示背包能达到的最大价值.

对于80%的数据, 1<=n<=1000, 1<=m<=1000, 1<=sumP=p1+p2+...+pn<=2000
对于100%的数据, 1<=N<=1000, 1<=m<=1000, 1<=pi<=1000
*/

#include <iostream>
#include <cstdio>

using namespace std;

int c[1000000], v[1000000], a[1000000];

int main()
{
    int n, m, signum, i, allnum=0, j, tmp, tmp1, tmp2, tmp3, first, lef;
    bool b[11];

    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){       //二进制拆分（写得可能有点丑）
        scanf("%d",&signum);
        scanf("%d%d",&tmp2,&tmp3);

        first = 0;
        tmp1 = signum;
        for(j=0;j<=10;++j){
            tmp = (1<<j);
            if(tmp1>=tmp){tmp1 -= tmp; b[j] = 1; first += tmp;}
            else b[j] = 0;
        }
        lef = signum - first;
        for(j=0;j<10;++j)
            if(b[j]!=0){
                v[allnum] = tmp2 * (1<<j);
                c[allnum] = tmp3 * (1<<j);
                ++allnum;
            }
        v[allnum] = tmp2 * lef;
        c[allnum] = tmp3 * lef;
        ++allnum;
    }

    //下面是01背包的解法
    for(i=0;i<=m;++i) a[i] = 0;

    for(i=0;i<allnum;++i)
        for(j=m;j>=v[i];--j)
            a[j] = max(a[j],a[j-v[i]]+c[i]);

    printf("%d",a[m]);

    return 0;
}
