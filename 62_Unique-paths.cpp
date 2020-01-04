#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
using namespace std;

// #1排列组合的方法来做
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int M=m<n?m-1:n-1;

        long ans=1;
        for(int i=1;i<=M;i++)
            ans = ans*(N-i+1)/i;

        return ans;
    }
};

// #2动态规划的方法
class Solution2{
public:

    int uniquePaths(int m, int n) {
            
        int *pre = new int[n];
        int *cur = new int[n];

        for(int i=0;i<n;i++){
            pre[i]=1;
            cur[i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)
                cur[j]=cur[j-1]+pre[j];
            for(int k=0;k<n;k++)
                pre[k]=cur[k];
        }
        return cur[n-1];
    }
};
int main(int argc, char const *argv[])
{
    
    
}