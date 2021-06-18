class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int result = 0;
        for(char i : jewels){ 
            for(char j : stones){
                if (i == j){
                    result++;
                }
            }
        }
        return result;
    }
};