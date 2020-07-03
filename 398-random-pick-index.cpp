#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->len = nums.size();


    }
    
    int pick(int target) {
        int index = -1;
        int j;
        int n=1;
        for(int i=0; i < this->len;i++){
            if(nums[i]==target){
                j = rand()%n;
                if(j==0){
                    index = i;
                }
                n++;
            }
        }
        return index;
    }
private:
    vector<int> nums;
    int len;
};


int main(){

}