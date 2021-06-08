         // https://leetcode.com/problems/jump-game-v/
 
 // recursion + memoization
 // question is straight forward just do as question is stated using recursion 
 // momoized the result to optimized the result

class Solution {
public:
    
    vector<int> dp;
    int solve(vector<int>&v,int i,int d){
        int n = v.size();
        if(i>=n or i < 0) return 0;
        else if(dp[i] != -1)
            return dp[i];
        int ans = 0;
        for(int j=i+1; j<min(i + d + 1, n); j++){
            if(v[j] >= v[i]) break;
            ans = max(ans, 1 + solve(v,j,d));
        }
        for(int j=i-1; j>=max(0,i-d); j--){
            if(v[j] >= v[i]) break;
            ans = max(ans, 1 + solve(v,j,d));
        }
        return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size(), ans = 0;
        
        dp.assign(n+1,-1);
        for(int i=0; i<n; i++){
            ans = max(ans, 1 + solve(arr,i,d));
        }
    return ans;
    }
};



// make the directed edges from downwards to the left and downwards to the right
// now this problem is transformed to the : find the longes path in directed acylic graph
// find the longest path starting from each index 


class Solution {
public:
    
    
    vector<vector<int>> g;
    
    int dfs(int v,vector<int>&dp){
        if(dp[v] != -1)
            return dp[v];
        int ans = 0;
        for(auto x : g[v]){
            ans = max(ans, 1 + dfs(x,dp));
        }
        dp[v] = ans;
        return ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        stack<int> stk;
        
        g.resize(n);
        // add edges downwards to the left side
        for(int i=0; i<n; i++){
            while(stk.size()>0 && arr[stk.top()] < arr[i]){
                if(abs(i - stk.top()) <= d)
                    g[i].push_back(stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        
        // add edges downwards to the right side
        
        while(stk.size()>0) stk.pop();
        for(int i=n-1; i>=0; i--){
            while(stk.size() > 0 && arr[stk.top()] < arr[i]){
                if(abs(i - stk.top()) <= d)
                    g[i].push_back(stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        
        int ans = 0;
        vector<int> dp(n,-1);
        for(int i=0; i<n; i++){
            ans = max(ans, 1 + dfs(i,dp));
        }
        
    return ans;
    }
};
