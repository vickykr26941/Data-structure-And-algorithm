/*
  vicky kumar
  date : 20/07/2021
  source: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
*/

// hint : trie data structure
// first sort the queries on the basise of mi and sort array too
// then insert all the values less then mi and find the maximum possible result 
// seet the code for more details

class Solution {
public:
    struct trie{
        trie *child[2];
        trie(){
            this->child[0] = nullptr;
            this->child[1] = nullptr;
        }
    };
    
    trie *root;
    void insert(int val){
        trie *cur = root;
        for(int i=31; i>=0; i--){
            int index = ((val>>i)&1);
            if(cur->child[index]==nullptr)
                cur->child[index] = new trie();
            cur = cur->child[index];
        }
    }
    
    long get_max(int val){
        long ans = 0;
        trie * cur = root;
        if (!cur-> child[0] && !cur -> child[1])
                return -1; 
        
        bool ok = false;
        for(int i=31; i>=0; i--){
            int index = ((val>>i)&1);
            if(cur && cur->child[index^1]){
                ans += (1 << i);
                cur = cur->child[index^1];
            }
            else if(cur){
                cur = cur->child[index];
            }
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<vector<int>> q;
        for(int i=0; i<queries.size(); i++){
            auto v = queries[i];
            q.push_back({v[1],v[0],i});
        }
        sort(begin(q),end(q));
        sort(begin(arr),end(arr));
        
        int j=0;
        vector<int> res(queries.size(), 0);
        
        
        
        root = new trie();
        for(auto &x : q){
            int index = x[2];
            int m = x[0], xorto = x[1];
            while(j < arr.size() && arr[j] <= m){
                insert(arr[j]);
                j++;
            }
            res[index] =(int)get_max(xorto);
        }
        
        return res;
    }
};
