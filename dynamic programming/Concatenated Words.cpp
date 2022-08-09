    //    https://leetcode.com/problems/concatenated-words/
   
   // using dfs 
class Solution {
public:
    set<string> st;
    
    vector<int> v;
    bool solve(string &s,int i,int j){
        if(i>=s.size()) return true;
        for(int k=i; k<j; k++){
            string tmp = s.substr(i,k-i+1);
            if(tmp.size()<s.size() && st.find(tmp)!=st.end() && solve(s,k+1,j))
                return true;
        }
      return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto &w : words)
            st.insert(w);

        vector<string> res;
        for(int i=0; i<words.size(); i++){
            if(words[i].size()>=1 && solve(words[i],0,words[i].size())){
                res.push_back(words[i]);
            }
        }
    return res;
    }
};






 // more 
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
const int mxn = 1e5 + 1;

set<string> st;
bool solve(string &s,int i,int j){
    if(i>=j) return true;
    for(int k=i; k<j; k++){
        string tmp = s.substr(i,k-i+1);
        if(tmp.size()<s.size() && st.find(tmp)!=st.end() && solve(s,k+1,j))
            return true;
    }
    return false;
}
void test_case(){
    int n; cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        st.insert(v[i]);
    }

    vector<string> res;
    for(auto x : v){
        if(solve(x,0,x.size()))
            res.push_back(x);
    }

    cout<<res.size()<<endl;
    for(auto &x : res)
        cout<<x<<" ";
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


 // using trie data structure 
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
const int mxn = 1e5 + 1;
struct trie{
    struct trie* child[26];
    bool isEnd;
    trie(){
        memset(child,nullptr,sizeof(child));
        isEnd = false;
    }
}
struct trie *root;
void add(string s){
    struct *cur = root;
    for(int i=0; i<s.size(); i++){
        int idx = s[i] - 'a';
        if(cur->child[idx]==nullptr){
            cur->child[idx] = new trie();
        }
        cur= cur->child[idx];
    }
    cur->isEnd = true;
}
bool find(string &s,int idx,trie *head,int cnt){
    struct *cur = head;
    int n = s.size();
    for(int i=idx; i<n; i++){
        int cur_idx = s[i] - 'a';
        if(cur->child[cur_idx]==nullptr)
            return false;
        if(cur->isEnd){
            if(i==n-1) return cnt>=1;
            if(find(s,i+1,head,cnt+1))
              return true;
        }
        cur = cur->child[cur_idx];
    }
    return false;
}
void test_case(){
    int n; cin>>n;
    vector<string> v(n,0);

    root = new trie();
    for(int i=0; i<n; i++){
        cin>>v[i];
        add(v[i]);
    }
    vector<string> res;
    for(int i=0; i<n; i++){
        if(find(v[i],0,root,0))
            res.push_baack(v[i]);
    }
    cout<<res.size()<<endl;
    for(auto &x : res){
        cout<<x<<" ";
    }
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
