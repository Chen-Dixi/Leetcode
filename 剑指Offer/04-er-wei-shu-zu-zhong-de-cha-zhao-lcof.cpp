#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int> >& matrix, int target) {
        int nrow = matrix.size();
        if(nrow==0){
            return false;
        }
        int ncol = matrix[0].size();
        if(ncol==0)
            return false;

        //从右上角开始找
        int row = 0;
        int col = ncol-1;

        while( row < nrow && col >= 0){
            if(matrix[row][col] < target){
                row = row+1;

            }else if(matrix[row][col] > target){
                col=col-1;
            }else{
                return true;
            }
        }

        return false;
    }
};

//思考测试用例

/*
包含查找数组
没有查找的数字
空指针，为空

考察问题分析能力，发现问题比较复杂时，能不能通过具体例子找出其他规律。能否解决这个问题的关键所在。
从右上角开始分析，就能找到方法

*/

