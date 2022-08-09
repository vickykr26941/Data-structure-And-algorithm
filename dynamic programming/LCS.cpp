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


vector<vector<int>> dp;
int solve(string &s,string &t,int n,int m){
    if(n==0 or m==0)
        return 0;
    else if(dp[n][m] != -1)
        return dp[n][m];
    if(s[n-1]==t[m-1])
        return dp[n][m] = 1 + solve(s,t,n-1,m-1);
    else{
        return dp[n][m] = max(solve(s,t,n-1,m), solve(s,t,n,m-1));
    }
}
void test_case(){
    int n,m; cin>>n>>m;
    string s,t; cin>>s>>t;

     // recursion + memoization 
     // dp.clear();
     // dp.assign(n+1,vector<int>(m+1,-1));
    // cout<<solve(s,t,n,m); 
    // top down 
    vector<vector<int>> dp2(n+1,vector<int>(m+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == s[j-1]){
                dp2[i][j] = dp2[i-1][j-1] + 1;
            }
            else{
                dp2[i][j]= max(dp2[i-1][j], dp2[i][j-1]);
            }
        }
    }

    cout<<dp2[n][m];
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
