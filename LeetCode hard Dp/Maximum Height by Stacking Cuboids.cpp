   // https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

class Solution {
public:
    int check(vector<int>&a,vector<int>&b){
        return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
    }
    int maxHeight(vector<vector<int>>& a) {
       int n = a.size();
       for(auto &x : a){
           sort(begin(x),end(x));
       }
       sort(begin(a),end(a),[&](vector<int> &x,vector<int>&y){
           if(x[0] != y[0])
               return x[0] < y[0];
           else if(x[1] != y[1])
               return x[1] < y[1];
           else return x[2] < y[2];
       });
        
     
     vector<int> dp(n,0);
     for(int i=0; i<a.size(); i++){
         dp[i] = a[i][2];
     }
    
        
     int res = 0;
     for(int i=0; i<n; i++){
         for(int j=0; j<i; j++){
             if(check(a[j],a[i])){
                 dp[i] = max(dp[i], dp[j] + a[i][2]);
             }
         }
         
     res = max(res, dp[i]);
     }
    return res;
    }
};
