class Solution {
private:
    inline int switchToPattern(const string& s){
        int result = 0;
        for(auto ch:s){
            result |= 1 << (ch-'a');
        }
        return result;
    }
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> answers;
        for(auto word:words) {
            answers[switchToPattern(word)]++;
        }
        vector<int> result;
        for(auto puzzle:puzzles){
            int pattern = switchToPattern(puzzle);
            int mask = 1 << (puzzle[0]-'a');
            int current = pattern;
            int count = 0;
            while(current){
                if((mask & current) && answers.count(current)) count+=answers[current];
                current = pattern & (current-1);
            }
            result.push_back(count);
        }
        return result;
    }
};
