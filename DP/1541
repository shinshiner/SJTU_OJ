/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.
For example, Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
Window position Max --------------- ----- [1 3 -1] -3 5 3 6 7 3 1 [3 -1 -3] 5 3 6 7 3 1 3 [-1 -3 5] 3 6 7 5 1 3 -1 [-3 5 3] 6 7 5 1 3 -1 -3 [5 3 6] 7 6 1 3 -1 -3 5 [3 6 7] 7
Therefore, return the max sliding window as [3,3,5,5,6,7].
Note: You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

input 3 rows, the first rows is a number k and the second rows is a number n.
The third row is n numbers separated by a blank.

output n-k+1 numbers in a row separated by a blank.
*/

//区间最大问题用单调队列解
#include <iostream>
#include <cstdio>
using namespace std;

int a[200005], q[200005];

int main()
{
    int k, n, head = 0, tail = 0;

    scanf("%d%d",&k,&n);
    for(int i=0;i<n;++i) scanf("%d",&a[i]);

    q[++tail] = 0;
    for(int i=1;i<k;++i){
        while(head!=tail)
            if(a[i]>a[q[tail]]) --tail; else break;
        q[++tail] = i;
    }

    printf("%d ",a[q[head+1]]);
    for(int i=k;i<n;++i){
        while(head!=tail)
            if(a[i]>a[q[tail]]) --tail; else break;
        q[++tail] = i;

        while(q[head+1]<=i-k) ++head;
        printf("%d ",a[q[head+1]]);
    }

    return 0;
}
