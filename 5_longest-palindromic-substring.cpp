class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        bool dp[1000][1000];
        int n=s.size();
        for(int i=n-1;i>=0;i--)
            for(int j=i;j<n;j++){
                
                dp[i][j] = s[i]==s[j] && (j-i<2 || dp[i+1][j-1]);
                if (dp[i][j] && j-i+1>res.size()){
                    res = s.substr(i,j-i+1);
                }
            }
        return res;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int len = s.size();
        if(len==0){
            return "";
        }
        int dp[len][len];
        int maxsize=0;
        memset(dp,0,sizeof(dp));
        for(int j=0;j<len;j++)
            for(int i=j;i>=0;i--){
                dp[i][j] = (s[i]==s[j]) && (j-i+1<=2 || dp[i+1][j-1])? 1:0;
                if(dp[i][j]==1 && j-i+1>ans.size()){
                    ans = s.substr(i,j-i+1);
                }
            }
        
        return ans;
    }
};