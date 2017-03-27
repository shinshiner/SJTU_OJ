/*
现在给出A,B,C,D四个集合,每个集合中元素的个数n都是相同的.
现在从每个集合中任取出一个数,记为a,b,c,d,现在要求统计有多少组不同的(a,b,c,d)使得a+b+c+d=0.

第一行为各集合中元素的个数n;
第二行到第n+1行,每行有4个数字,依次为A,B,C,D中的一个元素.

输出一行,为不同的(a,b,c,d)使得a+b+c+d=0的组数.

a,b,c,d的绝对值小于1000000,n小于500

将式子变形为(a+b)=-(c+d),可以将A,B两集合中元素相加得到n^2个和的集合E,
散列存储后,对C,D两集合中元素任意取和,查找和在E中出现的次数,累加即为解。
*/

#include <iostream>
#include <cstdio>

using namespace std;

int n, *a, *b, *c, *d, *e, ans=0;
int E[4000010]={0};  //用y=x的函数散列,下标存的就是数值

int main()
{
    int tmp;
    bool flag;

    scanf("%d",&n);
    a = new int[n];
    b = new int[n];
    c = new int[n];
    d = new int[n];
    e = new int[n*n];
    openHashTable h(n*n);
    for(int i=0;i<n;++i){
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            e[i*n+j] = a[i] + b[j];
            ++E[e[i*n+j]+2000000];
        }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            tmp = -1*(c[i] + d[j]);
            ans += E[tmp+2000000];
        }
    printf("%d",ans);

    delete []a;
    delete []b;
    delete []c;
    delete []d;
    delete []e;

    return 0;
}
