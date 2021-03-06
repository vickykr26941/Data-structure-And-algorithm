/*
  vicky kumar
  date : 24/07/2021
  source : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/

//  hint : dp + dfs 

class Solution {
public:
    
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    
    int valid(int i,int j,int n,int m){
         if(i >=n or j>=m or i<0 or j < 0) return 0;
         return 1;
    }
    
    vector<vector<int>> dp;
    int solve(vector<vector<int>> &v,int i,int j,int prev){
        int n = v.size(), m = v[0].size();
        if(!valid(i,j,n,m)) return 0;
        else if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        for(int k =0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(valid(x,y,n,m)){
                if(v[x][y] > prev){
                   ans = max(ans,1 + solve(v,x,y,v[x][y]));
                }
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        dp.assign(n+1,vector<int>(m+1,-1));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // dp.assign(n+1,vector<int>(m+1,-1));  // slower 
                ans = max(ans, 1 + solve(mat,i,j,mat[i][j]));
            }
        }
        
    return ans;
    }
};

