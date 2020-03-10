#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dm[4] = {-1,1,0,0};
    int dn[4] = {0,0,-1,1};

    int numIslands(vector<vector<char>>& grid) {
        int num=0;

        int m = grid.size(); //m是纵向的数量
        if(m==0)
        {
            return 0;
        }

        int n = grid[0].size(); //n是横向的数量

        if(n==0){
            return 0;
        }
    
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    
                    bianli(i,j,grid,m,n);
                    num+=1;
                }
            }
        
        return num;
    }

    void bianli(int i, int j, vector<vector<char>>& grid,int m, int n ){
        grid[i][j]='0';

        for(int k=0;k<4;k++){
            int ii = i+dm[k];
            int jj = j+dn[k];
            if(ii>=0 && ii<m && jj>=0 && jj<n && grid[ii][jj]=='1'){ //可以直接用这个grid当作flag 
                bianli(ii,jj,grid,m,n);
            }
        }
    }
};
