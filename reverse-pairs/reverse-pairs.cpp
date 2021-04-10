class Solution {
public:
    void insert(int i,vector<int>& sums_) {
        while (i < sums_.size()) {
            sums_[i] += 1;
            i += lowbit(i);
        }
    }
    
    int search(int i,vector<int>& sums_) {
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end(), greater<int>());
        
        vector<int> sums_(nums.size()+1,0);
        int sum = 0;
        for (int i = 0;i < nums.size();i++) {
            int index = findIndex(copy,2LL*nums[i] + 1);
            int res = index == -1 ? 0 : search(index + 1,sums_);
            sum += res;
            int insertIndex = findIndex(copy,nums[i]);
            insert(insertIndex + 1,sums_);
        }
        return sum;
    }
    
    int findIndex(vector<int>& copy, long target) {
        int start = 0;
        int end = copy.size() - 1;
        while(start+1<end) {
            int mid = (start + end)/2;
            if (copy[mid] == target) {
                return mid;
            }
            if (copy[mid] > target) {
                start = mid;
            }
            if (copy[mid] < target) {
                end = mid;
            }
        }
        if (copy[end] >= target) {
            return end;
        }
        
        if (copy[start] >= target) {
            return start;
        }
        return -1;
        
    }
private:
    static inline int lowbit(int x) {return x & (-x);}
};