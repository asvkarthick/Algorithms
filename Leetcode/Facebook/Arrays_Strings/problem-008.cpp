/* Problem: Read N characters given Read4
 * Weblink: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/268/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int numBytesRead = 0;
        char buf4[4];
        while (n > 0) {
            int nn = read4(buf4);
            if (nn == 0) break;
            if (n < nn) {
                memcpy(buf + numBytesRead, buf4, n);
                numBytesRead += n;
                n = 0;
            } else {
                memcpy(buf + numBytesRead, buf4, nn);
                numBytesRead += nn;
                n -= nn;
            }
        }
        return numBytesRead;
    }
};
