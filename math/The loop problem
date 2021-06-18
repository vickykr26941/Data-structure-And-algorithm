   // https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/loop-problem-db615209/


  
// problem can be solved using bitwise xor properties
// total number of set bits at ith position in range [a,b] , let say x 
// total number of unset bits at ith position in range [a b] , let say y 
// total number of bits  in range [a,b] = b - a + 1

// total number of set bits at ith position in range [c ,d], let say p
// total number of unset bits at ith position in range [c d] , let say q
// total number of bits  in range [c,d] = d - c + 1

// contiribution of ith bit to the result is  (a * q + b * p) * pow(2,i);
// now we need to find the total number of set bits at ith position in range[a,b]
// we can find total number of set bits at ith position till b then subtract till a - 1
// which means x = get_bit(b) - get(a - 1)

// now how do we find ith bit set till b or n 
// observe the patterns of binary representation and get the formula
// which is :  d = (b - (1<<i) + 1)/(1<<(i+1)) * (1<<i))
//           or d = int((b - pow(2,i))/(2 * pow(2,i))) * pow(2,i) + min(pow(2,i),d % (2 * pow(2,i)))
//           



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
const int mxn = 1e5 + 5;
int pow(int a,int x){
    int ans = 1;
    while(x>0){
        if(x&1){
            ans = (ans * a) %mod;
        }
        a = (a * a) %mod;
        x >>= 1;
    }
    return ans;
}
int get_bits(int x,int i){
    int l = (1 << i);
    if(l > x) return 0;
    int d = x - l + 1;
    int bit_cnt = d/(2 * l) * l + min(l,d % (2 * l));
    return bit_cnt;
}
void test_case(){
    int a,b,c,d; cin>>a>>b>>c>>d;
    int ans = 0;
    for(int i=0; i<31; i++){
        int x = get_bits(b,i) - get_bits(a - 1, i);
        int y = b - a + 1 - x;
        int p = get_bits(d,i) - get_bits(c - 1, i);
        int q = d - c + 1 - p;
        int c = (x * q + p * y) % mod;
        c = c * pow(2,i);
        ans = (ans + c) %mod;
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
