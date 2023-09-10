
    // https://leetcode.com/problems/video-stitching/

class Solution {
public: 
    const int inf = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>&v,int i,int l,int h,int target){
        if(i>=v.size()){
            return h>=target?0:inf;
        }
        if(h>=target) return 0;
        else if(dp[i][l][h] != -1)
            return dp[i][l][h];
        if(v[i][0] <= h) {
            int x = 1 + solve(v,i+1,min(l,v[i][0]),max(h,v[i][1]),target);
            int y = solve(v,i + 1,l,h,target);
            return dp[i][l][h] = min(x,y);
        }
        return dp[i][l][h] = inf;
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        if(time==0 or n==0) return 0;
        int l = 0,r = 0;
        for(auto &x : clips){
            l = max(l,x[0]);
            r = max(r,x[1]);
        }
       
        
        dp.assign(n+1,vector<vector<int>>(l+1,vector<int>(r +1,-1)));
        sort(begin(clips),end(clips));
         for(auto &x : clips)
            cout<<x[0]<<" "<<x[1]<<endl;
        
        int ans = solve(clips,0,0,0,time); 
        
        return ans>=inf ? -1 : ans;
    }
};


   // greedy solution 
 // it's better to extend the right till it possible and take the time which can cover largest interval
class Solution {
public: 
    const int inf = 1e9 + 7;
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        sort(begin(clips),end(clips));
        int maxReach = 0;
        int ans = 0,i = 0;
        while(maxReach < time){
            int curMaxReach = 0;
            while(i < n && clips[i][0]<= maxReach){
                curMaxReach = max(curMaxReach, clips[i][1]);
                i++;
            }
            if(curMaxReach <= maxReach) return -1;
            maxReach = curMaxReach;
            ans++;
        }
        return ans;
    }
};
