#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();

        //anomalous inputs
        if(len<1){
            return 0;
        }

        int ans = nums[0];
        
        int temp = nums[0];
        for(int i=1;i<len;i++){
            temp = max(temp+nums[i],nums[i]);
            ans = max(temp,ans);
        }

        return ans;
    }
};


int main(){
    Solution sol = Solution();
    vector<int> points = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = sol.maxSubArray(points);
    printf("%d\n",ans );
    return 0;
}