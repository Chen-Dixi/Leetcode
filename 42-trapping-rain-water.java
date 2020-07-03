class Solution {
    public int trap(int[] height) {
        int length = height.length;
        if(length<=0)
            return 0;

        int ans=0;
        int[] right_max = new int[length];
        int[] left_max = new int[length];
        left_max[0]=height[0];
        right_max[length-1]=height[length-1];
        for(int i=1;i<length;i++){
            left_max[i] = Math.max(left_max[i-1],height[i]);
        }
        for(int i=length-2;i>=0;i--){
            right_max[i] = Math.max(right_max[i+1],height[i]);
        }
        for(int i=0;i<length;i++){
            ans += (Math.min(left_max[i],right_max[i]) - height[i]);
        }
        return ans;
    }
}

class Solution {
    public int trap(int[] height) {
        int left=0,right=height.length-1;

        int left_max = 0, right_max = 0;
        int ans = 0;
        while(left<right){
            if( height[left] < height[right] ){
                if(height[left] >= left_max) 
                    left_max = height[left];
                else
                    ans += (left_max-height[left]);
                left++;
            }else{
                if(height[right] >= right_max) 
                    right_max = height[right];
                else
                    ans+=(right_max - height[right]);
                right--;
            }
        }
        return ans;
    }
}