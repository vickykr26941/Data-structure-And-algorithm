

namespace bit{
    int n; 
    vector<int> a;
    void init(int s){
        a = vector<int>(s + 1, 0);
        n = s;
    }

    void add(int loc,int val){
        if(loc <=0 ) return;
        while(loc <= n){
            a[loc] += val;
            loc += loc & (-loc);
        }
    }

    int query(int loc){
        int s = 0;
        while(loc > 0){
            s += a[loc];
            loc -= loc & (-loc);
        }
     return s;
    }

   // bit's are 1 based indexed
}
using namespace bit;
