class Solution {
public:
    
    const int inf = 1e9 + 7;
    vector<vector<int>> dp;
    int solve(vector<vector<int>> &v,int i,int j){
        if(i>=v.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = inf;
        
        for(int k=0; k<v[0].size(); k++){
            if(k==j) continue;
            int cur_res = v[i][j] + solve(v,i+1,k);
            ans = min(ans,cur_res);
        }
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        int n = mat.size(),m = mat[0].size();
        int ans = inf;
        
        dp.assign(n+1,vector<int>(m+1,-1));
        for(int i=0; i<m; i++){
            // dp.clear();
            // dp.assign(n+1,vector<int>(m+1,-1));
            ans = min(ans, solve(mat,0,i));
        }
        
    return ans;
    }
};
