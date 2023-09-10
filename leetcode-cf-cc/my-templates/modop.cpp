
  
namespace modop{
    int addmod(int a,int b){
        return (a + b) % mod;
    }
    int submod(int a,int b){
        int x = (a - b) % mod;
        if(x < 0)
            x += mod;
        return x;
    }
    int mulmod(int a,int b){
        int x = a % mod;
        int y = b % mod;
        return (x * y) % mod;
    }
    int pmod(int a,int b){
        int ans = 1;
        while(b>0){
            if(b&1){
                ans = (ans * a) % mod;
                b >>= 1;
            }
            a = (a * a) %mod;
        }
        return ans;
    }
    int inv(int n){
        return pmod(n,mod - 2);
    }
    int divmod(int a,int b){
        return mulmod(a,inv(b));
    }
}
using namespace modop;
