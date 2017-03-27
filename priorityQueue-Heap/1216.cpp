/*
使用最小化堆实现一个整型的优先队列,实现下列功能:
insert x     将优先级值为x的元素入队
find x       找出优先级值大于x的最小的元素,输出其下标.如果有多个元素优先级值相同,输出下标最小的那个.
DECREASE i v 将第i个节点的优先级值减少v。

第一行含有一个正整数M(1<=M<=20000),代表总的操作数.
以下M行,每行一个操作.

对于每个find操作,输出一个下标,回车分隔.

输入数据保证合法
find操作只要求时间复杂度O(n),其他操作要求O(logn)
*/

#include <iostream>
#include <cstring>

using namespace std;

class pQ{
    int currentSize;
    int array[20005];

    void down(int hole);
public:
    pQ() {currentSize = 0;}
    ~pQ() {}

    void enq(const int &x);
    void deq() {array[1] = array[currentSize--]; down(1);}
    int find(int &x);
    void up(int hole, int value);
};

//-----private-----//

void pQ::down(int hole){
    int child;
    int tmp = array[hole];

    for(;hole*2<=currentSize;hole=child){
        child = hole * 2;
        if(child!=currentSize&&array[child+1]<array[child]) ++child;
        if(array[child]<tmp) array[hole] = array[child];
        else break;
    }
    array[hole] = tmp;
}

//-----public-----//

void pQ::enq(const int &x){
    int hole = ++currentSize;
    for(;hole>1&&x<array[hole/2];hole/=2)
        array[hole] = array[hole/2];
    array[hole] = x;
}

void pQ::up(int hole, int value){
    array[hole] -= value;
    int tmp;
    while(hole>1&&array[hole]<array[hole/2]){
        tmp = array[hole];
        array[hole] = array[hole/2];
        array[hole/2] = tmp;
        hole = hole / 2;
    }
}

int pQ::find(int &x){
    int tmp = 100000000, j = 1;
    for(int i=1;i<=currentSize;++i)
        if(array[i]>x)
            if(tmp>array[i]) {tmp = array[i]; j = i;}
    return j;
}

int main()
{
    pQ pt;
    int m, tmp1, tmp2;
    char str[10];
    cin >> m;
    for(int i=0;i<m;++i){
        cin >> str;
        if(strcmp(str,"insert")==0)     {cin >> tmp1; pt.enq(tmp1);}
        if(strcmp(str,"find")==0)       {cin >> tmp1; cout << pt.find(tmp1) << '\n';}
        if(strcmp(str,"decrease")==0)   {cin >> tmp1 >> tmp2; pt.up(tmp1,tmp2);}
    }
    return 0;
}
