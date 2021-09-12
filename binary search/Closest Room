/*
 vicky kumar
 date : 13/09/2021

 https://leetcode.com/problems/closest-room/
 
*/



class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        
        int n = queries.size();
        for(int i = 0; i<n; i++) queries[i].push_back(i);
        sort(begin(queries),end(queries),[&](vector<int>&a,vector<int>&b){return a[1] > b[1];});
        sort(begin(rooms),end(rooms),[&](vector<int>&a,vector<int>&b){return a[1] > b[1];});
    
        set<int> ids;
        vector<int> res(n,-1);
        
        int i = 0;
        for(auto q : queries){
            int pos = q[2], size = q[1], id = q[0];
            while(i < rooms.size() && rooms[i][1] >= size){
                ids.insert(rooms[i][0]);
                i++;
            }
            if(ids.size() > 0){
                auto it = ids.upper_bound(id);
                int id_diff = it != end(ids) ? abs(*it - id) : INT_MAX;
                int room_id = it != end(ids) ? *it : INT_MAX;
                
                if(it != begin(ids)){
                    --it;
                    if(abs(*it - id) <= id_diff){
                        room_id = *it;
                    }
                }
                res[pos] = room_id;
            }
        }
        return res;
    }
};

