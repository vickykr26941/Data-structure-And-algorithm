// date : 02/06/2022



class Solution {
public:
    
    
    
    // time : nlogn
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
//         sort(begin(flowers),end(flowers));
        
//         vector<vector<int>> rev_flowers = flowers;
//         sort(begin(rev_flowers),end(rev_flowers),[&](vector<int> &a , vector<int> &b){ return a[1] < b[1]; });
//         // sort(begin(persons),end(persons));
        
//         using pii = pair<int,int>;
//         multiset<pii> st;
//         vector<pii> ordered_persons;
//         for(int i = 0; i < (int)persons.size(); i++){
//             ordered_persons.push_back({persons[i],i});
//         }
//         sort(begin(ordered_persons),end(ordered_persons));
        
//         int i = 0, j = 0, n = persons.size();
//         vector<int> res(persons.size(), 0);
//         for(int k = 0; k < n; k++){
//             while(i < flowers.size() && flowers[i][0] <= ordered_persons[k].first){
//                 st.insert({flowers[i][0], flowers[i][1]});
//                 i ++;
//             }
//             while(j < rev_flowers.size() && rev_flowers[j][1] < ordered_persons[k].first){
//                 st.erase({rev_flowers[j][0], rev_flowers[j][1]});
//                 j++;
//             }
//             res[ordered_persons[k].second] = st.size();
//         }
//         return res;
        
        
        
        using pii = pair<int,int>;
        vector<pii> q;
        vector<int> res(persons.size(), 0);
        priority_queue<int, vector<int>, greater<int> > pq;
        int c = 0, i = 0;
        
        
        for(auto &e : persons) q.push_back({e, c++});
        sort(begin(flowers) , end(flowers));
        sort(begin(q), end(q));
        
        for(int k = 0; k < (int)q.size(); k++){
            while(i < (int)flowers.size() && flowers[i][0] <= q[k].first){
                pq.push(flowers[i][1]);
                i++;
            }
            while(pq.size() > 0 && pq.top() < q[k].first) pq.pop();
            res[q[k].second] = pq.size();
        }
        return res;
        
        
    }
};
