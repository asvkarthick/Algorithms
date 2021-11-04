/* Problem: Read N Characters give read4() II
 * Weblink: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/269/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    Solution() : mIdx(0), mValidBytes(0)
    {

    }

    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int numBytesRead = 0;
        std::cout << "Valid bytes = " << mValidBytes << std::endl;
        if (mValidBytes) {
            numBytesRead = std::min(n, mValidBytes);
            memcpy(buf, mBuffer + mIdx, numBytesRead);
            mIdx = mIdx + numBytesRead;
            if (mIdx >= 4) mIdx = 0;
            mValidBytes -= numBytesRead;
            if (numBytesRead == n) return n;
        }
        int ret = read4(mBuffer);
        mValidBytes = ret;
        mIdx = 0;
        if (ret == 0) return numBytesRead;
        return numBytesRead + read(buf + numBytesRead, n - numBytesRead);
    }
    char mBuffer[4];
    int mIdx;
    int mValidBytes;
};
