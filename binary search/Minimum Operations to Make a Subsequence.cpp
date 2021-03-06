/*
  
  vicky kumar 
  date : 06/07/2021
  problem : https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/
*/



class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        map<int,int> m;
        for(int i=0; i<target.size(); i++){
            m[target[i]] = i;
        }
        vector<int> v;
        for(int i=0; i<arr.size(); i++){
            if(m.find(arr[i]) == m.end()) continue;
            v.push_back(m[arr[i]]);
        }
        
        vector<int> a;
        for(int i=0; i<v.size(); i++){
            if(a.size() == 0 || a.back() < v[i]){
                a.push_back(v[i]);
            }
            else{
                int pos = lower_bound(begin(a),end(a),v[i]) - begin(a);
                if(pos < a.size())
                    a[pos] = v[i];
            }
        }
    return target.size() - a.size();
    }
};


// 1 0 5 4 2 0 3 
    
