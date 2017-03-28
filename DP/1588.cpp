/*
某国有种导弹拦截系统.但有个缺陷:虽然它的第一发炮弹能够到达任意的高度,但是以后每一发炮弹都不能高于等于前一发的高度.
某天,导弹来袭.如果只有一套这样的系统,最多能拦截多少枚导弹?
如果要拦截所有导弹,最少需要多少套这样的拦截系统?

第一行有一个整数N,代表来袭导弹的数目.
接下来一行N个数分别代表每发导弹的高度{X_1,X_2,…,X_N}.

输出两行,分别是单系统最多能拦截的导弹数与要拦截所有导弹最少要配备的系统数.

对于100%的数据   1<=x[i]<=2^31-1
对于30%的数据    n<=100

对于60%的数据    n<=1000
对于90%的数据    n<=10000
对于100%的数据   n<=1000000
*/
//本题就是找最长上升子序列和下降子序列
#include <iostream>
#include <cstdio>
using namespace std;

int x[1000005], y[1000005];

int main()
{
    int n, lh, rh, count=1, mid;
    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&x[i]);
    y[0] = 2147483647;
    y[1] = x[0];

    for(int i=1;i<n;++i){
        lh = 0;
        rh = count;
        while(lh<=rh){
            mid = (lh + rh) / 2;
            if(y[mid]>x[i]) lh = mid + 1;
            else rh = mid - 1;
        }
        y[lh] = x[i];
        if(lh>count) ++count;
    }
    printf("%d\n",count);

    y[0] = -1;
    y[1] = x[0];
    count = 1;
    for(int i=1;i<n;++i){
        lh = 0;
        rh = count;
        while(lh<=rh){
            mid = (lh + rh) / 2;
            if(y[mid]<x[i]) lh = mid + 1;
            else rh = mid - 1;
        }
        y[lh] = x[i];
        if(lh>count) ++count;
    }
    printf("%d",count);

    return 0;
}
