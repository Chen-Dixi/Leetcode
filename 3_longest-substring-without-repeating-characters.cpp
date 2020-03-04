#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashset;
        int len = s.size();
        if(s.size()==0){
            return 0;
        }
        int i=0,j=i;
        int ans=0;
        while(i<len && j<len){

            if(hashset.find(s[j])==hashset.end()){
                
                ans = max( ans, j-i+1 );
                hashset.insert(s[j++]);
            }else{
                hashset.erase(s[i++]);
            }
        }
        return ans;
    }
};