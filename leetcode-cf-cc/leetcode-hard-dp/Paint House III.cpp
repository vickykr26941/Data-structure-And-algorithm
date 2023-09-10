
 // https://leetcode.com/problems/paint-house-iii/


// intution 
// go for brute force and memoized to get optimized (top down dp)
// case 1 :
// if the ith house is already painted 
// then it either could be same as previouse painted houses, then theres is no increment in neighbordhoods
// otherwise 1 neighbordhoods will increse

// case2:
// if the house is not painted 
// we can paint with any color with the cost  cost[i][color-1]
// start painting with all possible colors and take the minimum possible answer
// while painting there could be two case as case1



class Solution {
public:
    
    const int inf = 1e9 + 7;
    int M , N, final_val;
    
    
    vector<vector<vector<int>>> dp;
    int solve(vector<int>&houses,vector<vector<int>>&cost,int i,int pre,int k){
       if(i==M && k==0) return 0;
       else if(i>=M or k<0) return inf;
       else if(dp[i][pre + 1][k] != -1)
           return dp[i][pre + 1][k];
       int ans = inf;
        
       if(houses[i]>0){
          if(pre==houses[i])
              ans = min(ans,solve(houses,cost,i+1,houses[i],k));
          else ans = min(ans,solve(houses,cost,i+1,houses[i],k-1));
       }
       else{
           for(int color = 1; color<=N; color++){
               if(pre==color)
                   ans = min(ans,cost[i][color-1] + solve(houses,cost,i+1,color,k));
               else ans = min(ans, cost[i][color-1] + solve(houses,cost,i+1,color,k-1));
           }
       }
    return dp[i][pre + 1][k] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        M = m, N = n;
        
        dp.assign(m+5,vector<vector<int>>(n+10,vector<int>(target+1,-1)));
        final_val = target;
        int val = solve(houses,cost,0,-1,target);
        return val==inf?-1:val;
    }
};

// f(i,j)-> minimum cost to paint till ith house , previous painted house is j
