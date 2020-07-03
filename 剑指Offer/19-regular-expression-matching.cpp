class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        vector<vector<bool> > dp(n+1, vector<bool>(m+1,false));
        /*dp数组已经被初始化成false，
        非空串和空正则必然不匹配，f[1][0]=...=f[n][0]=false 已经被定义好了
        空串和非空正则必须要计算出来
        */
        dp[0][0] = true;//空串和空正则是匹配的f[0][0]
        for(int i=0; i<=n;i++)//字符串s冲空字符串开始找
            for(int j=1;j<=m;j++){
                if(p[j-1]!='*'){
                    //首先 i>0才行，i==0时表示s是一个空串
                    dp[i][j] = i && dp[i-1][j-1] && (s[i-1]==p[j-1]||p[j-1]=='.');
                } else {
                    //        不考虑这个*号 || 考虑星号*， （S往前挪动一个看是否匹配 && 字符等于*号前一个的字符，或者*号前一个字符是点'.'）
                    //  (这里的 i && ...) 是防止下标出错，以免后面i-1让下标小于0
                    dp[i][j] = dp[i][j-2] || (i && dp[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.'));
                }
            }
    }
};