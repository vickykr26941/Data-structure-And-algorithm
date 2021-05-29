
    // https://leetcode.com/problems/word-break-ii/

class Solution {
public:
    set<string> st;
    vector<string> res;
    void solve(string &s,int i,int j,string cur_str){
        if(i>=s.size()){
            cur_str.pop_back();
            res.push_back(cur_str);
            return;
        }
        for(int k=i; k<j; k++){
            string tmp = s.substr(i,k-i+1);
            if(st.find(tmp) != st.end()){
                string t = cur_str;
                cur_str += tmp + " ";
                solve(s,k+1,j,cur_str);
                cur_str = t;
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &w : wordDict){
            st.insert(w);
        }
        
        int n = s.size();
        solve(s,0,s.size(),"");
        return res;
    }
};
