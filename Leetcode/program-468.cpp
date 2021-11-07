/* Problem: Validate IP Address
 * Weblink: https://leetcode.com/problems/validate-ip-address/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    bool checkHex(std::string str)
    {
        std::unordered_set<char> hashSet { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F' };
        if (str.length() <= 0) return false;
        if (str.length() > 4) return false;

        for (int i = 0; i < str.length(); i++) {
            if (hashSet.find(str[i]) == hashSet.end()) return false;
        }

        return true;
    }

    int checkNum(std::string str)
    {
        if (str.length() <= 0) return -1;
        if (str.length() > 3) return -1;

        int num = 0;
        for (int i = 0; i < str.length(); i++) {
            if (num == 0 && i > 0) // leading zero case
                return -1;
            if (str[i] < '0' || str[i] > '9') {
                return -1;
            } else {
                num = num * 10 + str[i] - '0';
            }
        }

        if (num > 255) return -1;
        return num;
    }

    string validIPAddress(string queryIP) {
        int numSubstring = 0;
        std::string addr = queryIP;
        size_t pos, prev_pos;
        int index = 0;
        prev_pos = 0;
        bool isIPV4 = false, isIPV6 = false;

        if (addr.find(".") != std::string::npos) isIPV4 = true;
        if (addr.find(":") != std::string::npos) isIPV6 = true;
        if (isIPV4 && isIPV6) return "Neither";

        if (isIPV4) {
            while (pos != std::string::npos) {
                pos = addr.find(".", index);
                index = pos + 1;
                numSubstring++;
                int num;
                if (pos == std::string::npos)
                    num = checkNum(addr.substr(prev_pos));
                else
                    num = checkNum(addr.substr(prev_pos, pos - prev_pos));
                if (num == -1) return "Neither";
                prev_pos = pos + 1;
            }
            if (numSubstring > 4) return "Neither";
            else if (numSubstring == 4) return "IPv4";
        }
        if (isIPV6) {
            index = 0;
            prev_pos = 0;
            pos = 0;
            numSubstring = 0;
            while (pos != std::string::npos) {
                pos = addr.find(":", index);
                index = pos + 1;
                numSubstring++;

                bool ret;
                if (pos == std::string::npos)
                    ret = checkHex(addr.substr(prev_pos));
                else
                    ret = checkHex(addr.substr(prev_pos, pos - prev_pos));
                if (ret == false) return "Neither";
                prev_pos = pos + 1;
            }
            if (numSubstring > 8) return "Neither";
            else if (numSubstring == 8) return "IPv6";
        }

        return "Neither";
    }
};
