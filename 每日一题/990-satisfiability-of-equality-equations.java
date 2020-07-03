class Solution {
    public boolean equationsPossible(String[] equations) {
        int len = equations.length;
        if(len<1)return true;
        int [] parent = new int[26];//并查集初始化,26个字母
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(String str:equations){
            if(str.charAt(1)=='='){
                int index1 = str.charAt(0) - 'a';
                int index2 = str.charAt(3) - 'a';
                union(parent, index1, index2);
            }
        }

        for(String str: equations){
            
            if(str.charAt(1)=='!'){
                int index1 = str.charAt(0) - 'a';
                int index2 = str.charAt(3) - 'a';
              
                if(find(parent,index1) == find(parent,index2) ){
                    return false;
                }
            }
        }
        return true;
    }

    private void union(int[] parent, int x, int y){
        int a = find(parent,x);
        int b = find(parent,y);
        if(a == b)
            return;
        parent[a] = b;
    }

    private int find(int[] parent, int x){
        return parent[x]==x ? x : (parent[x] = find(parent,parent[x]));
    }
}