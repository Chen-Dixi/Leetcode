import java.util.Arrays;
import java.util.Stack;

/*
 * @lc app=leetcode.cn id=785 lang=java
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
    public boolean isBipartite(int[][] graph) {
        int len = graph.length;

        int[] color = new int[len];
        Stack<Integer> stc = new Stack<>();
        Arrays.fill(color, -1);
        for(int i=0;i<len;i++){
            if(color[i]==-1){//没有标记颜色
                color[i]=0;
                stc.push(i);
                while(!stc.empty()){
                    int u = stc.pop();
                    for(int v: graph[u]){
                        if(color[v]==-1){
                            color[v]=color[u]^1;
                            stc.push(v);
                        }else if(color[v]==color[u]){
                            return false;
                        }
                    }
                }

            }
        }

        return true;
    }
}
// @lc code=end

