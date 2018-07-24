#include <iostream>
#include <map>

// Simple map program to demonstrate that it can keep duplicates

int main(void)
{
    std::multimap<int, std::string> m;

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

    std::cout << "Printing map using const iterators" << std::endl;
    for(auto x = m.cbegin(); x != m.cend(); x++)
        std::cout << x->first << " : " << x->second << std::endl;

    return 0;
}
