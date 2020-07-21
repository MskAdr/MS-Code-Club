class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() <= 10) return {};
        unordered_map<char,int> mapping = {
            {'A',0},
            {'T',1},
            {'G',2},
            {'C',3}
        };
        constexpr int mask = (1<<20)-1;
        vector<string> result;
        int current = 0;
        int i = 0;
        for(;i<10;++i){
            current <<= 2;
            current |= mapping[s[i]];
        }
        unordered_set<int> occurs = {current};
        unordered_set<int> output;
        for(;i<s.length();++i){
            current <<= 2;
            current &= mask;
            current |= mapping[s[i]];
            if(occurs.count(current)) {
                if(!output.count(current)) { 
                    result.emplace_back(s,i-9,10);
                    output.insert(current);
                }
            } else {
                occurs.insert(current);
            }
        }
        return result;
    }
};
