#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        vector<int> ans;

        int len = arr.size();
        if(len==0){
            return ans;
        }

        quick(arr,ans,0,len-1,k);
        return ans;
    }

    void quick(vector<int> & arr, vector<int> & ans, int l, int r, int k){
        if(l<=r){
            int q = partition(arr, l, r);
            
            if(q<k-1){
                
                quick(arr, ans,q+1,r,k);
            }else if(q>k){
                
                quick(arr,ans,l,q-1,k);
            }else{
                
                for(int i=0;i<k;i++){
                    ans.push_back(arr[i]);
                }
            }
        }
    }


    int partition(vector<int>& arr,int l,int r){
        int x = arr[r];
        int i=l-1;
        for(int j=l;j<r;j++){
            if(arr[j]<x){
                i++;
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        int tmp = arr[i+1];
        arr[i+1] = x;
        arr[r] = tmp;

        return i+1;
    }
};

int main(){
    vector<int> arr = {3,2,1};
    Solution sol = Solution();
    int k=2;
    vector<int> ans = sol.getLeastNumbers(arr,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}