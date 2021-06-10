
         // https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/

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
const int mxn = 1e7 + 1;
int dp[11][1<<11];
int solve(vector<vector<int>> &v,int i,int mask){
    int n = v.size();
    if(i >= n) return 0;
    else if(dp[i][mask] != -1)
        return dp[i][mask];
    int val = inf;
    for(int j=0; j<n; j++){
        if(mask & (1 << j)) continue;
        val = min(val, solve(v,i+1,mask | (1 << j)));
    }
    return dp[i][mask] = val;
}
void test_case(){   
    int n; cin>>n;
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    }
    for(int i=0; i<11; i++){
        for(int j=0; j<(1<<11); j++){
            dp[i][j] = -1;
        }
    }
    cout<<solve(v,0,0);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;  //cin>>t;
    while(t--){
        test_case();
        cout<<'\n';
    }
    return 0;
}
