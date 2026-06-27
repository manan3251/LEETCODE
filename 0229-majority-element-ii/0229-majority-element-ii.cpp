class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map <int , int> mpp;

        for ( int i = 0 ; i < n ; i++ ) {
            mpp[nums[i]]++;
        }

        vector<int> ans;

        for (auto cnt : mpp) {
            if (cnt.second > n / 3) {
                ans.push_back(cnt.first);
                }
            }
            return ans;
    }
};