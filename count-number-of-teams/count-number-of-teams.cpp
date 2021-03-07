 class Solution {
public:
    
    int numTeams(vector<int>& rating) {
        int n=rating.size(),res=0,rightLess,rightGreat,leftLess,leftGreat;
        if(n<3)return 0;
        for(int i=1;i<n-1;i++){
            rightLess=0;rightGreat=0; leftLess=0; leftGreat=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i])leftLess++;
                else leftGreat++;
            }    
            for(int j=i+1;j<n;j++){
                if(rating[j]>rating[i])rightGreat++;
                else rightLess++;
            }
            res=res+leftLess*rightGreat + leftGreat*rightLess;
        }
        return res;
    }
};