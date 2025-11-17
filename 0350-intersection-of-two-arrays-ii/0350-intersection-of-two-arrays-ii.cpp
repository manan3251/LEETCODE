class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int , int> count;
        vector <int> intersection;

        for ( int num : nums1 ) {
            count[num]++;
        }
        for ( int num : nums2 ) {
            if ( count[num] > 0 ) {
                intersection.push_back ( num );
                count[num]--;
            }
        }
        return intersection;
    }
};