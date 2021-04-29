 class Solution {
public:
    bool isNumber(string s) {
        
        int i = 0;
        if(s[i] == '-' || s[i] == '+')
            i++;
        
        int digits = 0;
        int dots = 0;
        while(i < s.length() && (s[i]=='.' || isdigit(s[i])))
            isdigit(s[i++])?digits++:dots++;
        
        if(dots >1 ||digits == 0 )
            return false;
        
        digits = 0;
        dots = 0;
        if(s[i] == 'e' || s[i] == 'E')
        {
            i++;
            if(s[i] == '-' || s[i] == '+')
                i++;
            while(i < s.length() && (s[i]=='.' || isdigit(s[i])))
                isdigit(s[i++])?digits++:dots++;
            
            if(digits == 0 || dots>0)
                return false;
        }
        
        return i == s.length();
        
    }
};