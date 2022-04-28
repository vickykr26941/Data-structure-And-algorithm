/*
   vicky kumar
   date : 26/07/2021
   source : https://www.codechef.com/problems/ODDBITS
*/


// explanation : the problem can be solve using digit dp  and binary search 
// answer is monotonically increasing binary search on answer and then for a particular answer find the values using digit dp





#include<bits/stdc++.h> 
#define int long long
#define readi(x) scanf("%d",&x)
#define reads(x) scanf("%s",x)
#define readl(x) scanf("%I64d",&x)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a; i>=b; i--)
#define all(v) begin(v),end(v) 
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define pb push_back
#define fi first
#define sec second
#define bg begin 
#define ed end 
#define lb lower_bound
#define ub upper_bound
  // constants
#define MAXN 1000000000010000005
#define MINN -1000000000000000000
#define MOD 1000000009
#define INTMAX 1000001000
#define PI 3.14
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ld long double

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
template< class T > using vt = vector<T>;
template< class T > using vvt = vector<vector<T>>;
// template< class T1,class T2> using pii = pair<T1,T2>;
template< class T > using max_q = priority_queue<T,vector<T>,greater<T>>;
template< class T > using min_q = priority_queue<T>;
template< class T1,class T2 > unordered_map<T1,T2> ump;
template< class T1, class T2 > void min_(T1 &a,T2 &b){a = a > b ? b : a;}
template< class T1, class T2 > void max_(T1 &a,T2 &b){a = b > a ? b : a;}
template< class T> void pow_(T a, T b){T ans = 1; while(b){ans *= a; b>>=1;} a*=a; return ans;}

template<typename A > ostream& operator <<(ostream &cout,vector<A> const &v);
template<typename A , typename B>ostream& operator <<(ostream &cout,pair<A,B> const &p){ return cout << "(" << p.fi << ", " << p.sec << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
    cin >> p.first;
    return cin >> p.second;
}
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
string tostring(int number) {stringstream ss; ss << number; return ss.str();}
// #define TRACE
// #ifdef TRACE 
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }

// using namespace std;

// template<class T> using oset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;

    // useful functions of oset 
// st.find_by_order(k); // returns element at position k(0 based indexing)
// st.find_of_key(k); // number of element <k
// st.order_of_key(k); // return order of k 
// less_equal<T> : as multiset
// less<T>      :  only set 
const int inf = LLONG_MAX;
const int mod = 1e9 + 7;
const int mxn = 1e5 + 10;
int dp[30][2][2][2][30];
int solve(string &s,int pos,int tight,int st,int odd,int odd_cnt){
    if(pos >= s.size()) 
        return odd_cnt;
    else if(dp[pos][tight][st][odd][odd_cnt] != -1)
        return dp[pos][tight][st][odd][odd_cnt];

    int ans = 0;
    if(st == 0){
        ans += solve(s,pos+1,0,st,odd,odd_cnt);
        ans += solve(s,pos+1,tight&(s[pos]=='1'),1,!odd,1);
    }
    else{
        int en = tight?(s[pos] - '0') : 1;
        for(int i=0; i<=en; i++){
            ans += solve(s,pos+1,tight&(en==i),st,!odd,odd_cnt +(i==1 && odd));
        }
    }
    return dp[pos][tight][st][odd][odd_cnt] = ans;
}
int check(int mid,int n){
    string s = bitset<32>(mid).to_string();
    for(int i=0; i<32; i++){
        if(s[i] == '1'){
            s = s.substr(i);
            break;
        }
    }
    memset(dp,-1,sizeof(dp));
    int ans = solve(s,0,1,0,1,0);
    return ans >= n;
}
void test_case(){
    int n; cin>>n;
    int l = 1, r = n;
    int ans = 0;
    // memset(dp,-1,sizeof(dp));
    while(l <= r){
        int mid = (l + r)/2;
        if(check(mid,n)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
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


// dp + range minimum - > insted segment tree maintain monotonic deque

