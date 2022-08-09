/*
  auther : vicky kumar
  date : 14/08/2021
  source : https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/
  
*/


// solution : try to connect points from first group to the second group if all the first group points are connected 
// to some points of second group, then try to connect all the remaining points from second group to the first group 
// memoize using dp : time complexity -> O(2 ^ n * 2 ^ n) -> 2 ^ 24 > 10^8 
// so, this is TLE


// think in another way
// look to the constrains one more time 
class Solution {
public:
    
    const int inf = INT_MAX;
    int final1 = 0, final2 = 0;
    
   int dp[(1<<12) + 1][(1<<12) + 1];
    int solve(vector<vector<int>> &cost,int mask1,int mask2){
        int n = cost.size(), m = cost[0].size();
        if(mask1==final1 && mask2 == final2){
            return 0;
        }
        else if(dp[mask1][mask2] != -1)
            return dp[mask1][mask2];
        
        int ans = inf;
        if(mask1 != final1){
            for(int i=0; i<n; i++){
                if((mask1&(1<<i)) == 0){
                    for(int j=0; j<m; j++){
                     ans = min(ans, cost[i][j] + solve(cost,mask1|(1<<i), mask2|(1<<j)));
                  }
                }  
            }
        }
        if(mask2 != final2){
             for(int j=0; j<m; j++){
                if((mask2&(1<<j)) == 0){
                  for(int i=0; i<n; i++){
                    ans = min(ans,cost[i][j] + solve(cost,mask1|(1<<i), mask2|(1<<j)));
                  }  
                }
            }
        }
        return dp[mask1][mask2] = ans;
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size();
        final1 = (1 << n) - 1, final2 = (1 << m) - 1;
        
        memset(dp,-1,sizeof(dp));
        return solve(cost,0,0);
    }
};



// try to connect each point to first group with 2nd group and keep a mask which points are connected from 2nd group and 
// which are remaing , once all points from left side is connected it's may be some point reaming from 2nd group which are not connected
// for that connect with minimum one on left side , this can be precalculated in a vector
// time complexity : O(N * M * 2 ^ M)
class Solution {
public:
    const int inf = INT_MAX;
    int min_j[13];
    
    
    vector<vector<int>> dp;
    int solve(vector<vector<int>> &cost,int i,int mask){
        int n = cost.size(), m = cost[0].size();
        if(i >= n){
            int take = 0;
            for(int j=0; j<m; j++){
                if((mask&(1<<j)) == 0){
                    take += min_j[j];
                }
            }
            
        return take;
        }
        else if(dp[i][mask] != -1){
            return dp[i][mask];
        }
        
        int ans = inf;
        for(int j=0; j<m; j++){
            ans = min(ans, cost[i][j] + solve(cost,i+1,mask|(1<<j)));
        }
        return dp[i][mask] = ans;
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size();
        for(int i=0; i<13; i++){
            min_j[i] = inf;
        }
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                min_j[j] = min(min_j[j], cost[i][j]);
            }
        }
        dp.assign(n+1,vector<int>((1<<m), -1));
        return solve(cost,0,0);
    }
};



