   // https://leetcode.com/problems/shortest-common-supersequence/


class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0) dp[i][j] = j;
                else if(j==0) dp[i][j] = i;
                else if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                }
            }
        }
        string res; 
        int i = n,j = m;
        while(i>0 && j>0){
            if(s[i - 1] == t[j - 1]){
                res += s[i - 1];
                i--,j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                res += t[j - 1];
                j--;
            }
            else{
                res += s[i - 1];
                i--;
            }
        }
        while(i > 0){
            res += s[i - 1];
            i--;
        }
        while(j > 0){
            res += t[j - 1];
            j--;
        }
        reverse(begin(res),end(res));
        return res;
    }
};

// abac 
// cab
