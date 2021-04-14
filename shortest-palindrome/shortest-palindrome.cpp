class Solution {
public:
    string shortestPalindrome(string ss) {
        if( ss.size() == 0 ) return "";
        int j = 0, i = 1;
        string r = ss;
        reverse( r.begin(), r.end() );
        string s = ss + "#" + r;
        vector< int > lps( s.size(), 0 );
        while( i < s.size() ) {
            if( s[ i ] == s[ j ] ) {
                lps[ i ] = j + 1;
                ++j, ++i;
            } else {
                if( j ) j = lps[ j - 1 ];
                else lps[ i++ ] = 0;
            }
        }
         return r.substr( 0, r.size() - lps[ i - 1 ] ) + ss;
    }
};