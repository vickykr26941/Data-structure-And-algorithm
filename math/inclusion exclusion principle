     // https://www.codechef.com/IARCSJUD/problems/LEAFEAT

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
int N,K;
int *v, ans = 0;
int get_val(int k){
    return (N - 1)/k + 1;
}
int lcm(int a,int b){
    return a * b / __gcd(a,b);
}
void solve(int i,int len,int cur_lcm){
    if(i>=K) return ;
    if(len % 2== 1)
        ans += get_val(lcm(cur_lcm,v[i]));
    else{
        ans -= get_val(lcm(cur_lcm,v[i]));
    }
    solve(i+1,len,cur_lcm);
    if(get_val(lcm(cur_lcm,v[i])) <= N)
        solve(i+1,len+1,lcm(cur_lcm,v[i]));
}
void test_case(){
    cin>>N>>K;
    v = new int[K];
    for(int i=0; i<K; i++){
        cin>>v[i];
    }
    ans = N;
    solve(0,0,1);
    cout<<ans;
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
