#include <bits/stdc++.h>

class Solution {
public:
    bool validPalindrome(string s) {
        
        int low = 0, high = s.size()-1;

        while(low<high){

            if(s[low]==s[high]){
                low++;high--;
            }else{
                return checkPalindrome(s, low+1,high) || checkPalindrome(s, low, high-1);
            }
        }

        return true;

    }

private:
    bool checkPalindrome(string& s, int low, int high)
    {
        while(low<high){
            if(s[low]!=s[high])
                return false;
            low++;high--;
        }
        return true;
    }
};