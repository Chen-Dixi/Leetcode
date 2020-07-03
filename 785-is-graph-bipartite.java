class Solution {
    public boolean isBipartite(int[][] graph) {
        
        int n = graph.length;

        int[] color = new int[n];
        Arrays.fill(color, -1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                Stack<Integer> stack = new Stack<>();
                stack.push(i);
                color[i]=0;
                
                while(!stack.empty()){
                    Integer node = stack.pop();
                    for(int nn : graph[node]){
                        if(color[nn]==-1){
                            stack.push(nn);
                            color[nn]=color[node]^1;
                        }else if(color[nn]==color[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
}
