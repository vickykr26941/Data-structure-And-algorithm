// https://leetcode.com/problems/minimum-incompatibility/


class Solution {
public:
    using pii = pair<int,int>;
    vector<pii> v;
    
    int FINAL_MASK = 0,K = 0;
    const int inf = INT_MAX;
    int dp[17][(1 << 16) + 1];
    int solve(int idx,int mask){
        if(idx == K) return 0;
        else if(dp[idx][mask] != -1) 
            return dp[idx][mask];
        
        int ans = 1e9 + 7;
        for(int i = 0; i<v.size(); i++){
            if((mask & v[i].first) == 0){
                ans = min(ans, v[i].second + solve(idx + 1, mask|v[i].first));
            }
        }
        return dp[idx][mask] = ans;
    }
    int minimumIncompatibility(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> frq(n + 1, 0);
        for(int i = 0; i < n; i++) frq[arr[i]]++;
        for(int i = 1; i<=n; i++){
            if(frq[i] > k) return -1;
        }
        int size = n/k;
        K = k;
        for(int mask = 0; mask < (1 << n); mask ++){
            if(__builtin_popcount(mask) != size) continue;
            
            int mx = 0, mn = n,ok = 1;
            int cur_mask = 0;
            for(int i = 0; i<arr.size(); i++){
                if(mask & (1 << i)){
                    if(cur_mask & (1 << arr[i])){
                        ok = 0;
                        break;
                    }
                    cur_mask |= (1 << arr[i]);
                    mx = max(mx,arr[i]);
                    mn = min(mn,arr[i]);
                }
            }
            if(ok){
                v.push_back({mask,mx - mn}); 
            }
        }
        
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};
