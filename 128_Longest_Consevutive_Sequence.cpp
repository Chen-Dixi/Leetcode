#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //数字nums-1
        if (nums.size()==0)
            return 0;

        set<int> numset;
        for(int num: nums){
            numset.insert(num);
        }

        int longest=1;
        int currentLength=0;
        for( int num: numset){
            if( numset.find(num-1)== numset.end() ){

                int current = num;
                
                while(numset.find(current)!=numset.end()){
                    currentLength+=1;
                    current += 1;
                }


                longest = max(longest, currentLength);
                currentLength = 0;
            }
        }

        return longest;
    }
};

int main(){
    Solution sol = Solution();
    vector<int> points = {100,4,200,3,2,1};
    int ans = sol.longestConsecutive(points);
    printf("%d\n",ans );
    return 0;
}