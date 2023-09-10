   //https://codeforces.com/problemset/gymProblem/100886/G
   
   
  // this is second varient of DigitDP problems 
  // this can be solved by making sure the range is not going less the lowerlimit and greater then upperlimt
  // it's better to write recrsive solution and memoize for easiness

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
#define mod MOD
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
template< class T1,class T2> using pii = pair<T1,T2>;
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


 
                  // solution 
const int inf = 1e10 + 20;
const int mxn = 1e5 + 5;
string a,b;
vector<vector<vector<vector<pair<int,string>>>>> dp;
pair<int,string> solve(int pos,int ta,int tb,int st){
    if(pos == a.size())
        return {1,""};
    else if(dp[pos][ta][tb][st].fi != -1)
        return dp[pos][ta][tb][st];

    int ans = -1;
    string res;
    int l = ta ? (a[pos] - '0') : 0;
    int r = tb ? (b[pos] - '0') : 9;
    int v = 0;
    for(int i=l; i<=r; i++){
        v = (st==0 && i==0) ? 1 : i;
        pair<int,string> dp_val = solve(pos + 1,ta&(l==i), tb&(r==i),st|(i>0));
        if((v * dp_val.fi) > ans){
            ans = v * dp_val.fi;
            if(st==0 && i==0)
                res = dp_val.sec;
            else{
                // reverse(all(dp_val.sec));
                dp_val.sec.pb('0' + i);
                // reverse(all(dp_val.sec));
                res = dp_val.sec;
            }
        }
    }
    return dp[pos][ta][tb][st] = {ans,res};
}
void test_case(){
    cin>>a>>b;
    reverse(all(a));
    while(a.size() < b.size())
        a.pb('0');
    reverse(all(a));

    dp.assign(a.size() + 1, vector<vector<vector<pair<int,string>>>>(2,vector<vector<pair<int,string>>>(2,vector<pair<int,string>>(2,{-1,""}))));
    string s = solve(0,1,1,0).sec;
    reverse(all(s));
    cout<<s;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1; // cin>>t;
    while(t--){
        test_case();
        cout<<'\n';
    }
    return 0;
}
