#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class superint
{
private:
    char data[200];
    int size;
public:
    superint(int sz, char ch)
    {size=sz; data[0]=ch;}
    superint() {size = 1; data[0]='0';}
    void set(char a[]);
    void add(superint b);
    void output();
    superint &operator=(const superint &right);
};

superint &superint::operator=(const superint &right)
{
    if(this==&right) return *this;
    size = right.size;
    for(int i=0;i<size;i++) data[i] = right.data[i];
    return *this;
}

void superint::output()
{
    int i;
    for(i=size-1;i>=0;i--) cout << data[i];
}

void superint::set(char a[])
{
    int i, n, j=0;
    n = strlen(a);
    size = n;
    for(i=n-1;i>=0;i--,j++) data[j] = a[i];
}

void superint::add(superint b)
{
    int i, n, tmp = 0;
    char r, res[2000];
    n = size < b.size ? size : b.size;
    for(i=0;i<n;i++)
    {
        r = data[i] + b.data[i] - '0' + tmp;
        if(r>'9') {tmp = 1; res[i] = r - 10;}
        else {tmp = 0; res[i] = r;}
    }

    if(size<b.size)
    {
        size = b.size;
        for(i=n;i<b.size;i++)
        {
            r = b.data[i] + tmp;
            if(r>'9') {tmp = 1; res[i] = r - 10;}
            else {tmp = 0; res[i] = r;}
        }
        if(tmp==1)
        {
            res[i] = '1';
            size++;
        }
    }
    else if(size>b.size)
    {
        for(i=n;i<size;i++)
        {
            r = data[i] + tmp;
            if(r>'9') {tmp = 1; res[i] = r - 10;}
            else {tmp = 0; res[i] = r;}
        }
        if(tmp==1)
        {
            res[i] = '1';
            size++;
        }
    }
    else
    {
        if(tmp==1)
        {
            res[i] = '1';
            size++;
        }
    }
    for(i=0;i<size;i++) data[i] = res[i];
}

superint F[55][55], ans, one(1,'1');

int main()
{

    long long f[55][55]={0}, g[55]={0};
    int k, h, i, j, tmp=0, r;
    scanf("%d%d",&k,&h);
    for(i=k;i>0;--i)
    {
        tmp += i;
        g[i] = tmp;
    }
    
    F[1][1].add(one);
    F[2][k].add(one);
    
    for(i=3;i<=h+1;++i)
        for(j=1;j<=k;++j)
            for(r=1;r<=k-j+1;++r) F[i][j].add(F[i-1][r]);

    for(i=1;i<=k;++i)
        for(j=1;j<=g[i];++j)
            ans.add(F[h][i]);
            
    ans.output();
    
    return 0;
}
