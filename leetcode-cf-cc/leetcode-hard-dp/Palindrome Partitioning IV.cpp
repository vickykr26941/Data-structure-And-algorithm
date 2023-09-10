   // https://leetcode.com/problems/palindrome-partitioning-iv/


class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0; i<n; i++) dp[i][i] = 1;
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = 1;
            }
        }
        
        for(int k = 3; k<=n; k++){
            for(int i=0; i<n-k + 1; i++){
                int j = i + k - 1;
                if(dp[i+1][j-1] && s[i] == s[j]){
                    dp[i][j] = 1;
                }
            }
        }
        
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
              if(dp[0][i] && dp[i+1][j] && dp[j+1][n-1])
                  return true;
            }
        }
    return false;
    }
};
