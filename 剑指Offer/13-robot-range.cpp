class Solution {
public:
    //广度优先搜索
    int movingCount(int m, int n, int k) {
        if(!k) return 1;
        queue<pair<int,int>> Q;
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<int> > vis(m, vector<int>(n,0));
        Q.push(make_pair(0,0));
        vis[0][0] = 1;
        int ans =1;
        while(!Q.empty()){
            auto [x, y] = Q.front();
            Q.pop();
            for(int i = 0; i < 2; ++i){
                int tx = dx[i]+x;
                int ty = dy[i]+y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || digitSum(tx) + digitSum(ty) > k) continue;
                Q.push(make_pair(tx,ty));
                vis[tx][ty]=1;
                ans++;
            }
        }
        return ans;
    }
private:
    //
    int digitSum(int i){
        int ans =0;
        while(i>0){
            ans+= i%10;
            i/=10;
        }
        return ans;
    }
};

//剑指Offer解法
class Solution{
public:
    int movingCount(int m,int n,int k){
        //不能进入数位之和大于k的格子
        if(k<0 || m<=0||n<=0)
            return 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count = movingCountRecursive(k,m,n,vis);
        return count;
    }

private:
    int movingCountRecursive(int k, int m,int n, int i, int j, vector<vector<int>>& vis)
    {
        int count=0;
        if(check(k,m,n,i,j,vis))
        {
            vis[i][j]=1;

            count = 1 + movingCountRecursive(k,m,n,i-1,j,vis) + movingCountRecursive(k,m,n,i,j-1,vis) + movingCountRecursive(k,m,n,i+1,j,vis) + movingCountRecursive(k,m,n,i,j+1,vis);

        }
        return count;
    }

    bool check(int k, int m, int n, int i, int j, vector<vector<int>>& vis){
        return (i>=0 && i<m && j>=0 && j<n && getSum(i)+getSum(j)<=k && !vis[i][j]);
    }

    int getSum(int i){
        int ans = 0;
        while(i>0){
            ans+=i%10;
            i/=10;
        }
        return ans;
    }
};