class Solution {
public:
    int FirstOcc(vector<int>& arr, int size, int key) {
        int s = 0;        
        int e = size - 1; 
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == key) {
                ans = mid;
                e = mid - 1;
            } else if (key > arr[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    int LastOcc(vector<int>& arr, int size, int key) {
        int s = 0;        
        int e = size - 1; 
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == key) {
                ans = mid;
                s = mid + 1; 
            } else if (key > arr[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int first = FirstOcc(nums, size, target);
        int last = LastOcc(nums, size, target);
        return {first, last};
    }
};