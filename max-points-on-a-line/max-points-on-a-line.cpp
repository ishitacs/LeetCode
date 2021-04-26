 #define ll long long 
class Solution {
public:
    string fractionToDecimal(int n, int d) {
        ll numerator=n;
        ll denominator=d;
        string q="";
        bool isNegative=false;
        if(numerator==0) return "0";
        int numNeg=0;
        if(numerator<0){ 
            numerator=abs(numerator);
            numNeg++;
        }
        if(denominator<0)
        {
            denominator=abs(denominator);
            numNeg++;
        }
        if(numNeg==1) isNegative=true;
        
        unordered_map<ll,ll> pos;
        bool isDecimal=false;
        bool isopening=false;
        while(1)
        {
            if(pos.find(numerator)!=pos.end())
            {
                //there is a repition
                q.insert(pos[numerator],"(");
                isopening=true;
                break;
            }
            if(numerator<denominator&&!isDecimal)
            {
                if(q.length()){
                    q+='.';
                }
                else{
                    q="0.";
                }
                isDecimal=true;
            }
            pos[numerator]=q.length(); //this is at index where opening bracket will be added 
           
            //q building starts
            int req=-1;
            while(numerator<denominator)
            {
                numerator*=10;
                req++;
            }
            for(int i=1;i<=req;i++)
            {
                q+='0';
            }
            q+=to_string(numerator/denominator);
            //q building ends 
            
            numerator=numerator%denominator;
            if(numerator==0) break;
            
        }
        if(isopening)
        {
            q+=')';
        }
        if(isNegative){
            q="-"+q;
        }
        return q;
    }
    string find(string x,unordered_map<string,string> &parent)
    {
        if(x==parent[x])
        {
            return x;
        }
        string px=find(parent[x],parent);
        parent[x]=px;
        return px;
    }
    void merge(string x,string y,unordered_map<string,string>&parent,unordered_map<string,int> &count)
    {
        string px=find(x,parent);
        string py=find(y,parent);
        
        if(px==py)
        {
            //already same
            return;
        }
        else{
            //merge hoga
            parent[py]=px;
            count[px]++;
            
        }
        
    }
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<string,string> parent;
        unordered_map<string,int> count;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int x1,y1,x2,y2;
                x1=points[i][0];
                y1=points[i][1];
                x2=points[j][0];
                y2=points[j][1];
                string m;
                if(x1==x2)
                {
                    m="inf";
                }
                else if(y1==y2)
                {
                    m="0";
                }
                else{
                    m= fractionToDecimal(y2-y1,x2-x1);

                }
                string x=to_string(x1)+"*"+to_string(y1)+"*"+m;
                string y=to_string(x2)+"*"+to_string(y2)+"*"+m;
                if(parent.find(x)==parent.end())
                {
                    parent[x]=x;
                }
                if(parent.find(y)==parent.end())
                {
                    parent[y]=y;
                }
                cout<<x<<" "<<y<<endl;
                merge(x,y,parent,count);
            }
        }
        unordered_map<string,int>::iterator it;
        int maxGroup=INT_MIN;
        
        for(it=count.begin();it!=count.end();it++)
        {
         maxGroup=max(maxGroup,it->second);   
        }
        return max(1,maxGroup+1);
    }
};