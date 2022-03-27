// date : 27/03/2022
// sunday contest 

class Solution {
public:
    
    
    
    // time complexity : O(n *  k)
    // space complexity : O(n * k)
    const int inf = 1e9 + 7;
    vector<vector<int>> dp;
    int solve(vector<vector<int>> &v,int i, int k){
        if(i >= v.size())
            return k == 0 ? 0 : -inf;
        else if(k == 0) return 0;
        else if(k < 0) return -inf;
        else if(dp[i][k] != -1) return dp[i][k];
        
        int ans = solve(v, i + 1, k), val = 0, t = k;
        for(int j = 0; j<min(k,(int)v[i].size()); j++){
            val += v[i][j], t --;
            ans = max(ans, val + solve(v, i + 1, t));
        }
        return dp[i][k] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n = piles.size();
        dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return solve(piles,0,k);
    }
};

// 1000 *2000 * ()
