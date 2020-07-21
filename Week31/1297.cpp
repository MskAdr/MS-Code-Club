class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        constexpr uint64_t mask = (1ULL<<58)-1ULL;
        vector<int> occurs(26,0);
        int letters = 0;
        uint64_t maxModulo = 31;
        uint64_t hash = 0;
        for(int i=0;i<minSize;i++){
            size_t index = s[i]-'a';
            letters += (occurs[index] == 0);
            occurs[index]++;
            maxModulo *= 31;
            maxModulo &= mask;
            hash *= 31;
            hash += index * 31;
            hash &= mask;
        }
        unordered_map<uint64_t,int> times;
        int result = 0;
        if(letters <= maxLetters){
            times[hash]++;
            result=1;
        }
        for(int i=minSize;i<s.size();i++){
            size_t index = s[i]-'a';
            size_t prevIndex = s[i-minSize]-'a';
            occurs[prevIndex]--;
            letters -= (occurs[prevIndex] == 0);
            letters += (occurs[index] == 0);
            occurs[index]++;
            hash *= 31;
            hash += 1ULL << 63;
            hash -= maxModulo * prevIndex;
            hash += 31 * index;
            hash &= mask;
            if(letters <= maxLetters){
                times[hash]++;
                result = max(times[hash],result);
            }
        }
        return result;
    }
};
