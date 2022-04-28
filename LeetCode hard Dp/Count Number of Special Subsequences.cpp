

/*
  
  
  vicky kumar 
  date : 01/08/2021
  source : https://leetcode.com/problems/count-number-of-special-subsequences
*/


class Solution {
public:
    
    const int mod = 1e9 + 7;
    int dp[100001][4][8];
    int solve(vector<int>&v,int i,int prev,int mask){
        if(i >= v.size()){
            return mask == 7;
        }
        else if(dp[i][prev][mask] != -1)
            return dp[i][prev][mask];
        int ans = 0;
        if(v[i] >= prev){
            // tow choices 
            ans = solve(v,i+1,v[i],mask|(1<<v[i]));
            ans %= mod;
            ans += solve(v,i+1,prev,mask);
            ans %= mod;
        }
        else{
            // no choice
            ans += solve(v,i+1,prev,mask);
            ans %= mod;
        }
        return dp[i][prev][mask] = ans;
    }
    int countSpecialSubsequences(vector<int>& arr) {
        int n = arr.size();
        
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,0,0);
    }
};
