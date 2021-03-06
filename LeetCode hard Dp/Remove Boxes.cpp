/*
  vicky kumar
  date : 01-07-2021
  source : // https://leetcode.com/problems/remove-boxes/
  LC : 546
*/

// explanation : 
// at each ith position we have two choice 
// 1) eiter we take the result and solve for the next   ans = (k + 1) * (k + 1) + solve(i+1,j,0);
 // where k is the number of same consecutive element 
 
 // 2) or we can associate this element with next same element to get higher result 
 

 
class Solution {
public:
    
    
    
    int dp[101][101][101];
    int solve(vector<int>&v,int i,int j,int k){
        if(i > j) return 0;
        else if(dp[i][j][k]!= -1)
            return dp[i][j][k];
        for(; i+1 <= j && v[i]==v[i+1]; i++) k++;
        int ans = (k + 1) * (k + 1) + solve(v,i+1,j,0);
        for(int m = i+1; m<=j; m++){
            if(v[i] == v[m]){
                ans = max(ans, solve(v,i+1,m-1,0) + solve(v,m,j,k+1));
            }
        }
        
        return dp[i][j][k] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                for(int k=0; k<=n; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(boxes,0,n-1,0);
    }
};




// optimized solution

// if we ovserv then we have always higher result when we remove all consecutive element toghether 
// so we can store the element with consecutive count and then can solve that will reduce the time to O(n^3) 

class Solution {
public:
    
    
    int dp[101][101][101];
    int solve(vector<vector<int>> &v,int i,int j,int k){
        if(i > j) return 0;
        else if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        int ans = (k+v[i][1]) * (k+v[i][1]) + solve(v,i+1,j,0);
        for(int m = i+1; m<=j; m++){
            if(v[i][0] == v[m][0]){
                ans = max(ans, solve(v,i+1,m-1,0) + solve(v,m,j,v[i][1] + k));
            }
        }
        return dp[i][j][k] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
       int n = boxes.size();
       vector<vector<int>> v;
        
       v.push_back({boxes[0],1});
       for(int i=1; i<n; i++){
           if(v[v.size()-1][0]==boxes[i])
               v[v.size()-1][1]++;
           else v.push_back({boxes[i],1});
       }
        
       for(int i=0; i<=n; i++){
           for(int j=0; j<=n; j++){
              for(int k=0; k<=n; k++){
                  dp[i][j][k] = -1;
              }
           }
       }
        
      return solve(v,0,v.size()-1,0);
    }
};
