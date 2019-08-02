#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int width[1000][1000];

    int maximalRectangle(vector<vector<char>>& matrix) {
        /*
        官方题解二：
        动态规划，柱状图的优化暴力算法
        https://leetcode-cn.com/problems/maximal-rectangle/solution/zui-da-ju-xing-by-leetcode/
        */
        //矩阵长度
        int H = matrix.size();
        int max_size = 0;
        if (matrix.size()==0){
            return 0;
        }

        //矩阵宽度
        int W = matrix[0].size();
        int maxArea = 0;


        //计算出在给定的坐标结束的矩形的最大宽度
        for(int i=0;i<H;i++){
            
            for(int j=0;j<W;j++){
                if (j==0)
                    width[i][0] = matrix[i][0]=='1' ? 1 : 0 ;        
                else if (matrix[i][j]=='1')
                    width[i][j]=width[i][j-1]+1;
                int maxWidth = 1<<30;
                if (width[i][j]>0){
                    for(int curRow = i; curRow >=0 ; curRow--){
                        maxWidth = min(maxWidth, width[curRow][j] );
                        if (maxWidth==0) break;
                        int curArea = maxWidth * (i-curRow+1);
                        maxArea = max(maxArea,curArea);
                    }
                }
            }
        }
        return maxArea;
    }
};


int main(){
    Solution sol = Solution();
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    int ans = sol.maximalRectangle(matrix);
    printf("%d\n",ans );
    return 0;
}