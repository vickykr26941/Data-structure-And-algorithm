/*
  author : vicky kumar
  date : 06/07/2021
  source : https://leetcode.com/problems/gcd-sort-of-an-array/
*/

// make graph those elements have commnon divisors
// then sort each connected component seperately if whole array become sorted then answer is yes otherwise no 


class Solution {
public:
    const int N = 1e5 + 10;
    int prime[100000 + 20];
    vector<int> pms;
    void seive(){
        for(int i = 0; i<=N; i++) prime[i] = 1;
        prime[0] = prime[1] = 0;
        for(int i = 2; i * i <=N; i++){
            if(prime[i]){
                for(int j = i * i; j<=N; j+=i){
                    prime[j] = 0;
                }
            }
        }
        for(int i = 0; i<=N; i++){
           if(prime[i] == 1) pms.push_back(i);
        }
    }
    bool gcdSort(vector<int>& arr) {
        seive();
        
        int n = arr.size();
        vector<vector<int>> divs(n);
        for(int i = 0; i<n; i++){
            int val = arr[i];
            for(auto d : pms){
                if(d * d > val) break;
                if(val % d == 0){
                   divs[i].push_back(d);
                    while(val % d == 0){
                     val/=d;
                  } 
                }
            }
            if(val > 1){
                divs[i].push_back(val);
            }
        }
        vector<vector<int>> edges;
        map<int,int> m;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<divs[i].size(); j++){
                if(m.find(divs[i][j]) != m.end()){
                    edges.push_back({m[divs[i][j]], i});
                }
                m[divs[i][j]] = i;
            }
        }    
        // sort the each connected component seprately 
        vector<int> par(n,0);
        for(int i = 0; i<n; i++){
            par[i] = i;
        }
        function<int(int)> find;
        find = [&](int x){
            if(par[x] == x) return x;
            return par[x] = find(par[x]);
        };
        
        for(auto edge : edges){
            int x = edge[0], y = edge[1];
            x = find(x);
            y = find(y);
            if(x != y){
                par[x] = y;
            }
        }
        for(int i = 0; i<n; i++){
            par[find(i)] = find(i);
        }
        map<int,vector<int>> comp;
        for(int i = 0; i<n; i++){
            comp[par[i]].push_back(i);
        }
        vector<int> res(n,0);
        for(auto &v : comp){
            sort(begin(v.second),end(v.second));
            vector<int> vt;
            for(int i = 0; i<v.second.size(); i++){
                vt.push_back(arr[v.second[i]]);
            }
            sort(begin(vt),end(vt));
            for(int i = 0; i<vt.size(); i++){
                res[v.second[i]] = vt[i];
            }
        }
        for(int i = 1; i<n; i++){
            if(res[i-1] > res[i]) return false;
        }
        
        return true;
        
    }
};


