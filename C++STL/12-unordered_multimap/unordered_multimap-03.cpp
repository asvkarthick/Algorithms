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

    std::cout << "Printing map using range based for loop" << std::endl;
    for(const auto& x : m)
        std::cout << x.first << " : " << x.second << std::endl;

    std::cout << "Printing map using iterators" << std::endl;
    for(auto x = m.begin(); x != m.end(); x++)
        std::cout << x->first << " : " << x->second << std::endl;

    return 0;
}
