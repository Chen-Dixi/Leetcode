#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int ans=0;
        for(long long i=1;i<=n;i*=10)
        {
            long long divider = i*10;
            ans += (n/divider)*i+min(max(n%divider-i+1,0LL),i);
        }
        return ans;

    }
};

//

class Solution {
public:
    int countDigitOne(int n) {
        int ans=0;
        for(long long i=1;i<=n;i*=10) //这个就是，遍历位数
        {
            long long divider = i*10;
            //每10个数字，各位有1个1，每100个数字，十位有10个1，每1000，百位有100个1
            //下面的公式，用n来计算 每一位有多少1， 理解这个公式 min(max( n%divide-i+1,0LL),i)
            ans += (n/divider)*i + min( max( n%divider-i+1,0LL) ,i);
        }
        return ans;
    }
};