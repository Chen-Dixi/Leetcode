class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        vector<int> ans;
        if(len<=0)
            return ans;

        int left[len];
        int right[len];

        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        left[0]=1;
        right[len-1]=1;
        for(int i=1; i<len;i++){
            left[i] = left[i-1]*a[i-1];
            right[len-1-i] = a[len-i]*right[len-i];
        }

        for(int i=0;i<len;i++){
            ans.push_back(left[i]*right[i]);
        }

        return ans;
    }
};