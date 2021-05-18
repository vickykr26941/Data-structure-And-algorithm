// find the number of path from source to destination in DAG
// dynamic  + topological sort

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
    vii g(n + 1);
    vi in(n+1,0);

    int x,y; 
    rep(i,0,m){
        x,y; cin>>x>>y;
        g[x].pb(y);
        in[y]++;
    }
    queue<int> q;

    vector<int> dp(n+1,1);
    rep(i,1,n+1){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v==n){
            break;
        }
        for(auto u : g[v]){
            in[u]--;
            if(in[u]==0){
                dp[u]+=dp[v];
                q.push(u);
            }
        }
    }

    rep(i,1,n+1){
        cout<<dp[i] - 1<<" ";
    }
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
