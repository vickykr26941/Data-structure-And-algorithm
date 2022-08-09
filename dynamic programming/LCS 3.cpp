   // longest common subsequence of 3 strings
   // time complexity O(n^3) 
 
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
const int mxn = 3 * 1e5 + 1;


vector<vector<vector<int>>> dp;
int solve(string &a,string &b,string &c,int n,int m,int k){
    if(n==0 or m==0 or k==0)
        return 0;
    else if(dp[n][m][k] != -1)
        return dp[n][m][k];
    if(a[n-1]==b[m-1] && b[m-1]==c[k-1])
        return dp[n][m][k] = solve(a,b,c,n-1,m-1,k-1);
    else{
        return dp[n][m][k] = max(max(solve(a,b,c,n-1,m,k),solve(a,b,c,n,m-1,k)),solve(a,b,c,n,m,k-1));
    }
}
void test_case(){
    string a,b,c; 
    cin>>a>>b>>c;
    int n = a.size(), m = b.size(), K = c.size();

    // recursion + memoization 
    // dp.clear();
    // dp.assign(n+1,vector<vector<int>>(m+1,vector<int>(K+1,-1)));
    // cout<<solve(a,b,c,n,m,k);
    
    
     // iteraive // top down approach 
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>(m+1,vector<int>(K+1,0)));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=1; k<=K; k++){
                if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else{
                    dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                }
            }
        }
    }

    cout<<dp[n][m][K];
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
