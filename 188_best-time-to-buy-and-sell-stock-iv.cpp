#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstdint>
using namespace std;


class Solution {

public:
    int maxProfit(int k, vector<int>& prices) {
        
        int lens = prices.size();

        // anomalous inputs
        if (k == 0 || lens < 2) {
            return 0;
        }

        if (k>=prices.size() / 2 ){
            int res=0;
            int diff=0;

            for(int i=1;i<lens;i++){
                diff = prices[i]-prices[i-1];
                if (diff>0)
                    res+=diff;
                
            }
            return res;
        }    

        int dp[lens][k][2];
        for(int i=0;i<lens;i++)
            for(int j=0;j<k;j++){
                dp[i][j][1]=-999999;
            }

        for(int i=0;i<lens;i++){
            for(int j=0;j<k;j++)
                if(i==0){
                    dp[i][j][1]=-prices[i];
                    dp[i][j][0]=0;
                }else{
                    if (j==0){
                        dp[i][j][1]=max(-prices[i],dp[i-1][j][1]);
                        
                    }else{
                        
                        dp[i][j][1]=max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
                    }
                    dp[i][j][0]=max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                }
        }
        return dp[lens-1][k-1][0];
    }

};

class Solution2 {

public:
    int maxProfit(int k, vector<int>& prices) {
        
        int lens = prices.size();

        // anomalous inputs
        if (k == 0 || lens < 2) {
            return 0;
        }

        if (k>=prices.size() / 2 ){
            int res=0;
            int diff=0;

            for(int i=1;i<lens;i++){
                diff = prices[i]-prices[i-1];
                if (diff>0)
                    res+=diff;
                
            }
            return res;
        }    

        int dp[k][2];
        
        for(int j=0;j<k;j++){
            dp[j][1]=-99999999;
            dp[j][0]=0;

        }

        for(int i=0;i<lens;i++){
            for(int j=0;j<k;j++){
                if (j==0){
                    dp[j][1]=max(-prices[i],dp[j][1]);
                    
                }else{
                    dp[j][1]=max(dp[j][1], dp[j-1][0]-prices[i]);
                }
                dp[j][0]=max(dp[j][0], dp[j][1]+prices[i]);    
            }
        }
        return dp[k-1][0];
    }

};

int main(){
    //Solution sol = Solution();
    Solution2 sol = Solution2();
    vector<int> points = {3,2,6,5,0,3};
    //vector<int> points = {3,2,6,5,0,3};
    int k=2;
    int ans = sol.maxProfit(k, points);
    printf("%d\n",ans );
    return 0;
}






