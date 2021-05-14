 class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justified;
        int numWords = words.size();
        
        
        for(int i = 0, j = 0; i < numWords; ) {
            int currentLength = 0;
            for(j = i; j < numWords && currentLength + words[j].size() + j - i <= maxWidth; j++) {
                currentLength += words[j].size();
            }

            string line;
            if (j-i == 1 || j == numWords) {
                line = justifyLeft(words, i, j, maxWidth);
            } else {
                line = justifyFull(words, i, j, currentLength, maxWidth);
            }
            justified.push_back(line);
            
            i = j;
        }
        return justified;
    }
    
    string justifyLeft(vector<string>& words, int from, int to, int maxWidth) {
        string retString(maxWidth, ' ');
        
        int index = 0;
        for(int i = from; i < to; i++) {
            retString.replace(index, words[i].size(), words[i]);
            index += words[i].size() + 1;
        }
        return retString;
    }
    
    string justifyFull(vector<string>& words, int from, int to, int wordLength, int maxWidth) {
        string retString(maxWidth, ' ');
        int numWords = to - from;
        int spaces = maxWidth - wordLength;
        int space = spaces / (numWords - 1);
        int extraSpace = spaces % (numWords - 1);
        
        int index = 0;
        for(int i = from; i < to; i++) {
            retString.replace(index, words[i].size(), words[i]);
            index += words[i].size() + space;
            if(extraSpace > 0) {
                index++;
                extraSpace--;
            }
        }
        return retString;
    }
};