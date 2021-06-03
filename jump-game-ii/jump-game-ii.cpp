class Solution {
public:
    int jump(vector<int>& nums) { int cr=0; int m=0;int j=0;
                            
        for(int i=0;i<nums.size()-1;i++)
        { 
            if(i+nums[i]>m)
            {
                m=i+nums[i];
            }
            if(i==cr) {j++; cr=m;}
        }return j;
    }
};