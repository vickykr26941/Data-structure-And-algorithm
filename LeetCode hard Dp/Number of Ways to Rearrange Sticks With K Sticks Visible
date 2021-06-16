
      // https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/


// explanation : 
// intution 
// if we place the gretest stick will be it will be visible from left side now problem reduces to -> f(n-1,k-1)
// we can place the any n - 1 element to the right of nth element so the problem reduces to -> (n - 1) * f(n - 1, k);


// base case is n == 0, and k == 0
// means we take all the elements and k sticks are visible from left side then return 1;



class Solution {
public:
    
    long mod = 1e9 + 7;
    
    vector<vector<int>> dp;
    long solve(long n,long k){
        if(n==0 && k==0)
            return 1;
        else if(n < 0 or k < 0) 
            return 0;
        else if(dp[n][k] != -1)
            return dp[n][k];
        return dp[n][k] = (solve(n - 1, k - 1)%mod + (n - 1) * solve(n - 1, k) %mod)%mod;
    }
    int rearrangeSticks(int n, int k) {
        
        dp.assign(n+1,vector<int>(k+1,-1));
        return solve(n,k);
    }
};
