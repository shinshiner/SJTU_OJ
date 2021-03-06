/*
定义Fib数列：1,1,2,3,5,8,13,...
求第N项除以20102010的余数

输入仅一行，为一个整数N

输出仅一行，为第NN项除以20102010的余数

对于70%的数据 N≤1,000,000
对于100%的数据 N≤210,000,000,000
*/

#include <iostream>

using namespace std;

void fib(long long n){  //计算第n项
    if(n==1||n==2) {cout << 1; return;}

    long long tmp1=1, tmp2=1, ans=0;
    for(int i=2;i<n;++i){  //递推
        ans = (tmp1 + tmp2) % 2010;  //根据题目要求，每次加完要模2010
        tmp1 = tmp2;
        tmp2 = ans;
    }
    cout << ans << '\n';
    return;
}

int main()
{
    long long n;
    cin >> n;
    n %= 2040;  //循环节为2040
    fib(n);
    return 0;
}
