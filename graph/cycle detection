// reference : cp algorithm
/* auther : vicky kumar


#include<bits/stdc++.h>
#define int long long 
using namespace std;


// cycle finding in directed graph // check graph is Acyclic or not
void test_case(){
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        x--,y--;
        g[x].push_back(y);
    }

    vector<int> parent(n,-1);
    vector<int> color(n,0);

    int cycle_start = -1,cycle_end = -1;
    function<int(int)> solve;
    solve = [&](int v){
        color[v] = 1;
        for(auto &u : g[v]){
            if(color[u] == 0){
                parent[u] = v;
                if(solve(u))
                    return true;
            }
            else if(color[u] == 1){
                cycle_start = u;
                cycle_end = v;
                return true;
            }
        }
        color[v] = 2;
        return false;
    };

    bool ok = false;
    for(int i=0; i<n; i++){
        if(!color[i] && solve(i)){
            ok = true;   // cycle found
            break;
        }
    }

    if(!ok){
        // no cycle
        cout<<-1;
        return;
    }
    else{
        vector<int> v;
        v.push_back(cycle_start);
        int to = cycle_end;
        while(to != cycle_start){
            v.push_back(to);
            to = parent[to];
        }
        v.push_back(cycle_start);
        reverse(begin(v),end(v));

        for(auto &u : v){
            cout<<u<<" ";
        }
    }


}
signed main(){
    int t = 1; cin>>t;
    while(t --){
        test_case();
        cout<<'\n';
    }

    return 0;
}



// cycle detection in directed graph
#include<bits/stdc++.h>
#define int long long 
using namespace std;
void test_case(){
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> parent(n,-1);
    vector<int> vis(n,0);
    int c_end = -1;
    int c_start = -1;


    function<int(int,int)> dfs;
    dfs = [&](int v,int par){
        vis[v] = 1;
        for(auto &u : g[v]){
            if(u == par) continue;
            if(!vis[u] && dfs(u,v)){
                parent[u] = v;
                return true;
            }
            else if(vis[u]){
                c_start = u;
                c_end = v;
                return true;
            }
       }
       return false;
    };

    bool ok = false;
    for(int i=0; i<n; i++){
        if(!vis[i] && dfs(i,-1)){
            ok = true;
            break;
        }
    }

    if(!ok){
        // cycle does not exist
        cout<<-1;
    }
    else{


        // cout<<"cycle is found";
        // cout<<c_start<<" "<<c_end;

        vector<int> v;
        v.push_back(c_start);
        while(c_end != c_start){
            v.push_back(c_end);
            c_end = parent[c_end];
        }
        v.push_back(c_start);

        reverse(begin(v),end(v));
        for(auto &u : v){
            cout<<u + 1<<" ";
        }
    }

}
signed main(){
    int t = 1; cin>>t;
    while(t --){
        test_case();
        cout<<'\n';
    }

    return 0;
}
