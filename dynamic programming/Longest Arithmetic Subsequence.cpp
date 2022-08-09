
   // https://leetcode.com/problems/longest-arithmetic-subsequence/
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
void test_case(){
    int n; cin>>n;
    vector<int> a(n,0);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    vector<vector<int>> dp(n,vector<int>(2005,1));
    int res = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int d = a[i] - a[j] + 1000;
            dp[i][d] = max(dp[i][d], dp[j][d] + 1);
            res = max(dp[i][d], res);
        }
    }

    cout<<res;
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
