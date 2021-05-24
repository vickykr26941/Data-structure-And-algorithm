 // https://leetcode.com/problems/number-of-paths-with-max-score/
 // accepted time & space O(N * N)

class Solution {
public:
    const int mod = 1e9 + 7;
    int max_val(int a,int b,int c){
        return max(max(a,b),c);
    }
    vector<int> pathsWithMaxScore(vector<string>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]=='E' or mat[i][j]=='S')
                    v[i][j] = 0;
                else if(mat[i][j]=='X')
                    v[i][j] = -1;
                else{
                    v[i][j] = mat[i][j] - '0';
                }
            }
        }
        
        vector<vector<int>> score(n,vector<int>(m,0)),path(n,vector<int>(m,0));
        path[0][0] = 1;
        for(int i=1; i<m; i++){
            if(v[0][i] != -1)
                score[0][i] = score[0][i-1] + v[0][i],path[0][i] = 1;
            else break;
        }
        for(int i=1; i<n; i++){
            if(v[i][0] != -1)
                score[i][0] = score[i-1][0] + v[i][0],path[i][0] = 1;
            else break;
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(v[i][j] != -1){
                    int cur_max = max_val(score[i-1][j-1],score[i-1][j],score[i][j-1]);
                    int path_val = max_val(path[i-1][j-1],path[i-1][j],path[i][j-1]);
                    if(path_val>0){
                        if(cur_max == score[i-1][j-1])
                            path[i][j] = (path[i][j] + path[i-1][j-1])%mod;
                        if(cur_max == score[i-1][j])
                            path[i][j] = (path[i][j] + path[i-1][j] ) % mod;
                        if(cur_max == score[i][j-1])
                            path[i][j] = (path[i][j] + path[i][j-1]) %mod;
                        
                        score[i][j] = cur_max + v[i][j];
                    }
                }
            }
        }
        int score_val = score[n-1][m-1];
        int path_cnt = path[n-1][m-1];
        return vector<int>{score_val,path_cnt};
    }
};







   // recursion + backtracking TLE
// class Solution {
// public:
//     const int mod = 1e9 + 7;
//     vector<vector<vector<int>>> dp;
//     int solve(vector<vector<int>>&g,int i,int j,int val){
//         int n = g.size(), m = g[0].size();
//         if(i >=n or j>=m or i<0 or j<0 or g[i][j]==-1 or g[i][j]==-2 or val < 0)
//             return 0;
//         else if(i==n-1 && j==m-1){
//             return val == 0;
//         }
//         else if(dp[i][j][val] != -5)
//             return dp[i][j][val];
        
//         int t = g[i][j];
//         g[i][j] = -2;
//         int cur_res = solve(g,i+1,j,val-t) + solve(g,i,j+1,val-t) + solve(g,i+1,j+1,val - t);
//         g[i][j] = t;
//         return dp[i][j][val] = cur_res % mod;
//     }
//     int max_val(int a,int b,int c){
//         return max(max(a,b),c);
//     }
//     vector<int> pathsWithMaxScore(vector<string>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();
//         vector<vector<int>> dp1(n,vector<int>(m,0));
        
//         int val = 0;
//         for(int i=1; i<m; i++){
//             if(mat[0][i]=='X')
//                 break;
//             else val += mat[0][i] - '0';
//             dp1[0][i] = val;
//         }
//         val = 0;
//         for(int i=1; i<n; i++){
//             if(mat[i][0]=='X')
//                 break;
//             else val =(val + mat[i][0] - '0') %mod;
//             dp1[i][0] = val;
//         }
//         for(int i=1; i<n; i++){
//             for(int j=1; j<m; j++){
//                 if(mat[i][j] != 'X'){
//                     int cur_val = max_val(dp1[i-1][j-1],dp1[i-1][j],dp1[i][j-1]);
//                     if(cur_val > 0){
//                         dp1[i][j] = (cur_val + (mat[i][j]=='S'?0:mat[i][j]-'0'));
//                     }
//                 }
//             }
//         }
        
//         vector<vector<int>> g(n,vector<int>(m,0));
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(mat[i][j]=='X')
//                     g[i][j] = -1;
//                 else if(mat[i][j]=='S' or mat[i][j]=='E')
//                     g[i][j] = 0;
//                 else{
//                     g[i][j] = mat[i][j] - '0';
//                 }
//             }
//         }
//         val = dp1[n-1][m-1];
//         dp.assign(n+1,vector<vector<int>>(m+1,vector<int>(val+1,-5)));
//         int ans = solve(g,0,0,val); 
//         return vector<int>{val,ans};
//     }
// };

// E 1 3 4 
// 1 4 5 6
// 5 2 4 S


// E 1 2
// 1 X 1
// 2 1 S
