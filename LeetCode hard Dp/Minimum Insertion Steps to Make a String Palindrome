class Solution {
public:
    // recursion + memoization 
    vector<vector<int>> dp;
    int solve(string &s,int i,int j){
        if(i > j) return 0;
        else if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == s[j])
            return dp[i][j] = solve(s, i + 1, j - 1);
        else{
            return dp[i][j] = min(1 + solve(s,i+1,j), 1 + solve(s,i,j-1));
        }
    }
    int minInsertions(string s) {
        int n = s.size();
        // dp.assign(n+1,vector<int>(n+1,-1));
        // return solve(s,0,n-1);
        
        
        // top down approach 
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1; i>=0; i--){
            for(int j = i + 1; j<n; j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = min(1 + dp[i+1][j], 1 + dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
