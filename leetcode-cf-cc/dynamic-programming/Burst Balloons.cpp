 // https://leetcode.com/problems/burst-balloons/
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

vector<vector<int>> dp1;
vector<vector<int>> dp2;
// implementation 1
int solve2(vector<int>&a,int i,int j){
    if(i > j) return 0;
    if(dp1[i][j] != -1) return dp1[i][j];
    int ans = 0;
    for(int k=i; k<=j; k++){
        int val = a[i-1] * a[k] * a[j+1];
        int x = solve2(a,i,k-1);
        int y = solve2(a,k+1,j);
        ans = max(ans, x + y + val);
    }
    return dp1[i][j] = ans;
}
 // implementation 2
int solve(vector<int> a,int i,int j){
    if(i > j) return 0;
    if(dp2[i][j] != -1) return dp2[i][j];
    int ans = 0;
    for(int k=i; k<j; k++){
        int x = solve(a,i,k);
        int y = solve(a,k+1,j);
        ans = max(ans,x + y + a[i-1] * a[k] * a[j]);
    }
    return dp2[i][j] = ans;
}
void test_case(){
    int n; cin>>n;
    vector<int> a(n+2,0);
    for(int i=1; i<=n; i++)
        cin>>a[i];
    a[0] = a[n+1] = 1;
    
    // recursion + memoization 
    // dp1.clear();
    // cout<<solve(a,1,n+1);

    // dp2.clear();
    // cout<<solve2(a,1,n);

    // top down approach 
    n = n + 2;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int L=2; L<=n; L++){
        for(int i=1; i<n-L + 1; i++){
            int j = i + L - 1;
            for(int k=i; k<j; k++){
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j]);
            }
        }
    }
    cout<<dp[1][n-1];
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
