/*
  vicky kumar 
  date : 25/07/2021
  source : https://leetcode.com/problems/replace-the-substring-for-balanced-string/
*/


 // solution usign binary seach is easy 
// if x is a answer the x + 1 is aslo a possible asnwer , here answer is monotonically increasing 
// we can binary serch on the answer the chek if particlar answer is possible or not by replacing any window with size of answer 


class Solution {
public:
    
    // time complexity : nlogn
    
    vector<vector<int>> L;
    string str = "QWER";
    int check(string &s,int len){
        int n = s.size();
        
        bool any_ok = false;
        for(int i=1; i+len <=n+1; i++){
            vector<int> now(4,0);
            bool ok = true;
            for(int j=0; j<4; j++){
                now[j] = L[j][i-1] + (L[j][n] - L[j][i+len-1]);
                if(now[j] > n/4){
                  ok = false;
                }
            }
            any_ok = any_ok || ok;
        }
        
        return any_ok;
    }
    int balancedString(string s) {
        int n = s.size();
        L.assign(4,vector<int>(n+1,0));
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<4; j++){
                if(s[i-1] == str[j]){
                    L[j][i] = 1;
                }
            }
        }
        for(int i=0; i<4; i++){
            for(int j=1; j<=n; j++){
                L[i][j] += L[i][j-1];
            }
        }
        int l = 0, r = n;
        int ans = 0;
        
        while(l <= r){
            int m = (l + r)/2;
            if(check(s,m)){
                ans = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return ans;
    }
};






// the problem can solved uisng only sliding window too 
// as above we need only frequencey of Q,W,E,R outside the window 
// if frequency of each character outside the window less then n/4 then we can modify this window in any way 
// so we need to find the minimum size of winow such that frequency of each character outside of winodw is < n/4



class Solution {
public:
    
    const int inf = INT_MAX;
    int balancedString(string s) {
        int n = s.size();
        vector<int> cnt(128,0);
        
        int k = n/4;
        for(int i=0; i<n; i++){
            cnt[s[i]]++;
        }
        int ans = inf;
        int j = 0, i = 0;
        for(j = 0; j<n; j++){
            cnt[s[j]]--;
            while(i < n && cnt['Q'] <=k && cnt['W'] <= k && cnt['E'] <= k && cnt['R'] <= k){
                ans = min(ans, j - i + 1);
                cnt[s[i]]++;
                i++;
            }
        }
        
        return ans;
        
    }
};


