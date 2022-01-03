


// jan 4 2022
// https://leetcode.com/problems/maximum-students-taking-exam/

class Solution {
public:
    int maxStudents(vector<vector<char>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<int> avl(n,0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(arr[i][j] == '.'){
                    avl[i] |= (1 << j);
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(1 << m,-1));
        for(int mask = 0; mask < 1 << m; mask ++)
            dp[0][mask] = 0;
        
        for(int i = 1; i<=n; i++){
            for(int premask = 0; premask < 1 << m; premask ++){
                if(dp[i - 1][premask] == -1) continue; // if previous state is not valid 
                for(int mask = 0; mask < 1 << m; mask ++){
                    if((mask & avl[i - 1]) != mask) continue; // current mask should be subset of availabe students
                    if(mask & mask >> 1) continue; // there should not be any adjecent students 
                    
                    // chek top left, top right 
                    if((mask & premask << 1) || (mask & premask >> 1)) continue;
                    dp[i][mask] = max(dp[i][mask], dp[i - 1][premask] + __builtin_popcount(mask));
                }
            }
        }
        
        return *max_element(begin(dp[n]),end(dp[n]));
    }
};




