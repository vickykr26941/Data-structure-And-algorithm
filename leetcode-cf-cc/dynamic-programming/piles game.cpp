   // minimax algorithm 
   // https://leetcode.com/problems/predict-the-winner/

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
int solve(vector<int>&arr,int i,int j,int turn){
    if(i > j) return 0;
    else if(dp[i][j][turn] != -1)
        return dp[i][j][turn];
    if(turn == 1){
        int x = arr[i] + solve(arr,i+1,j,turn^1);
        int y = arr[j] + solve(arr,i,j-1,turn^1);
        return dp[i][j][turn] = max(x,y);
    }
    else{
        int x = -arr[i] + solve(arr,i+1,j,turn^1);
        int y = -arr[j] + solve(arr,i,j-1,turn^1);
        return dp[i][j][turn] = min(x,y);
    }
}


// another easy implementation 
vector<vector<vector<int>>> v;
int solve2(vector<int>&a,int i,int j,int turn){
    if(i > j) return 0;
    else if(v[i][j][turn + 1] != -1)
        return dp[i][j][turn + 1];
    int x = turn * a[i] + solve(a,i+1,j,-turn);
    int y = turn * a[i] + solve(a,i,j-1,-turn);
    return v[i][j][turn + 1] = turn * max(turn * x, turn * y);
}
void test_case(){
    int n; cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    v.assign(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
    dp.assign(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));

    // implementation 1 
    // cout<<solve(arr,0,n-1,1);

    // second method 
    cout<<solve2(arr,0,n-1,1);
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
