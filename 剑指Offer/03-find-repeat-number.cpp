#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution{
public:
    //时间复杂度是O(n)，空间复杂度是O(n)
    //哈希表
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int,int> hash;
        for(int i=0;i<len;i++){
            if(hash.find(nums[i])==hash.end()){
                hash[nums[i]]=1;
            }else{
                return nums[i];
            }
        }
        return -1;
    }  
};

class Solution{
public:
    //时间复杂度是O(n)，空间复杂度是O(1)
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        for(int i=0;i<len;i++){
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]])
                    return nums[i];

                int tmp = nums[i];
                nums[nums[i]] = nums[i];
                nums[i] = tmp;
            }
        }
        return -1;
    }  
};