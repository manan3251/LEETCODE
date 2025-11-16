class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort ( nums.begin() , nums.end() );

        for ( int j = 1 ; j < n ; j++ ) { 
            if ( nums[j] == nums[j-1] ) return true;
        }
        return false;
    }
};