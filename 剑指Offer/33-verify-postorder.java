class Solution {
    public boolean verifyPostorder(int[] postorder) {

        
        int len = postorder.length;

        if(len<=0)
            return true;

        return verify(postorder, 0, len-1);

    }

    private boolean verify(int []postorder, int l, int r){
        if(l>=r){
            return true;
        }
        int root = postorder[r];
        int i = l;
        for(;i<r;i++){
            if(postorder[i]>root)
                break;
        }

        int p = i++;
        for(;i<r;i++)
            if(postorder[i]<root)
                return false;

        return verify(postorder,l,p-1) && verify(postorder,p,r-1);
    }
}