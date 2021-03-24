class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        
                int N=grid.size();
        int sum=0;                                                                                      
        for(int i=0;i<N;i++)
        {
            int max=*max_element(grid[i].begin(),grid[i].end());            
            sum+=max;                                                                          
        }
     
        int k=0;
        for(int i=0;i<N;i++){
            int maxel=0;
            for(int j=0;j<N;j++){
                if(grid[j][i]==0) k++;                                   
                maxel=max(maxel,grid[j][i]);                         
            }
            sum+=maxel;                                                     
        
        }
    
		sum+=(N*N);                                        
        sum-=k;                                               
        return sum;
    

    }
};