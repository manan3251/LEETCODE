class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int xor1 = 0;
        int n = nums.size();
        for ( int i = 0 ; i < n ; i++ ) {
            xor1 = xor1 ^ nums[i];
        }
        return xor1;
        
    }
};