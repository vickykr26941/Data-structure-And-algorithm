/*
   vicky kumar
   date : 11/08/2021
   source : https://leetcode.com/problems/maximum-performance-of-a-team/
   
*/

// explanation : 
//   sort on the basis on efficiency (values)
//   assume each effieciency[i] as minimum and then taken first k maximum values from the prefix then calculate the answer ans specified in the question
  


class Solution {
public:
    
    const int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& values, int k) {
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            v.push_back({values[i],speed[i]});
        }
        sort(rbegin(v),rend(v));
        priority_queue<int,vector<int>,greater<int>> q;
        
        
        long long ans = 0, cur_sum = 0;
        for(int i=0; i<n; i++){
           q.push(v[i].second);
           cur_sum = (cur_sum + v[i].second);
           if(q.size() > k){
               int t = q.top(); q.pop();
               cur_sum -= t;
           }
           ans = max(ans, (cur_sum * v[i].first));
           
        }
        
    return ans % mod;
    }
};
