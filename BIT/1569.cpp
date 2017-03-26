/*
交大一共有N个女生连,每个女生连单身女生的人数二哥都掌握,这些人数可能发生变动:可能有女生脱单了或是又分了手.
二哥要随时知道某一段连续的女生连一共有多少单身女生.
但女生们的感情状况经常波动,而二哥每次查询的女生连也都不一样,他不可能一个一个连去数.
好在二哥学过树状数组,他决定写一个程序帮助自己解决这个问题.

第一行有一个整数N,表示有N个女生连,编号为1~N.
第二行有N个正整数,分别代表军训开始时每个女生连单身女生的数目.
接下来每行有一条纠纠送来的情报,情报有4种形式:
1-inc x y       x和y为正整数,表示编号为x的女生连新增了y名单身女生；
2-dec x y       x和y为正整数,表示编号为x的女生连减少了y名单身女生；
3-query x y     x和y为正整数,x<=y，表示询问第x到第y个女生连的总单身人数；
4-end           表示结束，这条命令仅在所有情报最后出现一次。

对于每个query询问,输出一个整数并回车,表示询问的段中的总人数,这个数保持在int以内.

对于100%的数据,1<=N<=10000,且保证每个数据不超过int范围.
请使用树状数组进行解题.
*/

#include <iostream>
#include <cstring>

using namespace std;

int query(int x, int t[]){
    int sum = 0;
    for(int i=x;i;i-=(i&-i))
        sum += t[i];
    return sum;
}

void add(int x, int p, int n, int t[]){
    for(int i=x;i<=n;i+=(i&-i))
        t[i] += p;
}

int main()
{
    int n, girl[10005]={0}, x, y;
    char cmd[10];

    cin >> n;
    for(int i=0;i<n;++i) {cin >> x; add(i+1,x,n,girl);}

    cin >> cmd;
    while(strcmp(cmd,"end")!=0){
        if(strcmp(cmd,"query")==0)
            {cin >> x >> y; cout << query(y,girl) - query(x-1,girl) << '\n';}
        else if(strcmp(cmd,"inc")==0)
            {cin >> x >> y; add(x,y,n,girl);}
        else if(strcmp(cmd,"dec")==0)
            {cin >> x >> y; add(x,-1*y,n,girl);}
        cin >> cmd;
    }

    return 0;
}
