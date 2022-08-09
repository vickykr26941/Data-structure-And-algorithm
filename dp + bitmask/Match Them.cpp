/*
auther : vicky kumar
date : 03:07:2021
source : https://hack.codingblocks.com/app/practice/1/1341/problem
*/


    // solution usign sliding window
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



   // solution goes here 
const int inf = 1e10 + 20;
const int mod = 1e9 + 7;
const int mxn = 1e5 + 10;
void test_case(){

    string s; cin>>s;
    int n = s.size();
    int k; cin>>k;

    map<char,int > m;
    char ch;
    rep(i,0,k){
        cin>>ch; 
        m[ch]++;
    }

    int count = k, ans = 0, start = 0, end = 0;
    while(end < n){
        if(m[s[end]] > 0){
            count --;
        }
        m[s[end]]--;
        end++;
        while(count == 0){
            ans += (n - end + 1);
            m[s[start]]++;
            if(m[s[start]] > 0)
                count ++;
            start++;
        }
    }

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







 // using sliding window is little bit harder , we can solve this using binary search with precompution easily 
 // but time complextiy will be NlogN in this case 
 
 
 #include<bits/stdc++.h> 
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a; i>=b; i--)
#define pb(i) push_back(i)
#define all(b) b.begin(),b.end()
using namespace std;
void test_case(){
    string s; cin>>s;
    int n = s.size();
    int k; cin>>k;

    vector<int> hass(10,0);
    for(int i=0; i<k; i++){
        int y; cin>>y;
        hass[y]++;
    }
    vector<vector<int>> dp(n,vector<int>(10,0));
    for(int i=0; i<n; i++){
        dp[i][s[i] - '0']++;
        if(i > 0){
            for(int j=0; j<10; j++){
                dp[i][j] += dp[i-1][j];
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int l = i, r = n - 1;
        int id = -1;

        while(l <= r){
            int mid = (l + r)/2;
            int check = 1;
            for(int j=0; j<10; j++){
                if(i>=1){
                 if(hass[j] > dp[mid][j] - dp[i-1][j])
                    check = 0;
                }
                else{
                    if(hass[j] > dp[mid][j])
                        check = 0;
                }
            }

            if(check){
                id = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        if(id != -1){
            ans += (n - id);
        }
    }

    cout<<ans;
    
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
 
