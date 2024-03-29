 class Solution {
public:
    long res=0;
    int findKthNumber(int n, int k) {
        vector<long>dig={0,1,11,111,1111,11111,111111,1111111,11111111,111111111};
        string N=to_string(n);
        
        
        for(int i=1;i<=9;i++){
            long first=N[0]-'0';
            long cnt=0;
            if(i<first){
                cnt=dig[N.size()];
                if(k<=cnt){
                    dfs(dig,N,k-1,N.size()-1,i,false,0,0);
                    break;
                }else{
                    k-=cnt;
                }
            }
            else if(i==first){
                cnt=n-dig[N.size()]*(i-1)-dig[N.size()-1]*(9-i);
                if(k<=cnt){
                    dfs(dig,N,k-1,N.size()-1,i,true,1,cnt-1);
                    break;
                }else{
                    k-=cnt;
                }
            }
            else{
                cnt=dig[N.size()-1];
                if(k<=cnt){
                    dfs(dig,N,k-1,N.size()-2,i,false,0,0);
                    break;
                }else{
                    k-=cnt;
                }
            }
        }
        return (int)(res);
    }
    
    void dfs(vector<long>&dig,string N,long k,int index,long cur,bool same,int ith,long n){
        if(k==0){
            res=cur;
            return;
        }
        if(same){
            int first=N[ith]-'0';
            for(int i=0;i<=9;i++){
                long cnt=0;
                if(i<first){
                    cnt=dig[index];
                    if(k<=cnt){
                        dfs(dig,N,k-1,index-1,cur*10+i,false,0,0);
                        break;
                    }else{
                        k-=cnt;
                    }
                }
                else if(i==first){
                    cnt=n-dig[index]*(i)-dig[index-1]*(10-i-1);
                    if(k<=cnt){
                        dfs(dig,N,k-1,index-1,cur*10+i,true,ith+1,cnt-1);
                        break;
                    }else{
                        k-=cnt;
                    }
                }
                else{
                    cnt=dig[index-1];
                    if(k<=cnt){
                        dfs(dig,N,k-1,index-2,cur*10+i,false,0,0);
                        break;
                    }else{
                        k-=cnt;
                    }
                }
            }
            
        }else{
            for(int i=0;i<=9;i++){
                int cnt=dig[index];
                if(k<=cnt){
                    dfs(dig,N,k-1,index-1,cur*10+i,false,0,0);
                    break;
                }else{
                    k-=cnt;
                }
            }
        }
    }
    
};
