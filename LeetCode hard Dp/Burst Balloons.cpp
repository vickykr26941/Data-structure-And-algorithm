
    // recursion + memoization 
public: 
    vector<vector<int>> dp;
    int solve(vector<int>&a,int i,int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        int ans = 0;
        for(int k=i; k<j; k++){
            int x = solve(a,i,k);
            int y = solve(a,k+1,j);
            ans = max(ans, x + y + a[i-1] * a[k] * a[j]);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& arr) {
        int n = arr.size();
        vector<int> a(n+2,0);
        a[0] = 1;
        int i = 1;
        for(auto &x : arr) a[i++] = x;
        a[i++] = 1;
        dp.assign(n+2,vector<int>(n+2,-1));
        return solve(a,1,n+1);
    }
};



  // top down approach 
class Solution {
public:
    int maxCoins(vector<int>& arr) {
        int n = arr.size();
        vector<int> a(n+2,0);
        a[0] = 1;
        int i = 1;
        for(auto &x : arr)
            a[i++] = x;
        a[i++] = 1;
        
        n = n + 2;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int L=2; L<=n; L++){
            for(int i=1; i<n-L + 1; i++){
                int j = i + L - 1;
                for(int k=i; k<j; k++){
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j]);
                }
            }
        }
     return dp[1][n-1];
    }
};
