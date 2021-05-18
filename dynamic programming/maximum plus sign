  // find maximum Plus sign in grid 
  // https://leetcode.com/problems/largest-plus-sign/

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
    int n,m; cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<int>> top(n,vector<int>(m,0));
    vector<vector<int>> left(n,vector<int>(m,0));
    vector<vector<int>> right(n,vector<int>(m,0));
    vector<vector<int>> down(n,vector<int>(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && mat[i][j]) top[i][j] = mat[i][j];
            else if(mat[i][j]==1){
                top[i][j] = top[i-1][j] + 1;
            }
        }
    }
        
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(j==0 && mat[i][j]) left[i][j] = 1;
            else if(mat[i][j]==1){
                left[i][j] = left[i][j - 1] + 1;
            }
        }
    }
        
    for(int i=0; i<n; i++){
        for(int j=m-1; j>=0; j--){
            if(j==n-1 && mat[i][j]) right[i][j] = 1;
            else if(mat[i][j]){
                right[i][j] = right[i][j + 1] + 1;
            }
        }
    }
        
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<m; j++){
            if(i==n-1 && mat[i][j]) down[i][j] = 1;
            else if(mat[i][j]){
                down[i][j] = down[i+1][j] + 1;
            }
        }
    }
        
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int val = min_val(top[i][j], left[i][j],right[i][j],down[i][j]);
            ans = max(ans, val);
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
