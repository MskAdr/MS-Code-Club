class Solution {
public:
    int maximum(int a, int b) {
        int tmp = static_cast<int>( (static_cast<uint64_t>(a) - static_cast<uint64_t>(b)) >> 63 );
        return a*(tmp^1) + b*tmp;
    }
};
