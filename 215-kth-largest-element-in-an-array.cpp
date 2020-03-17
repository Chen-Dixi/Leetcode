#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len=nums.size();
        // int q = partition(nums,0,len-1);
        // if(q==k-1){
        //     return nums[q];
        // }
        // else if(q<k-1){
        //     return 
        // }
        int ans = quicksort(nums,k,0,len-1);
        return ans;
    }

    int quicksort(vector<int>& nums, int k, int l, int r){
        if(l<=r){
            int q = partition(nums,l,r);
            if(q<k-1){

                return quicksort(nums, k, q+1,r);
            }else if(q>k-1){
                return quicksort(nums, k, l,q-1);
            }else{
                return nums[q];
            }
        }
        return -1;
    }

    int partition(vector<int>& nums, int l, int r){
        int x = nums[r];
        int i=l-1;
        for(int j=l;j<r;j++){
            if(nums[j]>x){
                i++;
                int tmp=nums[j];
                nums[j]=nums[i];
                nums[i]=tmp;
            }
        }
        int tmp=nums[i+1];
        nums[i+1]=x;
        nums[r]=tmp;
        return i+1;
    }
};