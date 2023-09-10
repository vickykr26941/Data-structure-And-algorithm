
// date : March 01 // 22
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i = 0; i<n; i++) arr[i] = ((arr[i] % k) + k ) % k;
        multiset<int> st(begin(arr),end(arr));
        
        
         while(st.size() > 0){
            int val = *begin(st);
            if(val == 0){
              if(st.count(val) % 2 == 0){
                  st.erase(val);
              }else{
                  return false;
              }
            }else{
                int need = k - val;
                st.erase(st.find(val));
                if(st.count(need) > 0){
                    st.erase(st.find(need));
                }else{
                    return false;
                 }
            }
            if(st.size() <= 0) break;
        }
        return true;
    }
};
