/**
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count=0;

        for(int i=0;i<s.size();i++){
            count += countPalindrome(s,i,i); //单数
            count += countPalindrome(s,i,i+1);//偶数
        }

        return count;
    }
private:
    int countPalindrome(string s, int left, int right){
        int count = 0;
        while(left >= 0 && right < s.size() && s[left--] == s[right++]) {
            count++;
        }

        return count;
    }
};

int main(){
    Solution sol = Solution();
    string str = "abc";
    cout<<sol.countSubstrings(str)<<endl;
}

