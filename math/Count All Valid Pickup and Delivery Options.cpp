     // question tag - hard pnc
     // source : https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/




class Solution {
public:
    int mod = 1e9 + 7;
    int countOrders(int n) {
        long res = 1;
        for(int i=1; i<=n; i++){
            res = (res * (2 * i * i  - i) % mod) %mod;
        }
    return res;
    }
};

// p1,p2,p3,p4,p5,..........
// for d1 we have 1 choice to place at the end
// p1,p2,p3,.....pn-1,pn,dn
// now for d2 we have 2 choice to place dn-1
// p1,p2,p3,.....pn-2,pn-1,dn-1,pn,dn
// now for d3 we have 5 choices to place dn - 2
    
// so 1 * 3 *5 * 7 ........... * 2n - 1
// ans each pair we can permutate with n! so that order remain unchanged
// so final result is res = (n! * (1 * 3 * ........ 2n- 1)) % 10^9 + 7;
