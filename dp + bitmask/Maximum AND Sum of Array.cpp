// date : 7/7/22
// LC : 2172

// class Solution {
// public:
//     // time : (2 ^ 18 * 9 * 30) TLE
    
//     int FINAL_MASK = 0;
//     int dp[(1 << 18) + 1][10];
//     int solve(vector<int> &v, int i, int n, int mask){
//         if(i >= (n + 1)) return 0;
//         if(dp[mask][i] != -1) return dp[mask][i];
        
        
//         int ans = solve(v, i + 1, n, mask);
//         for(int j = 0; j < v.size(); j++){
//             if( ((1 << j) & mask) == 0)
//                 ans = max(ans, (v[j] & i ) + solve(v, i + 1, n, mask | (1 << j)));
//             if( ((1 << j) & mask) == 0){
//                 int t = mask | (1 << j);
//                 for(int k = j + 1; k < v.size(); k++){
//                     if( ((1 << k) & t) == 0){
//                         int x = t | ( 1 << k);
//                         int val = (v[j] & i) + (v[k] & i);
//                         ans = max(ans, val + solve(v, i + 1, n, x));
//                     }
//                 }
//             }
//         }
        
        
//         return dp[mask][i] = ans;
//     }
//     int maximumANDSum(vector<int>& nums, int numSlots) {
        
//         FINAL_MASK = (1 << 15) - 1;
        
//         memset(dp, -1, sizeof(dp));
//         return solve(nums, 0, numSlots, 0);
//     }
// };



// use ternary number system for mask 
// and store the slot in that

 
class Solution {
public:
   
    int n = 0;
    
//     here the ith bit store either 0, 1, 2
//     so we can track that a slot have atmost 2 elements 
//     ith bit can be found by (mask / pow(3, i)) % 3
//     time complexity : n * (3 ^ k) * k -> nk(3 ^ k)
    
//     3 ^ 9 = 19683
    int dp[59049][19];
    
    int solve(vector<int> &v, int i, int mask){
        
        if(i >= v.size()) return 0;
        if(dp[mask][i] != -1) return dp[mask][i];
        
        int ans = 0;
        for(int slot = 1; slot <= n; slot++){
            int current = (mask / (int)pow(3, slot)) % 3;
            if(current <= 1){
                ans = max(ans, (v[i] & slot) + solve(v, i + 1, mask + (int)pow(3, slot)));
            }
        }
        
        return dp[mask][i] = ans;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        
        n = numSlots;
        
        memset(dp, -1, sizeof(dp));
       return solve(nums, 0, 0);
    }
};

