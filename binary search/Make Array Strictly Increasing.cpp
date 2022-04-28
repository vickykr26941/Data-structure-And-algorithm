/*
  vicky kumar
  date : 06/07/2021
  problem : https://leetcode.com/problems/make-array-strictly-increasing/
  
 */

   // sort the second array 
  // 1) if prev element is less then current element the take it and move forward
  // 2 ) else find the smallest greater element then prev in second array and move forward 
    // now prev will be sallest greated element of the second array 


class Solution {
public:
    
    const int inf = 1e9 + 7;
    
    map<pair<int,int>,int> dp;
    int solve(vector<int>&a,vector<int>&b, int pos,int prev){
        if(pos>=a.size()) return 0;
        else if(dp.find({pos,prev}) != dp.end()) 
             return dp[{pos,prev}];
        
        int ans = inf;
        int j = upper_bound(begin(b),end(b), prev) - begin(b);
        if(prev < a[pos]) 
            ans = min(ans, solve(a,b,pos+1,a[pos]));
        if(j < b.size()){
            ans = min(ans, 1 + solve(a,b,pos+1,b[j]));
        }
        return dp[{pos,prev}] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2),end(arr2));
        int val =  solve(arr1,arr2,0,-1);
        
        return val == inf?-1 : val;
    }
};
