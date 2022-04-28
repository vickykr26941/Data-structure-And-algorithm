/*
  vicky kumar
  date : 05/07/2021
  problem : https://leetcode.com/problems/minimum-space-wasted-from-packaging/
*/

// hint : use prefix sum and binary search to query the answer in logn time 
// time complexity : NlogN

#define ll long long int


class Solution {
public:
    
    const ll inf = LONG_MAX;
    const int mod = 1e9 + 7;
     int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        ll n = packages.size();
        sort(begin(packages),end(packages));
        // sort(begin(boxes),end(boxes));
         
        for(auto &x : boxes)
            sort(begin(x),end(x));
        
        vector<ll> F(n+1,0);
        for(int i=1; i<=n; i++)
            F[i] = (F[i-1] + packages[i - 1]) %mod;
        
        ll ans = inf;
        for(auto x : boxes){
            
            ll cur_ans = 0,prev = 0;
            
            ll max_elem = *max_element(begin(x),end(x));
            ll last_pos = upper_bound(begin(packages),end(packages),max_elem) - begin(packages);
            if(last_pos < n) continue;
            
            for(int i=0; i<x.size(); i++){
                int pos = upper_bound(begin(packages),end(packages),x[i]) - begin(packages);
               // cout<<"x_val "<<x[i]<<" position "<<pos<<" "<<endl;
                ll len = pos - prev;
                ll val = ((len * x[i]) - (F[pos] - F[prev]));
                // if(val < mod) 
                //     val += mod;
               // cout<<len << " " << val<<endl;
                
                cur_ans = (cur_ans + val);
                prev = pos;
            }
           // cout<<endl<<endl;
            ans = min(ans, cur_ans);
        }
        cout<<ans<<endl;
        
    return ans == inf? -1 : int(ans % mod);
    }
};
