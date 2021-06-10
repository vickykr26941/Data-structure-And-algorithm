        // https://www.geeksforgeeks.org/bitmasking-and-dynamic-programming-set-1-count-ways-to-assign-unique-cap-to-every-person/


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
vector<int> v[101];
int complete;
int dp[101][1<<11];
int solve(int i,int mask){
    if(i>100) return 0;
    if(mask == complete) return 1;
    else if(dp[i][mask] != -1)
        return dp[i][mask];
    int ways = solve(i+1,mask);

    int len = v[i].size();
    for(int j=0; j<len; j++){
        if(mask & (1 << v[i][j])) continue;
        ways += solve(i+1,mask | (1 << v[i][j]));
        ways %= mod;
    }
    return dp[i][mask] = ways;
}
void test_case(){
    int n; cin>>n;
    string w,str;
    getline(cin,str);
    int x;
    for(int i=0; i<n; i++){
        getline(cin,str);
        stringstream in(str);

        while(in >> w){
            stringstream s; 
            s << w;
            s >> x;
            v[x].push_back(i);
        }
    }
    complete = (1 << n) - 1;
    for(int i=0; i<101; i++){
        for(int j=0; j<(1<<n); j++){
            dp[i][j] = -1;
        }
    }
    cout<<solve(1,0);
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
   
