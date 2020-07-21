class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
		int result;
		for (int num:nums) {
            result = count == 0 ? num : result;
            count += result == num ? 1 : -1;
		}
		return result;
    }
};
