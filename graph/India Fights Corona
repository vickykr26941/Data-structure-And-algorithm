/*
  auther : vicky kumar
  date : 18/08/2021
  problem : https://www.codechef.com/problems/CORONA
  
*/

// explanation : 
take it this way. There is a ‘super’ hospital at node 00. All hospitals don’t test the samples by themselves; instead they send the samples to this ‘super’ hospital (which tests it for free).
The distance from hospital ii to node 0 is ci 
(so the charges you pay for the testing is actually the charges you are paying the hospital to take the samples to hospital 0).
Now, instead of giving the hospital your sample and paying them to send it to hospital 00, why don’t you go yourself to hospital 0 and get your testing done for free? The total cost incurred is the same, in both cases.






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

using pii = pair<int,int>;
void test_case(){
    int n,m,k; cin>>n>>m>>k;
    vector<vector<pii>> g(n+2);


    for(int i=0; i<k; i++){
        int x,c; cin>>x>>c;
        g[0].push_back({x,c});
        g[x].push_back({0,c});
    }
    for(int i=0; i<m; i++){
        int a,b,d; cin>>a>>b>>d;
        g[a].push_back({b,d});
        g[b].push_back({a,d});
    }

    vector<int> dist(n+2,inf);
    auto dijkestra = [&](){
        priority_queue<pii,vector<pii>,greater<pii>> q;
        dist[0] = 0;
        q.push({dist[0],0});

        while(q.size() > 0){
            auto v = q.top(); q.pop();
            int from = v.second;
            if(v.first > dist[from]) continue;

            for(auto &u : g[from]){
                int to = u.first, len = u.second;
                if(dist[from] + len < dist[to]){
                    dist[to] = dist[from] + len;
                    q.push({dist[to],to});
                }
            }
        }
    };

    dijkestra();
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
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
