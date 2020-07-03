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

//用推，可以处理海量数据，最小K个数字
class Solution {
    enum { MAXN = 10000 };
    int n;
    int heap[MAXN];
    
    inline int& getRef(int root) {
        return heap[root-1];
    }
public:
    Solution() : n(0) {}
    void push(int v) {
        heap[n++] = v;
        for(int pos = n, nextPos = pos>>1; pos > 1 
                && getRef(pos) > getRef(nextPos); pos = nextPos, nextPos >>= 1) {
            swap(getRef(pos), getRef(nextPos));
        }
    }
    int pop() {
       swap(getRef(1), getRef(n));
       int res = heap[--n];
       for(int root = 1; ; ) {
           int left = root<<1;
           int right = root<<1|1;
           if(right <= n && getRef(root) < max(getRef(left), getRef(right))) {
               if(getRef(left) > getRef(right)) {
                   swap(getRef(left), getRef(root));
                   root = left;
               } else {
                   swap(getRef(right), getRef(root));
                   root = right;
               }
           } else if (left <= n && getRef(root) < getRef(left)) {
                swap(getRef(left), getRef(root));
                root = left;
                break;
           } else {
               break;
           }
       }
       return res;
    }
    int size() const {
        return n;
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        for(auto v : arr) {
            this->push(v);
            if(this->size() > k) {
                this->pop();
            }
        }
        
        return vector<int>(heap, heap+k);
    }
};

 
//
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