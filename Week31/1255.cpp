class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> counts(26,0);
        for(auto letter:letters){
            counts[letter-'a']++;
        }
        int maxScore = 0;
        for (int mask=0;mask<(1<<words.size());++mask) {
            bitset<15> occurs(mask);
            int wordCount[26] = {0};        // 在栈上分配
            bool spell = true;
            for(int i=0;i<words.size();i++){
                if(!occurs[i]) continue;
                for(auto ch:words[i]){
                    int index = ch-'a';
                    wordCount[index]++;
                    if(wordCount[index]>counts[index]){
                        spell = false;
                        break;
                    }
                }
                if(!spell) break;
                int thisScore = 0;
                for(int i=0;i<26;i++){
                    thisScore += score[i] * wordCount[i];
                }
                maxScore = max(thisScore,maxScore);
            }
        }
        return maxScore;
    }
};
