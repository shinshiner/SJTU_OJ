/*
二哥开始筹备翘课计划.二哥发现了一个规律:如果连续翘课三天就会被教务处的人发现,
如果只连续翘课1天、2天或者不翘课就不会被发现.
现在已知一个学期有N天,二哥想知道有多少种不被教务处发现的翘课方案.(提示：最后结果可能会很大)

第1行有1个整数N,表示要测试的数据

输出一个数字,表示不被发现的翘课方案数

对于50%的数据    1<=N<=35
对于100%的数据   1<=N<=10000
*/

#include <iostream>
#include <cstring>

using namespace std;

class superint{  //数字太大,要用高精度
private:
    char data[2000];
    int size;
public:
    void set(char a[]);
    void add(superint b);
    void output() {for(int i=size-1;i>=0;i--) cout << data[i];}
    superint &operator=(const superint &right);
};

superint &superint::operator=(const superint &right){
    if(this==&right) return *this;
    size = right.size;
    for(int i=0;i<size;i++) data[i] = right.data[i];
    return *this;
}

void superint::set(char a[]){
    int n, j=0;
    n = strlen(a);
    size = n;
    for(int i=n-1;i>=0;i--,j++) data[j] = a[i];
}

void superint::add(superint b){
    int i, n, tmp = 0;
    char r, res[2000];
    n = size < b.size ? size : b.size;
    for(i=0;i<n;++i){
        r = data[i] + b.data[i] - '0' + tmp;
        if(r>'9') {tmp = 1; res[i] = r - 10;}
        else {tmp = 0; res[i] = r;}
    }

    if(size<b.size){
        size = b.size;
        for(i=n;i<b.size;++i){
            r = b.data[i] + tmp;
            if(r>'9') {tmp = 1; res[i] = r - 10;}
            else {tmp = 0; res[i] = r;}
        }
        if(tmp==1){res[i] = '1'; ++size;}
    }
    else if(size>b.size){
        for(i=n;i<size;++i){
            r = data[i] + tmp;
            if(r>'9') {tmp = 1; res[i] = r - 10;}
            else {tmp = 0; res[i] = r;}
        }
        if(tmp==1){res[i] = '1'; ++size;}
    }
    else if(tmp==1){res[i] = '1'; ++size;}
    for(i=0;i<size;++i) data[i] = res[i];
}

int n;
superint a, b, c, ans;

int main()
{
    cin >> n;
    a.set("1");
    b.set("2");
    c.set("4");

    for(int i=3;i<=n;++i){
        ans.set("0");
        ans.add(a);
        ans.add(b);
        ans.add(c);
        a = b;
        b = c;
        c = ans;
    }
    c.output();

    return 0;
}
