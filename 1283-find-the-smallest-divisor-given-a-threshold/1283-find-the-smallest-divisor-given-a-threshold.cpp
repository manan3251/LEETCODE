class Solution {
public:
int sumofD ( vector<int>& arr , int div ) {
    int sum = 0;
    int n = arr.size();

    for ( int i = 0 ; i < n ; i++ ) {
        sum += ceil ( (double)(arr[i]) / (double)(div) ); 
    }
    return sum;
} 

    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin() , nums.end() );
        int ans = -1;

        while ( start <= end ) {
            int mid = start + ((end - start) / 2);

        if ( sumofD( nums , mid ) <= threshold ) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        }
        return start;
    }
};