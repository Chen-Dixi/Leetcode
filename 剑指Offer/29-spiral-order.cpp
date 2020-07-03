#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();

        if(row<=0)
            return res;
        int col = matrix[0].size();

        if(col<=0)
            return res;

        int start=0;
        while(row>start*2 && col > start*2){
            printInCircle(matrix, res,start,row,col);

            start++;
        }

        return res;
    }

    void printInCircle(vector<vector<int>>& matrix, vector<int>& res, int start, int row, int col){
        int endX = col-start-1;
        int endY = row-start-1;

        //从左往右
        for(int i=start;i<=endX;i++){
            res.push_back(matrix[start][i]);
        }

        //从上往下
        if (start<endY)//至少有2行
        {
            for(int i=start+1;i<=endY;i++){
                res.push_back(matrix[i][endX]);
            }
        }

        //
        if(start<endX && start<endY)//至少有2行2列
        {
            for(int i=endX-1;i>=start;i--){
                res.push_back(matrix[endY][i]);
            }
        }

        if(endY>=start+2 && start<endX)//至少有3行2列
        {
            for(int i=endY-1;i>start;i--){
                res.push_back(matrix[i][start]);
            }
        }
    }
};