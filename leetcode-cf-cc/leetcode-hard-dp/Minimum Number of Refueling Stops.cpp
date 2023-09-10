/*
  vicky kumar 
  date : 07/07/2021
  problem : https://leetcode.com/problems/minimum-number-of-refueling-stops
*/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        
        // dp[i] = the farest locations we can reach with i refuling stations
        // at any time we could reach this station with t refuling stations 
        // then we can now reach capacity further with t +1 refuling stations
        
        long n = stations.size();
        if(startFuel >= target) return 0;
        vector<long> dp(n + 1,0);
        dp[0] = startFuel;
        for(int i=0; i<n; i++){
            for(int t = i; t>=0; t--){
                if(dp[t] >= stations[i][0]){
                    dp[t + 1] = max(dp[t + 1], dp[t] + long(stations[i][1]));
                }
            }
        }
        
        for(int i=0; i<=n; i++){
            // cout<<dp[i]<<" ";
            if(dp[i] >= target) return i;
        }
        return -1;
    }
};




// greedy approach uisng priority_queue

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int tank = startFuel;
        
        int prev = 0, result = 0;
        
        priority_queue<int> q;
        for(int i=0; i<n; i++){
            int Location = stations[i][0];
            int capacity = stations[i][1];
            
            tank -= Location - prev;
            
            // refule the tank while it's negative
            while(q.size() > 0 && tank < 0){
                tank += q.top();
                q.pop();
                result ++;
            }
            
            
            // after refuling the tank if tank is still empty then we can't reach the destination
            if(tank < 0) return -1;
            q.push(capacity);
            prev = Location;
        }
        
        
        tank -= target - prev;
        while(tank < 0 && q.size() >0 ){
            tank += q.top();
            q.pop();
            result ++;
        }
        if(tank < 0) return -1;
        
        return result ;
    }
};

