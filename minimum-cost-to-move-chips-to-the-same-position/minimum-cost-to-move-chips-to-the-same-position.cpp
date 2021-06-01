class Solution {
public:
    int minCostToMoveChips(vector<int>& p) { int e=0; int o=0;
    for(auto i:p)
    {
        if(i%2==0) e++;
        else o++;
    } return min(e,o);
        
    }
};