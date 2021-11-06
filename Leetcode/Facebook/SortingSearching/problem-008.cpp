/* Problem: First Bad Version
 * Weblink: https://leetcode.com/explore/interview/card/facebook/54/sorting-and-searching-3/272/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
