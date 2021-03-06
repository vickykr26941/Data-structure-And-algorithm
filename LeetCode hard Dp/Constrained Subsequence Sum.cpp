     //https://leetcode.com/problems/constrained-subsequence-sum/


#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int n, q, arr[MAX_N], st[4 * MAX_N];
 
void build(int node, int start, int end) {
    if (start == end) {
        st[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    st[node] = max(st[2 * node], st[2 * node + 1]);
}
 
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        st[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx, val);
    else update(2 * node + 1, mid + 1, end, idx, val);
    st[node] = max(st[2 * node], st[2 * node + 1]);
}
void update(int pos,int val,int n){
    update(1,1,n,pos,val);
}
int query(int node, int start, int end, int l, int r) {
    if (start > r || end < l) return -INF;
    if (l <= start && end <= r) return st[node];
    int mid = (start + end) / 2;
    return max(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r)); 
}
int query(int l,int r,int n){
    return query(1,1,n,l,r);
}
const int inf = 1e9 + 7;
class Solution {
public:
   
    int constrainedSubsetSum(vector<int>& a, int k) {
        int n = a.size();
        for(int i=0; i<MAX_N; i++){
          arr[i] = 0;
        }
        build(1,1,n+1);
        vector<int> dp(n,0);
        
        n = n;
        dp[0] = a[0];
        update(1,a[0],n+1);
        int ans = dp[0];
        for(int i=1; i<n; i++){
            int val = 0;
            if(i-k<=0){
                val = max(val,query(1,i,n+1));
            }
            else{
                val = max(val,query(i-k+1,i,n+1));
            }
            dp[i] = a[i] + val;
            update(i+1,dp[i],n+1);
            ans = max(ans, dp[i]);
        }
    return ans;
    }
};



  // using sliding window
class Solution {
public:
   
    int constrainedSubsetSum(vector<int>& a, int k) {
        int n = a.size();
        vector<int> dp(n,0);
        dp[0] = a[0];
        
        map<int,int> mp;
        mp[a[0]]++;
        int ans = dp[0];
        for(int i=1; i<n; i++){
            auto it = mp.rbegin();
            dp[i] = a[i] + max(0,it->first);
            if(i-k>=0){
               mp[dp[i-k]]--;
               if(mp[dp[i-k]]==0){
                   mp.erase(dp[i-k]);
               }
            }
            mp[dp[i]]++;
            ans = max(dp[i],ans);
        }     
    return ans;
    }
};


// we only need to find the max element in first k precalculated values
// we can query using segment tree with point update or can maintain a map or multiset to find the
// maximum of before k elements of dp 


