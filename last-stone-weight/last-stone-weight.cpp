class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    int k=stones.size();
        priority_queue<int>pq;
        for(auto i:stones){pq.push(i);}
        while(pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
         pq.push(abs(a-b)); 
        }return pq.top();
    }
};