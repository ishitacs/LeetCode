 class Solution {
public:
    unordered_map<int,int> mapper;
    random_device rd;
    mt19937 gen;
    int size;
    
    Solution(int N, vector<int>& blacklist):gen(rd()),size(N - blacklist.size()) {
        int counter = N - blacklist.size();
        unordered_set<int> bl(begin(blacklist),end(blacklist));
        
        for(auto &b : blacklist){
            if(b < N - blacklist.size()){
                while(bl.count(counter)){
                    counter++;
                }        
                
                mapper[b] = counter++;
            }
        }
    }
    
    int pick() {
        uniform_int_distribution<int> uid(0,size - 1);
        int ret = uid(gen);
        
        if(mapper.count(ret)){
            return mapper[ret];
        }
        
        return ret;
    }
};