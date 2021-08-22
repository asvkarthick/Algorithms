/* Draw Line - 8 pixels in one byte
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>

void drawLine(std::vector<unsigned char>& buf, int w, int x1, int x2, int y)
{
    int startByte = x1 / 8;
    int startBit = x1 % 8;
    int endByte = x2 / 8;
    int endBit = x2 % 8;
    if (startBit != 0) startByte++;
    if (endBit != 7) endByte--;
    int bufsize = buf.size();
    startByte = startByte + y * w / 8;
    endByte = endByte + y * w / 8;
    for (int i = startByte; i <= endByte; i++) buf[i] = 0xff;
    if (startByte > endByte) {
        int numBits = x2 - x1 + 1;
        unsigned char mask = (1 << numBits) - 1;
        buf[endByte] |= mask;
    } else {
        int numBits = 8 - startBit;
        buf[startByte - 1] |= (1 << numBits) - 1;
        numBits = endBit;
        buf[endByte + 1] |= (((1 << numBits) - 1) << (8 - numBits));
    }
}
