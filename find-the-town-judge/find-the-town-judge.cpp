class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
     vector<int> arr[N+1];
        int ar[N+1];
        for(int i=0;i<N+1;i++){
            ar[i]=0;
        }
        int x;
        for(int i=0;i<trust.size();i++){
            arr[trust[i][1]].push_back(trust[i][0]);
            ar[trust[i][0]]++;
        }
        for(int i=1;i<N+1;i++){
            if(arr[i].size()==N-1 && ar[i]==0){
                return i;
            }
        }
        return -1;   
    }
};