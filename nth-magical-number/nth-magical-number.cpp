class Solution {
public:
      int gcd(int a ,int b)
    {
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
    int nthMagicalNumber(int n, int a, int b) {
        int mod=1000000007;
        int lcm=(a*b)/gcd(a,b);
        long long l=min(a,b);
        long long r;
        r=n*l;    // to avoid overflow int*int cant use
        while(l<=r)
        {
            long long m=l+(r-l)/2;
            long long fact=0;
            fact+=m/a;
            fact+=m/b;
            fact-=m/lcm;
            if(fact==n)
            {
                if(m%a==0 || m%b==0)
                    return m%mod;
                r=m-1;
            }
            else if(fact>n)
                r=m-1;
            else
                l=m+1;
        }
        return -1;
        
    }
};