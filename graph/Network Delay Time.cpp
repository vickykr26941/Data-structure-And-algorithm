/*
 auther : vicky kumar 
 date : 21/08/2021
 source : https://leetcode.com/problems/network-delay-time/
 
*/





// usign floye warshal algorithm
// time complexity O(N^3)


class Solution {
public:
    const int inf = INT_MAX;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> v(n,vector<int>(n,inf));
        for(int i=0; i<times.size(); i++){
            int x = times[i][0],y = times[i][1], len = times[i][2];
            x--,y--;
            v[x][y] = len;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(v[k][j] != inf && v[i][k]!=inf){
                        v[i][j] = min(v[i][j],v[i][k] + v[k][j]);
                    }
                }
            }
        }
        
        k--;
        bool ok = true;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i!=k && v[k][i] == inf){
                ok = false;
                break;
            }
            else{
                if(i!= k) 
                  ans = max(ans,v[k][i]);
            }
        }
        if(!ok) return -1;
     return ans;
    }
};




// using Dijkestra algorithm
// we can implement using only dijkestra , 
// we need to find the shortest path from each node to k 
// that is same as shorted path from k to each node , if we can not reach all node then reutrn -1 
// else return the maximum of all the nodes distance



class Solution {
public:
    const int inf = INT_MAX;
    using pii = pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       
        vector<vector<pii>> g(n);
        for(int i=0; i<times.size(); i++){
            int x = times[i][0],y = times[i][1], len = times[i][2];
            x--,y--;
            g[x].push_back({y,len});
        }
        
        vector<int> dist(n,inf);
        
       
        auto dijkestra = [&](){
            priority_queue<pii,vector<pii>,greater<pii>> q;
            k--;
            q.push({0,k});
            dist[k] = 0;
            while(q.size() > 0){
                int from = q.top().second;
                int len = q.top().first;
                q.pop();
                
                if(len > dist[from]) continue;
                for(auto &to : g[from]){
                    int to_ = to.first, cost = to.second;
                    if(dist[to_] > cost + dist[from]){
                        dist[to_] = cost + dist[from];
                        q.push({dist[to_], to_});
                    }
                }
            }
        };
        
        dijkestra();
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(dist[i] == inf){
                return -1;
            }
            ans = max(ans,dist[i]);
        }
        
    return ans;
    }
};



