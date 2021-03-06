   // https://leetcode.com/problems/split-array-largest-sum/
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
vector<int> v;
vector<vector<int>> dp;
int solve(vector<int>&a,int i,int k){
    if(i>=a.size())
        return k==0?0:inf;
    else if(k<=0) return inf;
    else if(dp[i][k] != -1)
        return dp[i][k];

    int ans = inf;
    for(int j=i; j<a.size() - k + 1; j++){
        ans = min(ans, max(v[j+1]-v[i],solve(a,j+1,k-1)));
    }
    return dp[i][k] = ans;
}
void test_case(){
    int n,k; cin>>n>>k;
    vector<int> a(n,0);
    int s = 0, mn = inf;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        s += a[i];
        mn = min(mn,a[i]);
    }
    v.clear();
    dp.clear();

    v.assign(n+1,0);
    for(int i=1; i<=n; i++)
        v[i] = v[i-1] + a[i-1];
        
        
        // recursion + memoization (buttom up approach)
    // dp.assign(n+1,vector<int>(k+1,-1));
    // cout<<solve(a,0,k);


     // top down approach (iterative dp)
    // dp.assign(k,vector<int>(n,0));

    // for(int p=1; p<k; p++){
    //     for(int i=p; i<n; i++){
    //         int val = inf;
    //         for(int j=0; j<i; j++){
    //             val = min(val, max(dp[p-1][k],v[i+1] - v[j]));
    //         }
    //     dp[p][i] = val;
    //     }
    // }

    // cout<<dp[k-1][n-1];


    // using binary search time complexity recuces to Nlog(sum(a))

    // 4 5 6 7 8 9 10 
    // k = 3 
    /// binary search and check for the minimum possible answer


    int l = mn, r = s;
    int ans = 0;
    while(l <= r){
        int mid = (l + r)/2;
        int val = 0,c = 1;
        for(int i=0; i<n; i++){
            val += a[i];
            if(val > mid){
                val = a[i];
                c++;
            }
        }
        if(c<=k){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout<<ans;
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
