/*
用栈的方法
在这种方法中，我们维护一个栈。一开始，我们把 -1 放进栈的顶部来表示开始。初始化时，按照从左到右的顺序，我们不断将柱子的序号放进栈中，直到遇到相邻柱子呈下降关系，也就是 a[i-1] > a[i]a[i−1]>a[i] 。现在，我们开始将栈中的序号弹出，直到遇到 stack[j]stack[j] 满足a\big[stack[j]\big] \leq a[i]a[stack[j]]≤a[i] 。每次我们弹出下标时，我们用弹出元素作为高形成的最大面积矩形的宽是当前元素与 stack[top-1]stack[top−1] 之间的那些柱子。也就是当我们弹出 stack[top]stack[top] 时，记当前元素在原数组中的下标为 i ，当前弹出元素为高的最大矩形面积为：
$$
(i-stack[top-1]-1) \times a\big[stack[top]\big].
(i−stack[top−1]−1)×a[stack[top]].
$$
更进一步，当我们到达数组的尾部时，我们将栈中剩余元素全部弹出栈。在弹出每一个元素是，我们用下面的式子来求面积： (stack[top]-stack[top-1]) \times a\big[stack[top]\big](stack[top]−stack[top−1])×a[stack[top]]，其中，stack[top]stack[top]表示刚刚被弹出的元素。因此，我们可以通过每次比较新计算的矩形面积来获得最大的矩形面积。
*/
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
    //用栈的方法：https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode/
        stack<int> stc;
        stc.push(-1);
        int maxArea=0;

        for(int i=0;i<heights.size();i++){
            int t = heights[i];
            while (stc.top()!=-1 && heights[stc.top()] >= t ){
                int top = stc.top();stc.pop();
                maxArea = max( maxArea, heights[top]*(i-stc.top()-1) );
            }
            stc.push(i);
        }

        int last = stc.top();
        while( stc.top() != -1 ){
            int top = stc.top();stc.pop();
            maxArea = max( maxArea, heights[top]*(last-stc.top()) );
        }

        return maxArea;
    }
};

int main(){
    Solution sol = Solution();
    vector<int> matrix = {2,1,5,6,2,3};
    int ans = sol.largestRectangleArea(matrix);
    printf("%d\n",ans );
    return 0;
}