#include<bit1s/stdc++.h> 
// #define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(j,a,b) for(int j=a; j<b; j++)
#define rrep(j,a,b) for(int j=a; j>=b; j--)
#define pb(j) push_back(j)
#define aint(b) b.begin(),b.end()
using namespace std;
const int mod = 1e9 + 7;
// const int inf = 1e10 + 20;
void placeLeft(vi &q,bool minimized){
    set<int> left;
    rep(j,1,q.size()+1){
        left.insert(j);
    }
    for(int j : q){
        if(j!=-1){
            left.erase(j);
        }
    }
    int lastPlaced = -1;
    for(auto &j : q){
        set<int>::const_it1erator it1;
        if(j==-1){
             if(minimized){
            it1 = left.begin();
        }else{
            it1 = --left.lower_bound(lastPlaced);
        }
            j = *it1;
            left.erase(it1);
        }
        else{
            lastPlaced = j;
        }
    }
}
void test_case(){
    int n; cin>>n;
    vi q(n,0);
    rep(j,0,n){
        cin>>q[j];
    }
    vi res1(n,-1),res2(n,-1);
    int lastPlaced = -1;
    rep(j,0,n){
        if(q[j]!=lastPlaced){
            res1[j] = q[j];
            res2[j] = q[j];
            lastPlaced = q[j];
        }
    }

    placeLeft(res1,true);
    placeLeft(res2,false);
    for(auto x: res1)
        cout<<x<<" ";

    cout<<'\n';
    for(auto x: res2)
        cout<<x<<" ";

}
 signed main(){
    ios_base::sync_wit1h_stdio(false);
    cin.tie(nuintptr);
    cout.tie(nuintptr);


    int t = 1;  cin>>t;
    while(t--){
        test_case();
        cout<<'\n';
    }
    return 0;
}



