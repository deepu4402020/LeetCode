class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n= beginWord.size();

        queue<pair<string,int>>que;
        que.push({beginWord,1});
        unordered_set<string>st;
        unordered_set<string>used;
        for(auto x:wordList){
            st.insert(x);
        }
        while(!que.empty()){
            auto [str,level]=que.front();que.pop();
            if(str==endWord)return level;

            for(int i=0;i<str.size();i++){
                for(char j='a';j<='z';j++){
                    string temp=str;
                    temp[i]=j;
                    if(st.find(temp)!=st.end()&& used.find(temp)==used.end()){
                                                used.insert(temp);

                        que.push({temp,level+1});

                    }

                }
            }
        }
        return 0;
    }
};