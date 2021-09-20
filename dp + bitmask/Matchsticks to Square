/ *
  vicky kumar 
  date : 20/09/2021
  https://leetcode.com/problems/matchsticks-to-square/
*/


 // first approach : try all the possible ways to get result 
 // this might get TLE because 2 ^ 15 * (sum can go up to 10^8/4) 
 // even memoization of this will give us TLE 
   
   
   
   
    // TIME LIMT EXCEEDED 
// class Solution {
// public:
    
//     map<pair<int,vector<int>>,int> m;
//     int solve(vector<int>&v,int i,vector<int> vals){
//         if(i >= v.size()){
//             for(int j=0; j<vals.size(); j++){
//                 if(vals[j] != 0) return false;
//             }
//             return true;
//         }
//         else if(m.find({i,vals}) != m.end()) return m[{i,vals}];
        
//         bool ans = false;
//         for(int j = 0; j<vals.size(); j++){
//             vector<int> x = vals;
//             if(x[j] >= v[i]){
//                 x[j] -= v[i];
//                 ans |= solve(v, i + 1, x);
//             }
//         }
//        return m[{i,vals}] = ans;
//     }
//     bool makesquare(vector<int>& matchsticks) {
//         int n = matchsticks.size();
//         int s = 0;
//         for(int i = 0; i<n; i ++){
//             s += matchsticks[i];
//         }
        
//         if(s % 4 != 0) return false;
//         int x = s / 4;
//         vector<int> vals(4,x);

//         return solve(matchsticks,0,vals);
//     }
// };




  // first observation : there are 4 blocks and each blocks have equal sum sum(arr)/4 
  // take a mask and try all the possible ways while counting number of sides so far 
  // see the code for better understanding 
  
  

class Solution {
public:
    
    int dp[(1 << 15) + 10][5];
    int FINAL = 0,total_sum = 0,one_side = 0;
    int solve(vector<int>&v,int mask,int sides_cnt){
        if(mask == FINAL) return true;
        else if(dp[mask][sides_cnt] != -1) 
            return dp[mask][sides_cnt];
        
        int cur_sum =0 ;
        for(int j = 0; j<v.size(); j++){
            if((mask & (1 << j))){
                cur_sum += v[j];
            }
        }
        if(cur_sum > 0 && cur_sum % one_side == 0) sides_cnt++;
        if(sides_cnt == 3) return true;
        int blocks = cur_sum / one_side;
        int rem = (blocks + 1) * one_side - cur_sum; // one_side - {somthing}
        
        bool ans = false;
        for(int j = 0; j<v.size(); j++){
            if((mask & (1 << j)) == 0){
                if( v[j] <= rem){
                    ans |= solve(v, mask | (1 << j), sides_cnt);
                }
            }
        }
        return dp[mask][sides_cnt] = ans;
        
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int s = 0;
        for(int i = 0; i<n; i ++){
            s += matchsticks[i];
        }
        
        if(s % 4 != 0) return false;
        one_side = s / 4;
        
        FINAL = (1 << n ) - 1; 
        total_sum = s;
        
        memset(dp,-1,sizeof(dp));
        return solve(matchsticks,0,0);
    }
};
