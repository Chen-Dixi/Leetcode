class Solution {
public:
    int mySqrt(int x) {
        //x是非负整数
        //答案K 是满足k^2 <= x的最大整数
        int l=0,r=x;
        int ans=-1;
        while(l<=r){
            int mid = (l+r)/2;
            if((long long)mid*mid<=x){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
};