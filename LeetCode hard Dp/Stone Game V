
   // https://leetcode.com/problems/stone-game-v/

class Solution {
public:
    vector<vector<int>> dp;
    vector<int> sum;
    int val_sum(vector<int>&v,int l,int r){
        return sum[r] - ((l-1)>=0 ? sum[l-1] : 0);
    }
    int solve(vector<int>&v,int i,int j){
        if(i>=j or i>=v.size() or j<0) return 0;
        else if(dp[i][j] != -1)
            return dp[i][j];
        
        int val = 0;
        for(int k=i; k<=j; k++){
            int left = val_sum(v,i,k);
            int right = val_sum(v,k+1,j);
            if(left>right){
                val = max(val, right + solve(v,k+1,j));
            }
            else if(right>left){
                val = max(val, left + solve(v,i,k));
            }
            else{
                val = max(val, left + solve(v,i,k));
                val = max(val, right + solve(v,k+1,j));
            }
        }
        return dp[i][j] = val;
    }
    int stoneGameV(vector<int>& arr) {
        int n = arr.size();
        sum.assign(n,0);
        sum[0] = arr[0];
        for(int i=1; i<n; i++)
            sum[i] = sum[i-1] + arr[i];
        
        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(arr,0,n-1);
    }
};




     // 
class Solution {
public:
    vector<int> sum;
    vector<vector<int>> dp;
    int get_sum(vector<int>&v,int l,int r){
        int s = 0;
        for(int i=l; i<=r; i++)
            s += v[i];
        return s;
    }
    int solve(vector<int>&v,int i,int j){
        if(i>=j) return 0;
        int val = 0;
        for(int k=i; k<=j; k++){
            int L = get_sum(v,i,k), R = get_sum(v,k+1,j);
            int l = solve(v,i,k), r = solve(v,k+1,j);
            if(L>R){
                val = max(val, r + R);
            }
            else if(R>L){
                val = max(val, l + L);
            }
            else{
                val = max(val,l + L);
                val = max(val,r + R);
            }
        }
        return val;
    }
    int stoneGameV(vector<int>& arr) {
       int n = arr.size();
       return solve(arr,0,n-1);
    }
};
