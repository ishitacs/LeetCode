class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int>m;
        int i=nums2.size()-1;
        vector<int>ans;
        while(i>=0)
        {
            while(s.size() and nums2[i]>s.top()) s.pop();
            if(s.size()) m[nums2[i]]= s.top();
            else m[nums2[i]]=-1;
            s.push(nums2[i]);
            i--;
        }
        for(auto i:nums1)
            ans.push_back(m[i]);
    return ans;}
};
  
        
         
				 
           
       
        
