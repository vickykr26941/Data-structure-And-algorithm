/*
    auther : vicky kumar 
    date : 06/07/2021
    problem : https://leetcode.com/problems/shortest-path-visiting-all-nodes/
*/


  // find the distance between each pairs of nodes using foloyed warshal algorithm
  // then apply traviling salseman algorithm from each node to find the answer 
  // as nodes are very less : time complexity n * (1 << n) 
 

class Solution {
public:
    
    int MASK = 0, inf = 1e9 + 7;
    vector<vector<int>> dist;
    
    int dp[13][1<<13];
    int solve(int i,int mask,int n){
        if(mask == MASK) return 0;
        else if(dp[i][mask] != -1)
            return dp[i][mask];
        int ans = inf;
        for(int j=0; j<n; j++){
            if(mask&(1<<j)) continue;
            ans = min(ans, dist[i][j] + solve(j,mask|(1<<j), n));
        }
        
        return dp[i][mask] = ans;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        dist = vector<vector<int>>(n,vector<int>(n,inf));
        
        for(int i=0; i<n; i++) dist[i][i] = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                dist[i][graph[i][j]] = 1;
                dist[graph[i][j]][i] = 1;
            }
        }
        

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                   dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
      
        MASK = (1<<n) - 1;
        int ans = inf;
        for(int i=0; i<n; i++){
            memset(dp,-1,sizeof dp);
            ans = min(ans, solve(i,0,n));
        }
    return ans;
    }
};
