 class Solution {
public:
	bool ispal(long long temp){
		string cur=to_string(temp);
		int a=0;
		int b=cur.size()-1;
		while(a<b){
			if(cur[a]!=cur[b]) return false;
			a++;
			b--;
		}
		return true;
	}
	long long constru(int num, int type){
		long long x=num;
		long long y=num;
		if(type==1) x/=10;
		while(y>0){
			x=x*10+y%10;
			y/=10;
		}
		return x;
	}
	int superpalindromesInRange(string L, string R) {
		long long l=stoll(L);
		long long r=stoll(R);
		int count=0;
		for(int i=0;i<1e5;i++){
			for(int type=0;type<2;type++){
				long long pal=constru(i,type);
				if(pal>1e9) continue;
				long long temp=pal*pal;
				if(temp>=l && temp<=r && ispal(temp)) count++;
			}
		}

		return count;

	}
};