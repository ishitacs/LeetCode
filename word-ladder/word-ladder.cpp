 class Solution {
public:
    int findDiff(string &s1,string &s2) {
        int count=0;
        for(int i=0;i<s1.length();i++) {
            if(s1[i] != s2[i]) count++;
        }
        return count;
    }
    void createGraph(vector<string>& wordList, vector<vector<int>> &graph) {
        for(int i=0;i<wordList.size();i++) {
            string word = wordList[i];
            for(int j=i+1;j<wordList.size();j++) {
                int diff = findDiff(word,wordList[j]);
                if(diff == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    }
    int bfs(vector<vector<int>> &graph,int startIndex,int endIndex) {
        int nodes = graph.size();
        vector<bool> visited(nodes,false);
        queue<int> q;
        q.push(startIndex);
        visited[startIndex] = true;
        int count = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int ele = q.front();
                q.pop();
                for(auto x : graph[ele]) {
                   if(x == endIndex) return count;
                   if(!visited[x]){
                       q.push(x);
                       visited[x] = true;
                   }
                }
            }
            count++; 
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { 
        int n = wordList.size();
        int startIndex = -1;
         for(int i=0;i<n;i++) {
            if(wordList[i] == beginWord) {startIndex = i;}
        }
        if(startIndex == -1){
            startIndex = wordList.size();
            wordList.push_back(beginWord);
        }
        
        int nodes = wordList.size();
        vector<vector<int>> graph(nodes);
        createGraph(wordList,graph);
        int endIndex = -1;
        for(int i=0;i<nodes;i++) {
            if(wordList[i] == endWord) {endIndex = i;}
        }
        if(endIndex == -1) return 0;
        //cout<<startIndex<<" "<<endIndex<<"\n";
        int ans = bfs(graph,startIndex,endIndex);
        if(ans ==0) return ans;
        return ans+1;
        
    }
};
