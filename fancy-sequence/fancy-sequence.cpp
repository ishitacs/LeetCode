class Fancy {
public:
      Fancy() {}
    
    void append(int val) {
        v.push_back(tuple{val, add, mul});
    }
    
    void addAll(int inc) {
        add += inc;
    }
    
    void multAll(int m) {
        mul = mul * m % mod;
        add = add * m % mod;
    }
    
    // let mx+a = res
    // (m2x+a2) * m + a = mul*x + add
    // m2*m = mul, a2m + a = add
    // m = mul/m2    
    int getIndex(int idx) {
        if(idx >= v.size()) return -1;        
        auto [x, a2, m2] = v[idx];        
        auto m = divide(mul, m2);
        auto a = (add + mod - (a2*m)%mod) % mod;
        return (m * x + a) % mod;    
    }
    
private:    
    using ll = long long;
    ll power(ll a, ll b){ 
        ll x = 1, y = a % mod; 
        while (b > 0){ 
            if (b%2) x = x * y % mod; 
            y = y * y % mod; 
            b /= 2; 
        } 
        return x % mod; 
    }	 
 
    ll modular_inverse(ll n){ 
        return power(n, mod-2); 
    } 
    
    ll divide(ll a, ll b){
        return a * modular_inverse(b) % mod;
    }
    
    static constexpr ll mod = 1e9+7;
    vector<tuple<ll,ll,ll>> v;  //val, add, multi   final value = val * multi + add
    ll add = 0;
    ll mul = 1;
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */