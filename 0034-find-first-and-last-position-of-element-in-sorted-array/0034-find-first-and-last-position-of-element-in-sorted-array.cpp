class Solution {
public:
int FirstOcc ( vector<int>& arr, int size, int key) { 
    int s = 0;
    int n = size;
    int e = size-1;
    int ans = -1;

    while ( s <= e ) {
        int mid = s + ( e - s )/2;

    if ( key == arr[mid] ) {
        e = mid - 1;
        ans = mid;
    } 
    else if ( key > arr[mid] ) {
        s = mid + 1;
    }
    else {
        e = mid - 1;
    }
    }
    return ans;
}

int LastOcc ( vector<int>& arr, int size, int key) { 
    int s = 0;
    int n = size;
    int e = size-1;
    int ans = -1;

    while ( s <= e ) {
        int mid = s + ( e - s )/2;

    if ( key == arr[mid] ) {
        s = mid + 1;
        ans = mid;
    } 
    else if ( key > arr[mid] ) {
        s = mid + 1;
    }
    else {
        e = mid - 1;
    }
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = FirstOcc( nums, n, target);
        int last = LastOcc ( nums, n, target);
        return { first, last};
    }  
};