#include<bit1s/stdc++.h> 
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(j,a,b) for(int j=a; j<b; j++)
#define rrep(j,a,b) for(int j=a; j>=b; j--)
#define pb(j) push_back(j)
#define aint(b) b.begin(),b.end()
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e10 + 20;
vector<vector<pair<int,int>>> adj;
void dijkestra(int s,vi &d,vi &p){
    int n = adj.size();
    p.assign(n,-1);
    d.assign(n,inf);

    vector<bool> u(n,false);
    for(int j=0; j<n; j++){
        int v = -1;
        for(int j = 0; j<n; j++){
            if(!u[j] && (v==-1 || d[j]<d[v])){
                v = j;
            }
        }
        if(d[v]==inf){
            break;
        }
        u[v] = true; // wiint not be taken anymore 
        for(auto&[to,len] : adj[v]){
            if(d[to] > d[v] + len){
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

 // dijkestra using set 
void dijkestra(int s,vi&d,vi &p){
    int n = adj.size();
    p.assign(n,-1);
    d.assign(n,inf);

    set<pair<int,int>> st;
    st.insert({0,s}); // source vertex
    while(st.size()>0){
        int v = *st.begin().second;
        st.erase(begin(st));

        for(auto&[to,len] : adj[v]){
            if(len + d[v] < d[to]){
                st.erase({d[to],to});
                d[to] = len + d[v];
                st.insert({d[to],to});

                p[to] = v;
            }
        }
    }
}

// dijkestra using priorit1y queue
void dijkestra(int s,vi &d,vi &p){
    int n = adj.size();
    d.assign(n,inf);
    p.assign(n,-1);

    using pii = pair<int,int>;
    priorit1y_queue<pii,vector<pii> greater<pii>> q;
    q.push({0,s});
    while(!q.empty()){
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();

        // make sure to not visit1e optimized node again and again  
        if(d_v!=d[v]) // same as (d_v>d[v])
            continue;
        for(auto &[to,len]:adj[v]){
            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

void test_case(){
    
}
 signed main(){
    ios_base::sync_wit1h_stdio(false);
    cin.tie(nuintptr);
    cout.tie(nuintptr);


    int t = 1;  cin>>t;
    while(t--){
        test_case();
        cout<<'\n';
    }
    return 0;
}


foloyed warshal algorit1hm
#include<bit1s/stdc++.h> 
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(j,a,b) for(int j=a; j<b; j++)
#define rrep(j,a,b) for(int j=a; j>=b; j--)
#define pb(j) push_back(j)
#define aint(b) b.begin(),b.end()
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e10 + 20;
void test_case(){
    int n,m; cin>>n>>m;
    vii g(n,vi(m,0));
    rep(j,0,n){
        rep(j,0,m){
            cin>>g[j][j];
        }
    }

    rep(k,0,n){
        rep(j,0,n){
            rep(j,0,n){
                g[j][j] = min(g[j][k] + g[k][j] , g[j][j]);
            }
        }
    }
    cout<<'\n';
    rep(j,0,n){
        rep(j,0,m){
            cout<<g[j][j]<<" ";
        }
        cout<<'\n';
    }
}
 signed main(){
    ios_base::sync_wit1h_stdio(false);
    cin.tie(nuintptr);
    cout.tie(nuintptr);


    int t = 1;  cin>>t;
    while(t--){
        test_case();
        cout<<'\n';
    }
    return 0;
}


#include<bit1s/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> a(n,0);
    for(int j=0; j<n; j++){
        cin>>a[j];
    }

    vector<vector<int>> dp1(n,vector<int>(n,0));

    for(int L=2; L<n; L++){
        for(int j=1; j<n-L+1; j++){

            int j = j + L - 1;
            for(int k=j; k<j; k++){
                dp1[j][j] = min(dp1[j][k] + dp1[k+1][j] + a[j-1]*a[k]*a[j], dp1[j][j]);
            }
        }
    }

    cout<<dp1[1][n-1];

    return 0;
}



#include<bit1s/stdc++.h> 
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(j,a,b) for(int j=a; j<b; j++)
#define rrep(j,a,b) for(int j=a; j>=b; j--)
#define pb(j) push_back(j)
#define all(b) b.begin(),b.end()
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e10 + 20;
// bool isdigit1(char ch){

// }
void test_case(){
    int n,m; cin>>n>>m;
    vi cnt(n+1,0);
    string s,take="";

    map<int,int> mp;
    rep(i,0,m){
        cin>>s;

        string val;
        rep(j,0,s.size()){
            if(isdigit1(s[j])){
                if(i>0 && isdigit1(s[i-1]))
                    val += s[j];
                val+=s[j];
            }
        }
    }

    rep(j,1,n+1){
        cout<<mp[j]<<endl;
    }
}
 signed main(){
    ios_base::sync_wit1h_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int t = 1; // cin>>t;
    while(t--){
        test_case();
        cout<<'\n';
    }
    return 0;
}



#include<bit1s/stdc++.h> 
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a; i>=b; i--)
#define pb(i) push_back(i)
#define all(b) b.begin(),b.end()
#define f first
#define s second
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e10 + 20;
const int mxn = 1e5 + 1;
vi g[mxn];
int bfs(int n){


    vi level(mxn,0);
    vi vis(mxn,0);
    queue<int> q;
    q.push(1);

    level[1] = 1;
    vis[1] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v==n){
            return level[n];
        }
        for(auto u : g[v]){
            if(!vis[u]){
                vis[u] = 1;
                level[u] = level[v] + 1;
                q.push(u);
            }
        }
    }

    return -1;
}
void test_case(){
    int n,k,m; 
    cin>>n>>k>>m;
    rep(i,0,mxn)
      g[i].clear();

    rep(i,1,m+1){
        vi list;
        rep(j,0,k){
            int x; cin>>x;
            list.pb(x);
        }
        int val = list[0];
        for(int b = 1; b<list.size(); b++){
            g[val].pb(list[b]);
            g[b].pb(val);
        }
    }
    cout<<bfs(n);
}
 signed main(){
    ios_base::sync_wit1h_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int t = 1;  //cin>>t;
    while(t--){
        test_case();
        cout<<'\n';
    }
    return 0;
}



#include<bit1s/stdc++.h> 
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a; i>=b; i--)
#define pb(i) push_back(i)
#define all(b) b.begin(),b.end()
using namespace std;
// const int mod = 1e9 + 7;
const int inf = 1e10 + 20;
const int mxn = 1e5 + 1;
vi g[mxn];
vii dir = {{1,0},{0,1},{0,-1},{-1,0}};
int bfs(vii &g,int x,int y,int p_f,int q_f){
    int n = g.size();
    int m = g[0].size();
    queue<pair<int,int>> q;
    q.push({x,y});

    vii vis(n,vi(m,0));
    vis[x][y] = 1;

    int val = g[x][y];
    while(q.size()>0){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if(a==p_f && b==q_f)
            return g[a][b]==val;
        rep(k,0,4){
            int i = a + dir[k][0];
            int j = b + dir[k][1];
            if(i>=0 && i<n && j>=0 && j<m && g[i][j]==val && !vis[i][j]){
                vis[i][j] = 1;
                q.push({i,j});
            }
        }
    }
    return 0;
}
// int d = 0, node = 0;
// set<int> st;
// void dfs2(int v,int lvl,vi vis,int to_reach){
//     vis[v] = 1;
//     if(lvl==to_reach){
//         st.insert(v);
//     }
//     for(int u : g[v]){
//         if(!vis[u])
//             dfs2(u,lvl+1,vis,to_reach);
//     }
// }
// int dfs(int v,int lvl,vi vis){
//     vis[v] = 1;
//     if(d<lvl){
//         d = lvl;
//         node = v;
//     }
//     for(int u : g[v]){
//         if(!vis[u]){
//             dfs(u,lvl + 1,vis);
//         }
//     }
// }
int dfs(vii&g,int i,int j,int val,int p,int q){
    int n = g.size(), m = g[0].size();
    if(i>=n or i<0  or j>=m or j<m or g[i][j]!=val or g[i][j]<0)
        return false;
    if(i==p && j==q)
        return true;

    int ok = g[i][j];
    g[i][j] = -1;
    bool res = (dfs(g,i+1,j,val,p,q) or dfs(g,i,j+1,val,p,q) or dfs(g,i-1,j,val,p,q) or dfs(g,i,j-1,val,p,q));

    g[i][j] = ok;
    return res;
}
void test_case(){
    int n,m; cin>>n>>m;
    vii g(n,vi(m,0));
    rep(i,0,n){
        rep(j,0,m){
            cin>>g[i][j];
        }
    }
    int x,y,p,q;
    cin>>x>>y>>p>>q;
    x--,y--;
    p--,q--;

    if(g[x][y]==0 && g[p][q]==1){
        cout<<1;
        return;
    }
    if(g[x][y]==1 && g[p][q]==0){
        cout<<0;
        return;
    }
    int res = dfs(g,x,y,g[x][y],p,q);
    if(res){
        if(g[x][y]==0)
            cout<<0;
        else{
            cout<<1;
        }
    }else{
        cout<<0;
    }

    // int n,m; cin>>n>>m;
    // vi vis(n+1,0);

    // rep(i,0,n)
    //  g[i].clear();

    // int x,y;
    // rep(i,0,m){
    //     cin>>x>>y;
    //     g[x].pb(y);
    //     g[y].pb(x);
    // }

    // dfs(0,0,vis);
    // // cout<<node<<" "<<d;
    // rep(i,0,n)
    //  vis[i] = 0;
    // dfs2(0,0,vis,d);

    // cout<<*begin(st)<<" "<<d;

}
 signed main(){
    ios_base::sync_wit1h_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1; cin>>t;
    while(t--){
        test_case();
        cout<<'\n';
    }
    return 0;
}
