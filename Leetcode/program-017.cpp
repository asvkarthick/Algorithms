/* Program-017 : Letter combinations of a phone number
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:

    void findCombinations(std::string num, const std::string *letters, std::vector<std::string>& combs, std::string prefix = "")
    {
        if (num.length() == 0) {
            combs.push_back(prefix);
            return;
        }
        int n = num[0] - '0';
        if (n <= 1 || n > 9) return;
        auto chars = letters[n];
        for (auto ch : chars) {
            findCombinations(num.substr(1), letters, combs, prefix + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        std::string letterCombs[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> combs;
        if (digits != "")
            findCombinations(digits, letterCombs, combs);
        return combs;
    }
};

void findCombinations(std::string num, const std::string *letters, std::vector<std::string>& combs, std::string prefix = "")
{
    if (num.length() == 0) {
        combs.push_back(prefix);
        return;
    }
    auto chars = letters[num[0] - '0'];
    for (auto ch : chars) {
        findCombinations(num.substr(1), letters, combs, prefix + ch);
    }
}

int main(void)
{
    std::string letters[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    std::string number;
    std::cout << "Enter number : ";
    std::cin >> number;

    std::vector<std::string> combs;
    findCombinations(number, letters, combs);
    for (auto x : combs)
        std::cout << x << std::endl;
    return 0;
}
