class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int start = 0;
        int sub_start = -1;
        int sub_end = -1;
        int sum = 0;
        int maxi = INT_MIN;
        int n = nums.size();

        for ( int i = 0 ; i < n ; i++ ) {
            sum += nums[i];
            start = i;

        if ( sum > maxi ) {
            maxi = sum;
            sub_start = start;
            sub_end = i;
        }

        if ( sum < 0 ) sum = 0;

        }

        return maxi;
    }
};