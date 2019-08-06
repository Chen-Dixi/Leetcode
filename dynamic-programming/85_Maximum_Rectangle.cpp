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

class Solution2 {
public:
    int width[1000][1000];

    int maximalRectangle(vector<vector<char>>& matrix) {
        /*
        官方题解三：使用柱状图 - 栈
        在上一方法中我们讨论了将输入拆分成一系列的柱状图，每个柱状图代表一列的子结构。为了计算长方形的最大面积，我们仅仅需要计算每个柱状图中的最大面积并找到全局最大值（注意后面的解法对每一行而非列建立了柱状图，两者思想一致）。

        既然我们已经有了 84 - 柱状图中最大的矩形，可以直接使用该题题解中最快的基于栈的解法 点击这里 ，并将其应用在我们生成的柱状图中。想详细了解该算法的原理，请点击上面的链接。

        作者：LeetCode
        链接：https://leetcode-cn.com/problems/two-sum/solution/zui-da-ju-xing-by-leetcode/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
        */
        //矩阵长度
        return 0;
    }
};

int main(){
    Solution sol = Solution();
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    int ans = sol.maximalRectangle(matrix);
    printf("%d\n",ans );
    return 0;
}