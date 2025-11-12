class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = -1;
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        int arr_start = -1;
        int arr_end = -1;

        for ( int i = 0 ; i < n ; i++ ) {
            sum+= nums[i];
            if ( sum == 0 ) start = i;

            if ( sum > maxi ) {
                maxi = sum;
                arr_start = start;
                arr_end = i; 
            }
            if ( sum < 0 ) {
                sum = 0;
            }
        }
        return maxi;
    }
};