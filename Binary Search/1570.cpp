/*
二哥手上有N个数字,这些数字已经排好序了,二哥知道这里面有自己喜欢的T个数字.
现在他想知道对于自己喜欢的每个数字,这n个数字中比它大的有多少个.
N,T<=100,000

第一行有两个整数N,T
接下来一行N个数代表二哥手上的数字{X_1,X_2,…,X_N};
接下来一行T个数代表二哥喜欢的数字{Y_1,Y_2,…,Y_N}.

每行输出一个数字,表示二哥手上的数字比这个喜欢的数字{Y_i}大的个数.

对于30%的数据    N,T≤1000
对于70%的数据    N,T≤100000, Xi,Yi≤100000
对于100%的数据   N,T≤100000, Xi,Yi≤2,000,000,000
所有数字均为非负整数.
*/
#include <iostream>
#include <cstdio>

using namespace std;

void find_num(int num, int x[], int n){
    int mid, lh=0, rh=n-1;

    if(num<x[0]) {printf("%d\n",n); return;}
    if(num>=x[n-1]) {printf("0\n"); return;}
    while(lh<=rh){  //二分查找
        mid = (lh + rh) / 2;
        if(x[mid]<=num&&x[mid+1]>num) {printf("%d\n",n-1-mid); return;}
        else if(x[mid]>num) rh = mid - 1;
        else if(x[mid]<=num) lh = mid + 1;
    }
    return;
}

int n, t, x[100005], y[100005];

int main()
{
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;++i) scanf("%d",&x[i]);
    for(int i=0;i<t;++i) scanf("%d",&y[i]);

    for(int i=0;i<t;++i)
        find_num(y[i],x,n);

    return 0;
}
