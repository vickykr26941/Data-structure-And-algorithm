/*
  vicky kumar
  date : 20/07/2021
  source : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
*/

  // hint : trie data structre 
// insert all the values to the trie
// then again tarverse the array and look for the maximum xor with opposite bits
// see the code for easy to understant

class Solution {
public:
    
    
    const int inf = 1e9 + 7;
    struct trie{
        trie *child[2];
        trie(){
            this->child[0] = nullptr;
            this->child[1] = nullptr;
        }
    };
    
    int findMaximumXOR(vector<int>& arr) {
        int n = arr.size();
        
        trie *root = new trie();
        for(int i=0; i<arr.size(); i++){
            int val = arr[i];
            struct trie *cur = root;
            for(int j=0; j<32; j++){
                int index = (val & (1 << j)) > 0;
                if(!cur->child[index]){
                    cur->child[index] = new trie();
                }
                cur = cur->child[index];
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            int val = arr[i];
            struct trie *cur = root;
            
            int cur_res = 0;
            for(int j=0; j<32; j++){
                int index = (val &(1 << j)) > 0;
                if(cur->child[index^1]){
                    cur_res += (1 << j);
                    cur = cur->child[index^1];
                }
                else{
                    cur = cur->child[index];
                }
            }
            
            ans = max(ans,cur_res);
        }
    return ans;
    }
};

// 00011 3 
// 01010 10
// 00101 5
// 11001 25
// 00010 2
// 01000 8 

  
