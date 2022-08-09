/*
 auther : vicky kumar
 date : 11/07/2021
 problem : https://leetcode.com/problems/k-similar-strings/
*/

// idea : Do bfs 's' as node and the take transition only on valid string to avoid TLE 
 // valid string are where a[i] != b[i], then swap(a[i],a[j]) where a[j] == b[i] for all j in 'a'
 

class Solution {
public:
    
    vector<string> get(string &s,string &t){
        vector<string> count;
        int i = 0, j = 0;
        while(i < s.size()){
            if(s[i] != t[i]) break;
            i++;
        }
        j = i;
        while(j < s.size()){
            if(t[i] == s[j]){
                swap(s[j],s[i]);
                count.push_back(s);
                swap(s[j],s[i]);
            }
            j++;
        }
      return count;
    }
    int kSimilarity(string s, string t) {
        queue<string> q;
        q.push(s);
        set<string> vis;
        vis.insert(s);
        
        int level = 0;
        while(q.size() > 0){
           int size = q.size();
           for(int i=0; i<size; i++){
               string f = q.front();
               q.pop();
               if(f == t)
                   return level;
               
               for(string &x : get(f,t)){
                   if(vis.count(x)==0){
                       vis.insert(x);
                       q.push(x);
                   }
               }
           }
        level++;
        }
        
    return -1;
    }
};
