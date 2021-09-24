

/ * vicky kumar 
    date: 24/09/2021
    source : https://leetcode.com/problems/maximize-score-after-n-operations/
*/


// explanation : try all possible ways to select two elements and memoize to reduce the time complexity 


class Solution {
public:
    
    
    
    int dp[(1 << 14) + 10][15];
    int gcd(int a,int b){
        return b == 0 ? a : gcd(b,a % b);
    }
    int FINAL = 0, N;
    int solve(vector<int>&arr,int mask,int op){
       if(mask == FINAL) return 0;
       else if(dp[mask][op] != -1) 
           return dp[mask][op];
        
        int ans = 0;
        for(int i = 0; i<N; i++){
            int t = mask;
            if((mask & (1 << i)) == 0){
                t |= (1 << i);
                for(int j = 0; j<N; j++){
                    int vt = t;
                    if((vt & (1 << j)) == 0){
                        vt |= (1 << j);
                        ans = max(ans, op * gcd(arr[i],arr[j]) + solve(arr,vt,op + 1));
                }
            }
        }
        
        return dp[mask][op] = ans;
    }
    int maxScore(vector<int>& arr) {
        int n = arr.size();
        FINAL = (1 << n) - 1;
        N = n;
        
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,1);
    }
};
