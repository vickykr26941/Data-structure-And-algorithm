

// https://leetcode.com/problems/search-suggestions-system/

   // solution using binary search 

// class Solution {
// public:
    
//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        
//         vector<vector<string>> res(searchWord.size());
        
//         sort(begin(products) , end(products));
//         string key;
        
//         for(int i = 0; i < (int)searchWord.size(); i++){
//             key += searchWord[i];
//             int l = 0, r = products.size();
            
//             int start_pos = lower_bound(begin(products), end(products), key) - begin(products);
//             // int start_pos = -1;
//             // while(l <= r){
//             //     int m = (l + r) / 2;
//             //     bool ok = true;
//             //     for(int k = 0; k < (int)key.size(); k++){
//             //         if(products[m][k] < key[i]) continue;
//             //         else {
//             //             ok = false;
//             //             break;
//             //         }
//             //     }
//             //     if(ok){
//             //         start_pos = m;
//             //         r = m - 1;
//             //     }else{
//             //         l = m + 1;
//             //     }
//             // }
        
//             if(start_pos != -1){
//                 for(int j = start_pos; j < min(start_pos + 3, (int)products.size()); j++){
//                     if(products[j].substr(0, key.size()) == key){
//                         res[key.size() - 1].push_back(products[j]);
//                     }
//                 }
//             }
//         }
        
//         return res;
//     }
// };




        // solution using trie

class Solution {
public:
    struct trie{
        struct trie *child[26];
        bool is_end;
        trie(){
            for(int i = 0; i < 26; i++){
               this -> child[i] = nullptr;
               this -> is_end = false;
            }
        }
    };
    
    void insert(trie *root, string &key){
        trie *node = root;
        for(int i = 0; i < (int)key.size(); i++){
            if(!node -> child[key[i] - 'a']){
                node -> child[key[i] - 'a'] = new trie();
            }
            node = node -> child[key[i] - 'a'];
        }
        node -> is_end = true;
    }
    
    void dfs(trie *node, string &cur_res, vector<string> &v){
       
      
        if(v.size() >= 3) return;
        if(node -> is_end){
            v.push_back(cur_res);
        }
        for(int i = 0; i < 26; i++){
            if(node -> child[i]){
                cur_res += (i + 'a');
                dfs(node->child[i], cur_res, v);
                cur_res.pop_back();
            }
            // node = node -> child[i];
        }
        
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
       vector<vector<string>> res;
        
        
       trie *root = new trie();
       trie *node = root;
        for(int i = 0; i < (int)products.size(); i++){
            insert(root, products[i]);
        }
        string key;
        for(int i = 0; i < (int)searchWord.size(); i++){
            key += searchWord[i];
            
            node = root;
            
            bool ok = true;
            for(int j = 0; j < (int)key.size(); j++){
                if(node -> child[key[j] - 'a']){
                    node = node -> child[key[j] - 'a'];
                } else{
                    ok = false;
                    break;
                }
            }
            
            vector<string > v;
            if(ok) dfs(node,key, v);
            res.push_back(v);
        }
        
        return res;
    }
};


