/*
 vicky kumar 
 date : 19/09/21
 https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree

*/


class Solution {
public:
    
    int visited[100005];
    void dfs(vector<vector<int>>&g,int v,vector<int>&arr){
        if(!visited[arr[v]]){
            visited[arr[v]] = 1;
            for(auto &u : g[v]){
                dfs(g,u,arr);
            }
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> g(n);
        for(int i = 0; i<parents.size(); i++){
            if(parents[i] != -1){
                g[parents[i]].push_back(i);
            }
        }
        int pos = 0, min = 1;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == 1){
                pos = i;
                break;
            }
        }
        vector<int> res(n,1);
        for(; pos != -1; pos = parents[pos]){
            dfs(g,pos,arr);
            while(visited[min]){
                min++;
            }
            res[pos] = min;
        }
        return res;
    }
};
