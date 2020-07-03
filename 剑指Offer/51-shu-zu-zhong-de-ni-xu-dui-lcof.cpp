#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int global_count=0;
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        
        global_count=0;
        if(len<=1){
            return 0;
        }
        vector<int> T(len,0);
        mergesort(nums,T,0,len-1);
        return global_count;
    }

    void mergesort(vector<int>& nums,vector<int> & T,int l, int r)
    {
        if(l>=r) return;

        int mid = (l+r)/2;

        int p=l,q=mid+1;
        mergesort(nums,T,l,mid);
        mergesort(nums,T,mid+1,r);
        int i=l;
        while(p<=mid || q<=r){
            if(q>r || (p<=mid && nums[p]<nums[q]) ){

                T[i++]=nums[p++];

            }else{
                if(p<=mid){
                    int k=p;
                    while(nums[k]<=nums[q])
                        k++;
                    global_count+= ((mid-k)+1);
                }
                T[i++]=nums[q++];
                
            }
        }

        for(int i=l;i<=r;i++){
            nums[i]=T[i];
        }
    }
};

class Solution{
private:
    int counter=0;
    int reversePairs(vector<int>& nums) {
        int len = nums,size();
        if(len<=1){
            return 0;
        }   
        counter=0;
        //归并排序
        vector<int> copy(len,0);
        mergesort(nums,copy,0,len-1);
        return counter;

    }

    return mergesort(vector<int>& nums, vector<int>& copy,int l, int r){
        if(l>=r) return;
        int mid = (l+r)/2;
        
        mergesort(nums,copy,l,mid);
        mergesort(nums,copy,mid+1,r);
        //这里归并过程，从子数组最后往前归并
        int p=mid,q=r;
        int k=r;
        while(p>=l && q>=mid+1){
            if(nums[p]>nums[q]){
                copy[k--]=nums[p--];
                counter+=(q-mid);
            }else{
                copy[k--]=data[q--];
            }
        }
        for(;p>=l;--p){
            copy[k--]=nums[p];
        }
        for(;q>=mid+1;q--)
            copy[k--]=nums[q];
        for(int i=l;i<=r;i++){
            nums[i]=copy[i];
        }
    }


};