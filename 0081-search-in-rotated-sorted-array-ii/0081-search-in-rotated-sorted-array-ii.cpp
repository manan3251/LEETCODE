class Solution {
public:

int BS ( vector<int>& nums, int n, int x ) {
    int start = 0;
    int end = n-1;

    while ( start <= end ) {
        int mid = start + ((end -start)/2);

    if ( x == nums[mid] ) return true;
    if ( nums[start] == nums[mid] && nums[mid] == nums[end] ) {
        start = start + 1;
        end = end - 1;
        continue;
    }

    else if ( nums[start] <= nums[mid] ) {
        if (  nums[start] <= x && x <= nums[mid] ) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }  
    
    else {
        if ( nums[mid] <= x && x <= nums[end] ) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    }
    return false;
}

    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        return BS ( nums, n, target);
        
    }
};