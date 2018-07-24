#include <iostream>
#include <unordered_map>

// Simple unordered multimap program to demonstrate that it can keep duplicates

int main(void)
{
    std::unordered_multimap<int, std::string> m;

    // insert some elements in arbitrary order
    m = { { 2, "am" },
          { 1, "I" },
          { 3, "Karthick" },
          { 3, "Kumaran" }
        };

    for(const auto& x : m)
        std::cout << x.first << " : " << x.second << std::endl;

    return 0;
}
