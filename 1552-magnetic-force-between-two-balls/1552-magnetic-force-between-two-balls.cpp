class Solution {
public:
bool canweplace ( vector<int> & position , int dist , int balls ) {
    int cntballs = 1;
    int last = position[0];
    for ( int i = 1;i < position.size() ; i++ ) {
        if (position[i] - last >= dist ) {
            cntballs++;
            last = position[i];
        }
        if ( cntballs >= balls ) return true;
    }
    return false;
}

    int maxDistance(vector<int>& position, int m) {
        sort ( position.begin() , position.end() );
        int n = position.size();
        int low = 1;
        int high = position[n-1] - position[0];

        while ( low <= high ) {
            int mid = low + (high-low)/2;

        if (canweplace ( position , mid , m ) == true ) {
            low = mid + 1;
        }
        else high = mid -1;
        }
        return high;
    }
};