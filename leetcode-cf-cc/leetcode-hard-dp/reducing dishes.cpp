
   // https://leetcode.com/problems/reducing-dishes/
class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &arr,int n,int t){
        if(n<=0) return 0;
        if(dp[n][t]>=0){
            return dp[n][t];
        }
        return dp[n][t] = max(solve(arr,n-1,t),arr[n-1]*t + solve(arr,n-1,t+1));
    }
    int maxSatisfaction(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr),end(arr),[&](int x,int y){return x>y;});
        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(arr,arr.size(),1);
    }
};
