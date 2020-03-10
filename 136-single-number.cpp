#include <unordered_map>

//时间复杂度：O(n^2)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int,int> set;

        for(int i=0;i<len;i++){
            if(set.find(nums[i])!=set.end()){
                set[nums[i]]=2;
            }else{
                set.insert({nums[i],1});
            }
        }

        for(int i=0;i<len;i++){
            if(set[nums[i]]==1){
                return nums[i];
            }
        }
        return 0;
    }
};
//时间复杂度O(n)的，用hashset表存储，找到就remove，没找到就加进去

//只扫描一次，位运算有个规律，用xor。亦或，
class Solution2{
public:
    int singleNumber(vector<int>& nums){
        int len = nums.size();

        int ans=nums[0];
        for(int i=1;i<len;i++){
            ans ^= nums[i];
        }
        return ans;


    }
}