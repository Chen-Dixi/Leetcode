class Solution {
    public boolean exist(char[][] board, String word) {
        int rows = board.length;
        if (rows<=0)
            return false;
        int cols = board[0].length;

        for(int i = 0;i<rows; i++)
            for(int j=0; j<cols; j++){
                if(search(board, word,rows,cols, 0, i, j))
                    return true;
            }

        return false;
    }

    private boolean search(char[][] board, String word,int rows, int cols, int k,int i, int j){
        if(i<0 || i>=rows || j<0 || j>=cols || board[i][j]!=word[k])
            return false;

        char tmp = board[i][j];
        board[i][j]='/';
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};

        for(int k=0;k<4;k++){
            if(search(board,word,rows,cols,k+1,i+dx[k],j+dy[k]))
                return true;
        }
        board[i][j]=tmp;
        return false;
    }
}