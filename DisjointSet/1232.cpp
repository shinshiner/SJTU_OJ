/*https://acm.sjtu.edu.cn/OnlineJudge/problem/1232*/
/*砸墙用并查集,找字典序最小的路径按一定顺序深搜即可,
注意能走通的两点可能不能直达*/
#include <iostream>

using namespace std;

class seqStack{
private:
    int *elem;
    int top_p, maxSize;
    void doublespace();
public:
    seqStack(int initSize=10){elem = new int[initSize]; maxSize = initSize; top_p = -1;}
    ~seqStack() {delete []elem;}
    bool isEmpty() const {return top_p==-1;}
    void push(const int &x) {if(top_p==maxSize-1) doublespace(); elem[++top_p] = x;}
    void pop() {--top_p;}
    int top() const {return elem[top_p];}
    void print(int ans[]) {for(int i=1;i<=top_p+1;++i) ans[i] = elem[i-1]; ans[0] = top_p+1;}
};

void seqStack::doublespace(){
    int *tmp = elem;
    elem = new int[2*maxSize];
    for(int i=0;i<maxSize;++i) elem[i] = tmp[i];
    maxSize *= 2;
    delete []tmp;
}

class DisjointSet{
private:
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
    int tmp[1000], top=0;
    while(parent[x]>0){  //非递归的Find实现
        tmp[top++] = parent[x];
        x = parent[x];
    }
    for(int i=0;i<top;++i) tmp[i] = parent[x];
    return x;
}

void DisjointSet::Union(int root1, int root2){
    if(root1==root2) return;  //比较两棵树是否为同一棵树，如果是，则返回
    if(parent[root1]>parent[root2]) {parent[root2]+=parent[root1]; parent[root1]=root2;}
    else {parent[root1]+=parent[root2]; parent[root2]=root1;}
}

int n, a, b, p, q, f[1000][1000], sig[1000][1000]={0}, ans[1000];
bool qiang[1000][1000]={0};
seqStack st(100);
DisjointSet s(10000);

void dfs(int x, int y){
    sig[x][y] = 1;
    st.push(f[x][y]);
    if(f[x][y]==b) {st.print(ans); sig[x][y]=0; st.pop(); return;}
    if(y!=1&&sig[x-1][y-1]==0&&qiang[f[x][y]][f[x-1][y-1]]==1) dfs(x-1,y-1);
    if(y!=x&&sig[x-1][y]==0&&qiang[f[x][y]][f[x-1][y]]==1) dfs(x-1,y);
    if(x!=n&&sig[x+1][y]==0&&qiang[f[x][y]][f[x+1][y]]==1) dfs(x+1,y);
    if(x!=n&&sig[x+1][y+1]==0&&qiang[f[x][y]][f[x+1][y+1]]==1) dfs(x+1,y+1);
    sig[x][y] = 0;
    st.pop();
}
int main()
{
    cin >> n >> a >> b;
    int l, m;
    int k=1, i, j;
    for(i=1;i<=n;++i)
        for(j=1;j<=i;++j){
            f[i][j] = k; ++k;
        }
    while(true){
        cin >> p >> q;
        for(l=1;l<=n;++l){
            for(m=1;m<=l;++m)
                if(f[l][m]==p) {i = l; j = m; break;}
        }
        if(q==0&&j!=1){
            s.Union(s.Find(p),s.Find(f[i-1][j-1]));
            qiang[f[i][j]][f[i-1][j-1]] = 1;
            qiang[f[i-1][j-1]][f[i][j]] = 1;
        }
        else if(q==1&&j!=i){
            s.Union(s.Find(p),s.Find(f[i-1][j]));
            qiang[f[i][j]][f[i-1][j]] = 1;
            qiang[f[i-1][j]][f[i][j]] = 1;
        }
        else if(q==2&&i!=n){
            s.Union(s.Find(p),s.Find(f[i+1][j]));
            qiang[f[i][j]][f[i+1][j]] = 1;
            qiang[f[i+1][j]][f[i][j]] = 1;
        }
        else if(q==3&&i!=n){
            s.Union(s.Find(p),s.Find(f[i+1][j+1]));
            qiang[f[i][j]][f[i+1][j+1]] = 1;
            qiang[f[i+1][j+1]][f[i][j]] = 1;
        }
        if(s.Find(a)==s.Find(b)){
            for(l=1;l<=n;++l){
                for(m=1;m<=l;++m)
                    if(f[l][m]==a) {i = l; j = m; break;}
            }
            dfs(i,j);
            for(i=1;i<=ans[0];++i) cout << ans[i] << ' ';
            break;
        }
    }
    return 0;
}
