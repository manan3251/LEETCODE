class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x - 1;

        if ( x == 0 || x == 1 ) return x;

        while ( start <= end ) {
            long long mid = start + (( end - start ) / 2 );

        if ( mid*mid == x ) return mid;

        else if ( mid*mid > x ) end = mid - 1;

        else {
            start = mid + 1;
        }
        }
        return end;
    }
};