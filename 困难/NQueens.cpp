#include <bits/stdc++.h>
class Solution {
public:
    int A[10000];
    void init(){
        memset(A,-1,sizeof(A));
    }
    
    int N;

    void push_a_solut(){
        string kw = ".";
        string queen = "Q";
        vector<string> a_solut;
        
        for(int i=0;i<N;i++){
            int index=A[i];
            string row_str = "";
            for(int j=0;j<N;j++){
                row_str += (j==A[i]) ? queen : kw;
            }
            a_solut.push_back(row_str);
        }

        ans.push_back(a_solut);

    }

    //检查此时皇后放(r,c)的位置有没有问题
    int check(int r,int c){
        for(int i=0;i<r;i++){
            if ( A[i]==c || abs(i - r) == abs(A[i] - c))
                return 0;
        }
        return 1;
    }

    void find( int curRow)
    {
        //找到一个解
        if (curRow==N){
            push_a_solut();
            return;
        }

        for(int j=0;j<N;j++){
            if(check(curRow,j)==1){
                A[curRow]=j;
                find(curRow+1);    
            }
            
        }

        A[curRow]=-1;//回溯

    }

    vector<vector<string>> solveNQueens(int n) {
        //清空棋盘
        N=n;
        init();
        //现在搜索第几行棋盘
        find(0);

        return ans;
    }
private:
    vector<vector<string> > ans;
};