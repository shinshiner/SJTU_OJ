/*
数独是一种游戏.玩家需要根据9×9盘面上的已知数字,推理出所有剩余空格的数字.
满足每一行、每一列、每一个粗线宫内的数字均含1-9,不重复.
每一道合格的数独谜题都有且仅有唯一答案.
现在我们想知道，我们给定的数独是否是合格的数独（也就是说有解且唯一）.

输入的第一行包含一个不超过10的整数T,表示数据的组数.
接下来有T个部分,每两个部分之间用一个换行符隔开,每个部分描述一个数独局面.
每个局面由9*9的方阵描述,若方阵中的数字为1~9,则说明该位置是已经被填好;若是0,则表示该位置为空.

输出包含T行,每行包括一个“Yes”或“No”表示该数独是否合格.
*/

#include <iostream>

using namespace std;

//本程序只是比较low的dfs,check函数可用几个bool数组优化
int solve, a[10][10];

bool check(int x, int y){
    for(int i=0;i<9;++i){
        if(i==y) continue;
        else if(a[x][i]==a[x][y]) return false;
    }
    for(int i=0;i<9;++i){
        if(i==x) continue;
        else if(a[i][y]==a[x][y]) return false;
    }
    for(int x0=x/3*3;x0<x/3*3+3;++x0)
        for(int y0=y/3*3;y0<y/3*3+3;++y0){
            if(x0==x&&y0==y) continue;
            else if(a[x0][y0]==a[x][y]) return false;
        }
    return true;
}

bool precheck(){
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j){
            if(a[i][j]==0) continue;
            if(!check(i,j)) return false;
        }
    return true;
}

void print(){   //自己验证答案用的函数
    cout << '\n';
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j) cout << a[i][j] << ' ';
        cout << '\n';
    }
}

void dfs(int n){
    if(n==-1) {//print();
                ++solve; return;}
    int x = n / 9, y = n % 9;

    if(a[x][y]!=0) dfs(n-1);
    else{
        for(int i=1;i<10;++i){
            if(solve>1) break;
            a[x][y] = i;
            if(check(x,y)) dfs(n-1);
        }
        a[x][y] = 0;
    }
}

int main()
{
    int T;
    cin >> T;
    for(int i=0;i<T;++i){
        for(int j=0;j<9;++j)
            for(int k=0;k<9;++k) cin >> a[j][k];
        solve = 0;
        if(!precheck()) {cout << "No\n"; continue;} //check函数只检查了插入点的合法性,
                                                    //没有检查全局,所以要防止开始就不合法的局面
        dfs(80);    //亲测从最后一个点开始扫比顺序扫更快
        if(solve==1) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
