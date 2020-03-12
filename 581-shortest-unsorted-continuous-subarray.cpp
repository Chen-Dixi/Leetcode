#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
using namespace std;

//最短无序连续子数组
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();

        if(len<=1)
            return 0;

        int mins=99999999;
        int maxs=-999999;

        //无序数组最小元素决定最左，最大元素决定最右
        for(int i=1;i<len;i++){
            if(nums[i-1]>nums[i]){
                maxs = max(nums[i-1],maxs);
                mins = min(nums[i],mins);
            }
        }
        if(mins==99999999 || maxs==-999999)
            return 0;

        int i=0,j=len-1;

        while(nums[i]<=mins && i<len){
            i++;
        }

        while(nums[j]>=maxs && j>=0){
            j--;
        }

        
        return  j-i+1>0 ? j-i+1 : 0;

    }
};

int main(){
    vector<int> nums = {7,1,3,4,2,6,0,5,8,9};
    Solution sol = Solution();
    cout<<sol.findUnsortedSubarray(nums)<<endl;
}