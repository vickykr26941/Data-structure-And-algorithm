this problem is not accessible it's premium from coding blocks
problem disc : 
given a number N (10^18) find the count of numbers after rearranging the digits of N those are divisible by M(100)
leading zeros will be discarded 
constraints : 
 N - > 10^18
 M = 100
 
// solution : 
// we can optimized brute force solution with memoization and avoiding repeting count
// dp[mask][m] - > count of possible answers with Mask "mask" and reminder 'm'
// we can start taking all digits that are present in N , reptation can be avoided if we have already taken a digit at particular level then 
// we will not take that digit to the same level again, this problem is similler to TSP problem 


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
int FINAL_MASK, MOD;
string s;
int dp[1<<18 + 1][101];
int solve(int mask,int m){
    if(mask == FINAL_MASK)
        return m==0;
    int ans = 0;
    bool ch[10];
    memset(ch,0,sizeof(ch));
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0' && mask==0)
            continue;

        if(!(mask&(1 << i)) and !(ch[s[i] - '0'])){
            ans += solve(mask|(1<<i), (m * 10 + (s[i] - '0')) % MOD);
            ch[s[i] - '0'] = 1;
        }
    }
    return ans;
}
void test_case(){
    cin>>s>>MOD;

    FINAL_MASK = (1<<s.size()) - 1;
    cout<<solve(0,0);
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
