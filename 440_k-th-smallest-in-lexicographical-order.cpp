#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <climits>
using namespace std;

//困难题目 给定整数 n 和 k，找到 1 到 n 中字典序第 k 小的数字。
/*
解答
https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/ben-ti-shi-shang-zui-wan-zheng-ju-ti-de-shou-mo-sh/

*/
class Solution {
public:
    int findKthNumber(int n, int k) {
        int p=1; //排第几
        int prefix=1;//前缀
        while(p<k){

            int count = getCount(prefix, n);

            if (p+count>k){
                prefix *= 10;
                p++;
            }else if(p+count<=k){
                prefix+=1;
                p+=count;
            }
        }
        return prefix;
    }
private:

    //10叉树 先序遍历 结点数量
    // prefix 节点对应的数字大小
    int getCount(int prefix, int n){
        long long int cur=prefix, next = prefix+1;
        int count=0;
        while(cur<=n){
            count += (int)(min((long long int)(n+1),next) - cur);
            cur*=10;
            next*=10;
        }

        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    
    cout<<solution.findKthNumber(13,2);
    
}