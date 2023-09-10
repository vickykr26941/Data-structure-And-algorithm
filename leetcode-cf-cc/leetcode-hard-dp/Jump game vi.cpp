
/*
  date : 26/10/2021
  problem : https://leetcode.com/problems/jump-game-vi/
*/




  // brute force dp solution 
// class Solution {
// public:
    
//     vector<vector<int>> dp;
//     int solve(vector<int> &v,int k,int i){
//         if(i >= v.size() - 1) return v[v.size() - 1];
//         else if(dp[i][k] != -1) return dp[i][k];
//         int ans = INT_MIN;
//         for(int j = 1; j<=k; j++){
//             ans = max(ans,v[i] + solve(v,k,i + j));
//         }
//         return dp[i][k] = ans;
//     }
//     int maxResult(vector<int>& arr, int k) {
//        int n = arr.size();
//        dp.assign(n + 1, vector<int>(k + 1, -1));
//        return solve(arr,k,0);
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> dp;
//     int solve(vector<int> &v,int i,int k){
//         int n = v.size();
//         if(i >= v.size() - 1) return v[v.size() - 1];
//         else if(dp[i][k] != -1) return dp[i][k];
//         int ans = INT_MIN;
//         for(int j = i + 1; j<=(i + k); j++){
//             ans = max(ans,v[i] + solve(v,j,k));
//         }
//         return dp[i][k] = ans;
//     }
//     int maxResult(vector<int>& arr, int k) {
//        int n = arr.size();
       
//        dp.assign(n + 1, vector<int>(k + 1, -1));
//        return solve(arr,0,k);
//     }
// };



   // time complexity N * log(n) * log(n)
class Solution {
public:
    int maxResult(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,0);
        
        multiset<int> st;
        for(int i = 0; i < n; i++){
            if(i > k){
                st.erase(st.find(dp[i - k - 1]));
            }
            dp[i] = arr[i];
            if(st.size() > 0){
                auto it = --end(st);
                dp[i] += *it;
            }
            st.insert(dp[i]);
        }
        return dp[n - 1];
    }
};

