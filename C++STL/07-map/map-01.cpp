#include <iostream>
#include <map>

int main(void)
{
    std::map<int, std::string> m;

    // insert some elements in arbitrary order
    m = { { 2, "am" },
          { 1, "I" },
          { 3, "Karthick" }
        };

    for(const auto& x : m)
        std::cout << x.first << " : " << x.second << std::endl;

    return 0;
}
