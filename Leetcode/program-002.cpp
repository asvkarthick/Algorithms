#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
       std::string decodedString;
       std::vector<std::pair<int, std::string>> v;
       int i, j, repeat;
       char c, ch;

       std::cout << v.size() << std::endl;

       for(i = 0; i < s.length(); i++)
       {
           char repeat = s.at(i);
           if(repeat >= '0' && repeat <= '9')
           {
               std::string substr;
               c = s.at(i + 1);
               if(c == '[')
               {
                   j = i + 2;

                   while(s.at(j) >= 'a' && s.at(j) <= 'z')
                   {
                       ch = s.at(j);
                       substr.push_back(ch);
                       j++;
                   }
                   std::cout << substr << std::endl;

                   v.push_back(std::make_pair(repeat - '0', substr));
                   std::cout << i << std::endl;
               }
           }
           else if(repeat >= 'a' && repeat <= 'z')
           {
               if(v.size() != 0)
               {
                   std::string previous_string = v[v.size() - 1].second;
                   std::cout << "Previous: " << previous_string << std::endl;
               }
           }
           else if(repeat == ']')
           {
               int k = v[v.size() - 1].first;
               std::string previous_string = v[v.size() - 1].second;
               std::string decoded;
               while(k > 0)
               {
                   decoded = decoded + previous_string;
                   k--;
               }
               std::cout << "Decoded: " << decoded << std::endl;
           }
       }

       return decodedString; 
    }
};

int main(void)
{
    Solution s;
    std::string decodedString;

    decodedString = s.decodeString(std::string { "3[a]2[bc]" });
    std::cout << decodedString << std::endl;

    decodedString = s.decodeString(std::string { "3[a2[c]]" });
    std::cout << decodedString << std::endl;

    decodedString = s.decodeString(std::string { "2[abc]3[cd]ef" });
    std::cout << decodedString << std::endl;

    return 0;
}
