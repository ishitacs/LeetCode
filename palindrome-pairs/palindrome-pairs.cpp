 class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        //This will be our returned answer
        vector<vector<int>> pairs;
        
        //create map of words, hash value k = string, mapped value T = int position in initial vector<string> words
        unordered_map<string, int> map;
        for (int i = 0; i < words.size(); ++i) {
            map[words[i]] = i;
        }
        
        //identifying all possible palindromes:
        //1. if word = "", then it forms a palindrome with any word that is itself a palindrome
        //2. if string1 == reverse(string2) then string1+string2 is a palindrome (as is str2+str1)
        //then start trying to form any possible palindromes out of the letters in word, and if any are found see if that string is in the map
        //3. To do this, reverse the word, cut off the first letter and concatinate word+substr, repeat until length = 0,
        //4. also similarly cutting the last letter and concatinating substring+word
        //for instance word=abc, reverse is cba. We will already have cba from 2, but we need all other possible palindrome substrings
        //word+reverseSubstring abc+ba is a palindrome
        //but abc+a is not
        //reverseSubstring+word cb+abc is a palindrome
        //but c+abc is not
        //so if "ba" and "cb" are present, those form palindromes with "abc": "cbabc" and "abcba"
        

        //1. if the blank string is in the set, we check each word to see if it is itself a palindrome. 
        //Any palindromes we find will give us two pairs for the answer, palindrome+"" and ""+palindrome
        //for example: hannah is a palindrome, so hannah+"" and ""+hannah are both the string "hannah" and are both palindromes 
        if (map.find("") != map.end()) {
            int index = map[""];
            for (int i = 0; i < words.size(); ++i) {
                if(i != index && checkPalindrome(words[i])){
                    addPalindromePair(&pairs, index, i);
                    addPalindromePair(&pairs, i, index);
                }
            }
        }
        
        //The second iteration through the map looks for everything else (2, 3, and 4)
        for (int i = 0; i < words.size(); ++i) {
            if(words[i] == "") {
                //We have already found all the blank string palindromes, so continue to next loop iteration
                continue;
            }
            
            //2. If the reverse of a word is present in the map, those form a palindrome
            string reverseWord = words[i];
            reverse(reverseWord.begin(), reverseWord.end());
            if(map.find(reverseWord) != map.end() && map[reverseWord] != i) {
                addPalindromePair(&pairs, map[reverseWord], i);    
            }
            
            //lastly, take each reversed word and begin cuttong off letters from the front and back,
            //concatinate those substrings with the original word to find palindromes. Then check to see if the 
            //reversed substring that resulted in a palindrome exists in the map.
            for (int j = 1; j < words[i].length(); ++j) {
                if(checkPalindrome(words[i]+reverseWord.substr(j)) && map.find(reverseWord.substr(j)) != map.end()) {
                    //3. word+substr palindrome found
                    addPalindromePair(&pairs, i, map[reverseWord.substr(j)]);
                }
                if(checkPalindrome(reverseWord.substr(0, j)+words[i]) && map.find(reverseWord.substr(0, j)) != map.end()) {
                    //4. substr+word palindrome found
                    addPalindromePair(&pairs, map[reverseWord.substr(0, j)], i);
                }
            }
        }
        return pairs;
    }
    
    //function for checking is a string is a palindrome
    bool checkPalindrome(string str) {
        int i = 0, j = str.length();
        while (i < j) {
            if (str.at(i) != str.at(j-1)) {
                return false;                
            }
            ++i;
            --j;
        }
        return true;
    }
    
    //function to add a vector<int> pair to the answer vector
    void addPalindromePair(vector<vector<int>> *v, int a, int b) {
        vector<int> newPair;
        newPair.push_back(a);
        newPair.push_back(b);
        v->push_back(newPair);
    }
};