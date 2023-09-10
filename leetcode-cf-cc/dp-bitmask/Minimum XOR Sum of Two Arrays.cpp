/*
  auther : vicky kumar
  date : 15/08/2021
  problem : https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/
*/

// explanation : 
//   for each a[i] take b[j] in the second array and keep track to selected element from the 2nd array using mask
//   then transition  ans = min(ans, a[i] ^ a[j] + f(i+1,mask|(1<<j)) for all j in 2nd array where jth element is not selected 
  
  
  

class Solution {
public:
    const int inf = INT_MAX;
    int FINAL = 0;
    int dp[15][(1<<14) + 1];
    int solve(vector<int>&v1,vector<int>&v2,int i,int mask){
        if(i>=v1.size() && mask == FINAL)
            return 0;
        else if(dp[i][mask] != -1)
            return dp[i][mask];
        
        int ans = inf;
        for(int j=0; j<v2.size(); j++){
            if(mask&(1<<j)) continue;
            ans = min(ans, (v1[i]^v2[j]) + solve(v1,v2,i+1,mask|(1<<j)));
        }
        return dp[i][mask] = ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        FINAL = (1 << n) - 1;
        
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,0,0);
    }
};

