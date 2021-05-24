   // https://leetcode.com/problems/partition-array-for-maximum-sum/

#include<bits/stdc++.h> 
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a; i>=b; i--)
#define pb(i) push_back(i)
#define all(b) b.begin(),b.end()

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// template<class T> using oset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// st.find_by_order(k); // returns element at position k(0 based indexing)
// st.find_of_key(k); // number of element <k
// st.order_of_key(k); // return order of k 
// less_equal<T> : as multiset
// less<T>      :  only set

const int mod = 1e9 + 7;
const int inf = 1e10 + 20;
const int mxn = 1e5 + 1;
vector<int> dp;
int solve(vector<int>&a,int i,int k){
    if(i>=a.size()) return 0;
    else if(dp[i] != -1) 
        return dp[i];

    int ans = 0, cur_max = 0;
    for(int j=i; j<min(i+k,(int)a.size()); j++){
        cur_max = max(cur_max, a[j]);
        ans = max(ans, cur_max * (j - i + 1) + solve(a,j+1,k));
    }
    return dp[i] = ans;
}
void test_case(){
    int n,k; cin>>n>>k;
    vector<int> a(n,0);
    for(int i=0; i<n; i++)
        cin>>a[i];

    // dp.assign(n+1,-1);
    // cout<<solve(a,0,k);

    // top down 
    vector<int> dp(n+1,0);
    for(int i=1; i<=n; i++){
        int cur_max = 0, best = 0;
        for(int j=1; j<=k && i - j>=0; j++){
            cur_max = max(cur_max, a[i-j]);
            ans = max(ans, cur_max * k + dp[i-j]);
        }
        dp[i] = best;
    }

    cout<<dp[n];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;  cin>>t;
    while(t--){
        test_case();
        cout<<'\n';
    }
    return 0;
} 
