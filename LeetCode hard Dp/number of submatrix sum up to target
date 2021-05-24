// class Solution {
// public:
//     int numSubmatrixSumTarget(vector<vector<int>>& mat, int val) {
//         int n = mat.size() , m =mat[0].size();
//         for(int i=0; i<n; i++){
//             for(int j=1; j<m; j++){
//                 mat[i][j] +=mat[i][j-1];
//             }
//         }
//         int res =0;
//         unordered_map<int,int> map;
        
//         for(int i=0; i<m; i++){
//             for(int j=i; j<m; j++){
//                 int s= 0;
//                 map = {{0,1}};
//                 for(int k=0; k<n; k++){
//                     s+=mat[k][j] - (i>0?mat[k][i-1]:0);
//                     res += (map.find(s-val)!=map.end())?map[s-val] : 0;
//                     map[s]++;
//                 }
//             }
//         } 
//     return res;
//     }
// };

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int val) {
        int n = mat.size(), m = mat[0].size();
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++){
                mat[i][j] +=mat[i-1][j];
            }
        }
        unordered_map<int,int> mp;
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                mp = {{0,1}};
                int s = 0;
                for(int k=0; k<m; k++){
                    s+=mat[j][k] - (i>0?mat[i-1][k]:0);
                    res+=mp.find(s-val)!=mp.end()? mp[s-val] : 0;
                    mp[s]++;
                }
            }
        }
     
    return res;
    }
};
