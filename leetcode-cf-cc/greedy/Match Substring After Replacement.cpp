class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
           
        
        
        // naive search algo TLE
//         map<char,vector<char>> m_forward, m_backward;
//         for(int i = 0; i < mappings.size(); i++){
//             char a = mappings[i][0], b = mappings[i][1];
//             m_forward[a].push_back(b);
//             m_backward[b].push_back(a);
//         }
     
//         int n = s.size(), m = sub.size();
//         for(int i = 0; i <=(n - m); i++){
//             int j = 0;
//             for(j = 0; j <m; ){
//                 bool ok = (sub[j] == s[i + j]);
//                 vector<char> possible_chars = m_forward[sub[j]];
//                 for(int k = 0; k < (int)possible_chars.size(); k++){
//                     if(possible_chars[k] == (s[i + j])){
//                         ok |= true;
//                     }
//                 }
//                 if(ok) j++;
//                 else break;
//             }
//             if(j == m) return true;
//         }
//         return false;
        
        
        
        
        // time : O(n * m)
        map<char, map<char,int>> m;
        for(int i = 0; i < mappings.size(); i++){
            char a = mappings[i][0], b = mappings[i][1];
            m[a][b] = 1;
        }
        int n = s.size(), k = sub.size();
        for(int i = 0; i <= (n - k); i++){
            int j = 0;
            for(j = 0; j < k; ){
                if((sub[j] == s[i + j]) or (m[sub[j]][s[i + j]] == 1)){
                    j ++;
                }else break;
            }
            if(j == k) return true;
        }
        
        return false;
    }
};
