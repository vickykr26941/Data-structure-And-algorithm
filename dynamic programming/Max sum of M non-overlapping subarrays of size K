
      // https://www.geeksforgeeks.org/max-sum-of-m-non-overlapping-subarrays-of-size-k/
      
      // compute v[i] -> store sum of first k elements
      // now if we include this subarray then -> v[i] + f(i+k,m -1) , i + k because we can't take next k elements to avoid overlapping of subarray
      // if we exclude this subarray then ->            f(i+1,m)   , excluding this subarray to go for next other subarray is just i + 1
      // base case : when all array is traversed and m subarray have taken(m==0) then return 0, otherwise inf
      

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

vector<vector<int>> dp;
int solve(vector<int>&v,int i,int m,int k){
    if(i==v.size() && m==0) return 0;
    else if(i>=v.size() or m<0) return inf;
    else if(dp[i][m] != -1) return dp[i][m];
    int x = v[i] + solve(v,i+k,m-1,k);
    int y = solve(v,i+1,m,k);
    return dp[i][m] = max(x,y);
}
void test_case(){
	int n,m,k; cin>>n>>m>>k;
    vector<int> a(n,0);
    for(int i=0; i<n; i++)
        cin>>a[i];

    vector<int> v(n-k + 1, 0);
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
        if(i>=k){
            sum -= a[i-k];
        }
        if(i>=k-1)
            v[i-k+1] = sum;
    }

    int len = n - k + 1;
    dp.assign(len + 1, vector<int>(m+1,-1));
    cout<<solve(v,0,m,k);
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
