    
    // https://leetcode.com/problems/stone-game-iii/
    
    // minMax algorithm
class Solution {
public:
    
    
    const int inf = 1e9 + 7;
    
    vector<vector<int>> dp;
    int max_val(int a,int b,int c){
        return max(max(a,b),c);
    }
    int min_val(int a,int b,int c){
        return min(min(a,b),c);
    }
    int solve(vector<int>&v,int i,int turn){
        int n = v.size();
        if(i>=n) return 0;
        else if(dp[i][turn] != -1)
            return dp[i][turn];
        int t = turn;
        int result = -inf, val = 0;
        if(t){
           for(int j=i; j<min(i+3,n); j++){
            val += v[j];
            result = max(result,val + solve(v,j+1,turn^1));
          } 
        }
        else{
            result = inf;
            for(int j=i; j<min(i+3,n); j++){
                val += v[j];
                result = min(result,-val + solve(v,j+1,turn^1));
            }
        }
        return dp[i][turn] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size(); 
        dp.assign(n+1,vector<int>(2,-1));
       int val = solve(stoneValue,0,1); 
       return val==0?"Tie" : val<0?"Bob":"Alice";
    }
};



// another method 
class Solution {
public:
    const int inf = 1e9 + 7;
    vector<int> dp;
    int solve(vector<int>&v,int i){
        int n = v.size();
        if(i>=n) return 0;
        else if(dp[i] != -1)
            return dp[i];
        int ans = -inf,val = 0;
        for(int j=i; j<min(i+3,n); j++){
            val += v[i];
            ans = max(ans, val - solve(v,j+1));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();
        dp.assign(n+1,-1);
        int res = solve(arr,0);
        
        return res==0?"Tie":res<0?"Bob":"Alice";
    }
};
