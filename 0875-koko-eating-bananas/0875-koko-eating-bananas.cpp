class Solution {
public:
long long calculateHours ( vector<int>& piles , int k ) {
    long long totalH = 0;
    int n = piles.size();

    for ( int i = 0 ; i < n ; i++ ) {
        totalH += ceil ((double)(piles[i]) / (double)(k) ); 
    }
    return totalH;
}

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1 , end = *max_element(piles.begin() , piles.end() );

        while ( start <= end ) {
            int mid = start + ( end - start ) / 2;

        if ( calculateHours(piles,mid) <= h ) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        }
        return start;
    }
};