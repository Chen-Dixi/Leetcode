class Solution {
public:
    //回溯法
    bool exist(vector<vector<char>>& board, string word) {
        //怎么回溯呢
        //暴力法遍历矩阵中所有字符串可能性
        // 朝一个方向搜到底，再回溯至上一个节点，沿另一个方向搜索

        int rows = board.size();
        if(rows<=0)
            return false;
        int cols = board[0].size();

        //每个点都可以开始搜索
        
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
            {
                if(dfs(board, word,i,j,0)) return true;
            }

        return false;
    }


    //dfs + 回溯
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int k)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[k] ) return false;
        if(k==word.size()-1) return true;

        int drow[4] = {0,0,1,-1};
        int dcol[4] = {-1,1,0,0};
        char tmp = board[i][j];
        board[i][j]='/';
        for(int l=0;l<4;l++){
            if(dfs(board,word,i+drow[l],j+dcol[l],k+1)) return true;
        }
        board[i][j]=tmp;
        return false;
    }
};