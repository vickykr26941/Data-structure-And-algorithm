// date : 02/06/2022


class Solution {
public:
    
    const int inf = 1e9 + 7;
    vector<int> minInterval(vector<vector<int>>& arr, vector<int>& queries) {
        
        using pii = pair<int,int> ;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<pii> q;
        vector<int> res(queries.size(), -1);
        
        int c = 0, i = 0;
        for(auto &e : queries) q.push_back({e, c++});
        
        
        sort(begin(arr), end(arr));
        sort(begin(q), end(q));
        
        map<int,int > m;
        
        for(int k = 0; k <(int)q.size(); k++){
            while(i < arr.size() && arr[i][0] <= q[k].first){
                int len = arr[i][1] - arr[i][0] + 1;
                m[len] ++;
                pq.push({arr[i][1], len});
                i++;
            }
            while(pq.size() > 0 && pq.top().first < q[k].first){
                int len = pq.top().second;
                m[len]--;
                if(m[len] == 0) m.erase(len);
                pq.pop();
            }
            if(m.size() > 0){
                res[q[k].second] = begin(m)->first;
            }
        }
        return res;
    }
};
