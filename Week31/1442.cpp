class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int n = arr.size();
        int count=0;
        for(int i=0;i<n;++i){
            int num = arr[i];
            for(int j=i+1;j<n;++j){
                num ^= arr[j];
                count += (num==0)?j-i:0;
            }
        }
        return count;
    }
};
