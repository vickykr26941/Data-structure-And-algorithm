    // Longest increasing subseqeucen of two array with k changes are allowed 
    // problem source : coding block DP course practice 


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
vector<vector<vector<int>>> dp;
int solve(vector<int>&a,vector<int>&b,int i,int j,int k){
    int n = a.size(), m = b.size();
    if(i >= n or j >= m) return 0;
    else if(dp[i][j][k] != -1)
        return dp[i][j][k];
    if(a[i] == b[j]){
        return dp[i][j][k] = 1 + solve(a,b,i+1,j+1,k);
    }
    else{
        int x = max(solve(a,b,i+1,j,k), solve(a,b,i,j+1,k));
        int y = 0;
        if(k > 0){
            y = 1 + solve(a,b,i+1,j+1,k-1);
        }
        return dp[i][j][k] = max(x,y);
    }
}
void test_case(){
   int n,m,k; cin>>n>>m>>k;
   vector<int> a(n,0), b(m,0);
   for(int i=0; i<n; i++)
    cin>>a[i];
   
   for(int i=0; i<m; i++)
    cin>>b[i];
   
   dp.assign(n + 1, vector<vector<int>>(m+1,vector<int>(k + 1,-1)));
   cout<<solve(a,b,0,0,k);
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
