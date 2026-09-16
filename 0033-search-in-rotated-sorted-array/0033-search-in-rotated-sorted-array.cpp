class Solution {
public:

int BS ( vector<int>& nums, int n, int x ) {
    int low = 0;
    int high = n -1;

    while ( low <= high ) {
        int mid = low + ( ( high - low ) / 2 );

    if ( x == nums[mid] ) return mid;

    else if ( nums[low] <= nums[mid] ) {
        if ( nums[low] <= x && x <= nums[mid] ) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    else {
        if ( nums[mid] <= x && x <= nums[high] ) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
}
    return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return BS ( nums, n, target );
        
    }
};