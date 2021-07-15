 class Solution {
public:
    int triangleNumber(vector<int>& nums) { int r=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int k=n-1;k>=0;k--)
        {int l=0; int h=k-1;
            while(l<h)
            { if(nums[l]+nums[h]>nums[k])
            {
                r+=h-l;
                h--;
            }else l++;
                
            }
        } return r;
    }
};