class Solution {
public:
    int findMinFibonacciNumbers(int k) { vector<int> fib;
     int t1=1; int t2=1;
        while(t1<=k)
        { 
            fib.push_back(t1);
            int t=t1+t2;
         t1=t2;
         t2=t;
        }
    int c=0;
          while(k>0)
          { k=k-fib.back();
           while(fib.size()>0 && k<fib.back()) fib.pop_back();
              c++;
          }
        return c;
    }
};
//   int c=1,c1=1;
//         vector<int> v;
//         while(c<=k)
//         {
//             v.push_back(c);
//             int t=c+c1;
//             c=c1;
//             c1=t;
//         }
//         int res=0;
//         while(k>0)
//         {
//             k=k-v.back();
            