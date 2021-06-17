      // porblem source : coding blocks

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
const int mxn = 1e6 + 5;
const int max_mask_val = (1<<20) - 1;
int FINAL_MASK = 0;
int dp[max_mask_val][21];
int solve(vector<vector<int>>&cost,int pos,int mask){
    int n = cost[0].size();
    if(mask==FINAL_MASK)
        return cost[pos][0];
    else if(dp[mask][pos] != -1)
        return dp[mask][pos];
    int ans = inf;
    for(int j=0; j<n; j++){
        if(!(mask & (1 << j)))
            ans = min(ans,cost[pos][j] + solve(cost,j,mask|(1<<j)));
    }
    return dp[mask][pos] = ans;
}
void test_case(){
    int n; cin>>n;
    vector<vector<int>> mat(n,vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }
    FINAL_MASK = (1 << n) - 1;
    for(int i=0; i<max_mask_val; i++){
        for(int j=0; j<21; j++){
            dp[i][j] = -1;
        }
    }
    cout<<solve(mat,0,0);
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
