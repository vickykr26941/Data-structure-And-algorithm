  // matrix chain multiplication 
  // https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

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

vector<vector<int>> dp;
int solve(vector<int>&a,int i,int j){
    if(i==j) return 0;
    else if(dp[i][j] != -1) 
        return dp[i][j];

    int ans = inf;
    for(int k=i; k<j; k++){
        int left = solve(a,i,k);
        int right = solve(a,k+1,j);
        ans = min(ans, left + right + a[i-1] * a[k] * a[j]);
    }
    return dp[i][j] = ans;
}
void test_case(){
    int n; cin>>n;
    vector<int> a(n,0);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    dp.clear();

    // recursion + memoization 
    // dp.assign(n+1,vector<int>(n+1,-1));
    // cout<<solve(a,1,n-1);

    // top down approach 
    dp.assign(n,vector<int>(n,inf));
    for(int i=1; i<n; i++)
        dp[i][i] = 0;

    for(int L=2; L<n; L++){
        for(int i=1; i<n-L+1; i++){
            int j = L + i - 1;
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j]);
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
