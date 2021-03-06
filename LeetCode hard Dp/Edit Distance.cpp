// class Solution {
// public:
    
//     vector<vector<int>> dp;
//     int min_val(int a,int b,int c){
//         return min(min(a,b),c);
//     }
//     int solve(string &s,string &t,int n,int m){
//         if(n==0) return m;
//         else if(m==0) return n;
//         if(dp[n][m]!=-1){
//             return dp[n][m];
//         }
//         if(s[n-1]==t[m-1]){
//             return dp[n][m] = solve(s,t,n-1,m-1);
//         }else{
//             return dp[n][m] = min_val(solve(s,t,n-1,m-1),solve(s,t,n-1,m),solve(s,t,n,m-1)) + 1;
//         }
//     }
//     int minDistance(string word1, string word2) {
//         int n = word1.size(), m = word2.size();
//         dp.assign(n + 1, vector<int>(m+1,-1));
//         return solve(word1,word2,word1.size(), word2.size());
//     }
// };
 // doing operation on string 1
// insert : n, m - 1
// delete : n -1, m
// replace :n - 1, m - 1





class Solution {
public:
    
    int min_val(int a,int b,int c){
        return min(min(a,b),c);
    }
    int minDistance(string s, string t) {
       int n = s.size(), m = t.size();
       vector<vector<int>> dp(n + 1, vector<int>(m+1,0));
        
       for(int i = 0; i<=n; i++){
           for(int j=0; j<=m; j++){
               if(i==0){
                   dp[i][j] = j;
               }
               else if(j==0){
                   dp[i][j] = i;
               }
               else if(s[i-1]==t[j-1]){
                   dp[i][j] = dp[i-1][j-1];
               }
               else{
                  dp[i][j] = min_val(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]) + 1;
               }
           }
       }
        
    return dp[n][m];
    }
};
