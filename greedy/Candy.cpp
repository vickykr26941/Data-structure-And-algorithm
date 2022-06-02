/*
  vicky kumar
  date : 11/08/2021
  source : https://leetcode.com/problems/candy/
*/

// explanations : give one candy to each child then greedly give candy to left then from right that would be optimal distrubution 


class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        vector<int> v(n,1);
        
        for(int i=1; i<n; i++){
            if(a[i] > a[i-1]){
                v[i] = v[i-1] + 1;
            }
        }
        
        for(int i=n-2; i>=0; i--){
            if(a[i] > a[i+1] && v[i] <= v[i+1]){
                v[i] = v[i + 1] + 1;
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += v[i];
        }
        
        
    return ans;
    }
};
