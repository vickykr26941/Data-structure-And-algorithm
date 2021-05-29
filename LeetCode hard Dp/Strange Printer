
    // https://leetcode.com/problems/strange-printer/
class Solution {
public:
    const int inf = 1e9 + 7;
    using pii = pair<char,int>;
    vector<vector<int>> dp;
    int solve(vector<pii>&v,int i,int j){
        if(i > j) return inf;
        else if(i==j) return 1;
        else if(dp[i][j] != -1)
            return dp[i][j];
        
        int val = 1 + solve(v,i+1,j);
        for(int m=i+1; m<=j; m++){
            if(v[i].first==v[m].first){
                val = min(val, solve(v,i+1,m-1) + solve(v,m,j));
            }
        }
        return dp[i][j] = val;
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<pii> v;
        for(int i=0; i<n; i++){
            int k = 1;
            while(i<n-1 && s[i]==s[i+1]) i++,k++;
            v.push_back({s[i],k});
        }
        int len = v.size();
        dp.assign(len + 1, vector<int>(len + 1, -1));
        return solve(v,0,len-1);
    }
};

// // andsfasdr



    // more optimal // replace same sequence of character as single charachter
class Solution {
public:
    const int inf = 1e9 + 7;
    vector<vector<int>> dp;
    int solve(string &s,int i,int j){
        if(i > j) return inf;
        else if(i==j) return 1;
        else if(dp[i][j] != -1)
            return dp[i][j];
        
        int val = 1 + solve(s,i+1,j);
        for(int m=i+1; m<=j; m++){
            if(s[i]==s[m]){
                val = min(val, solve(s,i+1,m-1) + solve(s,m,j));
            }
        }
        return dp[i][j] = val;
    }
    int strangePrinter(string s) {
        int n = s.size();
        string str;
        for(int i=0; i<n; i++){
            while(i<n-1 && s[i]==s[i+1]) i++;
            str += s[i];
        }
        int len = str.size();
        dp.assign(len + 1, vector<int>(len + 1, -1));
        return solve(str,0,len - 1);
    }
};

// andsfasdr
