class Solution {
public:
    int totalMoney(int n) { int sum=0; int j=1; int p=0;
        for(int i=1;i<=n;i++)
        { sum+=(j+p);
         p++;
         if(i%7==0){
             p=0;
             j++;
         }
            
            
        } return sum;
        
    }
};