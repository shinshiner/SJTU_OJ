/*
二哥有N个盒子,每个盒子里面都有一块糖.
二哥无聊的时候就做以下几种事情:
把某两个盒子里面的糖拿出来放在一个新的盒子里面;
吃掉某一个盒子里面的所有的糖;
数数当前糖果数第P多的盒子里面有几块糖.

第一行两个数N(初始糖果数)和M(操作数),糖果编号为1到N
下面M行,每行表示一个操作

C x y   把糖果x所在盒子与和糖果y所在盒子进行合并.如果x或者y已经被吃掉,或者x与y本来就在同一个盒子里,则什么也不做

D x     吃掉糖果x所在的盒子里面的糖,同样,如果x已经被吃掉,则什么也不做

Q p     询问当前糖果数第p多的盒子里面的糖果数量,如果剩下的有糖果的盒子数量小于p,则输出0.所有的p都在1到10之间

对于每个Q操作,输出一个数(糖果数量),占一行

1≤M≤50000,1≤N≤500000
其他数字都在1到N之间
*/

//显然用并查集解,这里用树状数组维护第k小数
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX=530000;

class DisjointSet{
public:
    int size;
    int *parent;
public:
    DisjointSet(int s);
    ~DisjointSet() {delete []parent;}
    void Union(int root1, int root2);
    int Find(int x);
};

DisjointSet::DisjointSet(int n){
    size = n;
    parent = new int[size];
    for(int i=0;i<size;++i) parent[i] = -1;
}

int DisjointSet::Find(int x){
    if(parent[x]<0) return x;
    return parent[x] = Find(parent[x]);
}

void DisjointSet::Union(int root1, int root2){
    if(root1==root2) return;  //比较两棵树是否为同一棵树，如果是，则返回
    if(parent[root1]>parent[root2]) {parent[root2] += parent[root1]; parent[root1] = root2;}
    else {parent[root1] += parent[root2]; parent[root2] = root1;}
}

int n, m, x, y, tmp, tmp1, tmp2, tmp3, tmp4, tmp5, t[MAX]={0};
int len;
char cmd[2];

void Add(int x, int p, int T[]){   //在x处增加p的值
    for(int i = x; i <= MAX; i+= (i & -i)) T[i] += p;
}

int Query(int x, int T[]){   //查询1~x的区间和
    int res = 0;
    for(int i = x; i; i -= (i & -i)) res += T[i];
    return res;
}

//求第k小数
int find(int k, int a[]){
    int cnt=0,ans=0;
    for(int i=19;i>=0;--i){		//i的初始值应为满足 2^i<MAX 的最大值
        ans += (1<<i);
        if(ans>=MAX||cnt+a[ans]>=k) ans-=(1<<i);
        else cnt += a[ans];
    }
    return ans + 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    DisjointSet s(MAX);
    Add(1,n,t);
    len = n;
    for(int i=0;i<m;++i){
        scanf("%s",cmd);
        if(cmd[0]=='C'){
            scanf("%d%d",&x,&y);
            tmp1 = s.Find(x);
            tmp2 = s.Find(y);
            tmp3 = -1*s.parent[tmp1];
            tmp4 = -1*s.parent[tmp2];
            if(tmp1==tmp2||tmp3==1000000||tmp4==1000000) continue;
            s.Union(tmp1,tmp2);
            Add(tmp4,-1,t);
            Add(tmp3,-1,t);
            Add(tmp3+tmp4,1,t);
            --len;
        }
        else if(cmd[0]=='Q'){
            scanf("%d",&x);
            if(len<x) {printf("%d\n",0); continue;}
            int tmp = find(len-x+1,t);
            printf("%d\n", tmp);
        }
        else if(cmd[0]=='D'){
            scanf("%d",&x);
            tmp1 = s.Find(x);
            if(s.parent[tmp1]==-1000000) continue;
            Add(-1*s.parent[tmp1],-1,t);
            --len;
            s.parent[tmp1] = -1000000;
        }
    }
    return 0;
}
