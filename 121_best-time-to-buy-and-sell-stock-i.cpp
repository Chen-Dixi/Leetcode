#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = INT_MAX;

        for(int i=0;i<prices.size();i++){
            if (prices[i]<minprice){
                minprice = prices[i];
            }else if(prices[i]-minprice>maxprofit){
                maxprofit = prices[i]-minprice;
            }
        }

        return maxprofit;
    }
};

int main(){
    Solution sol = Solution();
    vector<int> points = {7,1,5,3,6,4};
    int ans = sol.maxProfit(points);
    printf("%d\n",ans );
    return 0;
}