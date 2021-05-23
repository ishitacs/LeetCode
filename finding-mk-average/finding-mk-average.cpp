 class MKAverage {
public:
    MKAverage(int m, int k): m(m), k(k) {
        
    }
    
    void addElement(int num) {
        //O(logN)
        dq.push_back(num);
        mp[num]++;
        sum+=num;
        if(dq.size()>m) {
            //if there are more then m elements, remove the first element.
            //from deque and mp.
            int front = dq.front();
            mp[front]--;
            sum-=front;
            if(mp[front]==0) mp.erase(front);
            dq.pop_front();
        }
    }
    
    int calculateMKAverage() {
        //O(K)
        if(dq.size()<m) return -1;
        long long int temp_sum = sum;
        
        //normal order: remove smallest k number from sum
        int temp_k = k;
        for(auto it = mp.begin(); it!=mp.end(); it++){
            if(temp_k >= it->second){
                temp_sum -= it->first*it->second;
                temp_k-=it->second;
            }
            else{
                temp_sum -= it->first*temp_k;
                break;
            }
        }
        
        //reverse order: remove largest k number from sum
        temp_k = k;
        for(auto it = mp.rbegin(); it!=mp.rend(); it++){
            if(temp_k >= it->second){
                temp_sum -= it->first*it->second;
                temp_k-=it->second;
            }
            else{
                temp_sum -= it->first*temp_k;
                break;
            }
        }
        
        return temp_sum/(m-2*k);
    }
private:
    const int m = 0;
    const int k = 0;
    deque<int> dq; //used for keeping only m elements
    map<int, int> mp; //act as an sorted array
    long long int sum = 0; //the sum of current m numbers.
};