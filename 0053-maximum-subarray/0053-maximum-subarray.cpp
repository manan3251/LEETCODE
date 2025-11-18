class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = 0;
        int arr_start = -1;
        int arr_end = -1;
        int sum = 0;
        int maxi = INT_MIN;
        int n = nums.size();

        for ( int i = 0 ; i < n ; i++ ) {
            sum += nums[i];
            start = i;

        if ( sum > maxi ) {
            maxi = sum;
            arr_start = start;
            arr_end = i;
        }

        if ( sum < 0 ) sum = 0;
        }
        return maxi;
    }
};