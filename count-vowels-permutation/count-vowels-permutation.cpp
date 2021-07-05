 class Solution {
public:
  int countVowelPermutation(int n) {
    unsigned int a = 1, e = 1, i = 1, o = 1, u = 1, mod = 1000000007;
    while(--n){
      unsigned int new_a = (e + i + u)%mod;
      unsigned int new_e = (a + i)%mod;
      unsigned int new_i = (e + o)%mod;
      unsigned int new_u = (i + o)%mod;
      a = new_a, e = new_e, o = i%mod, i = new_i, u = new_u;
    }
    
    return (a + e + i + o + u)%mod;
  }
};