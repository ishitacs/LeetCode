 class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>mp;
        for(auto x:arr)
        {
            mp[x]++;
        }
           
         vector<int> vec;

        map<int, int>::iterator it = mp.begin();
	    while(it!=mp.end())
        {
            vec.push_back(it->second);
            it++;
        }
        
        sort(vec.begin(),vec.end(),greater<int>());
        		
        int len = arr.size()/2;
        int ans = 0;
        for (auto p: vec) {
		    if(len<=0)
            {
                break;
            }
            len -= p;
            ans++;
	    }
        return ans;
    }
};