#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution {
public:
    //首尾之能选一个偷
    int rob(vector<int>& nums) {
        //思想很简单，不偷第一家，就在后面n-1家里偷，不偷最后一家，就在前n-1家里偷
        int len=nums.size();
        if(len==0)
            return 0;
        if(len==1)
            return nums[0];

        int ans1 = rob1(nums, 0, len-2);
        int ans2 = rob1(nums, 1, len-1);

        return max(ans1,ans2);
    }

    int rob1(vector<int> &nums, int l, int r){

        int ans = 0;
        int pre=0,prepre=0;

        for(int i=l;i<=r;i++){
            ans = max(prepre+nums[i], pre);
            prepre = pre;
            pre = ans;
        }
        return ans;
    }
};

