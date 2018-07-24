#include <iostream>
#include <unordered_map>

// Simple unordered map program to demonstrate that it cannot keep duplicates
// Element values can be overwritten but not the key
// If you just change the values it does not do rehashing

int main(void)
{
    std::unordered_map<int, int> m;

    // insert some elements in arbitrary order
    for(int i = 0; i < 10; i++)
        m[i] = 10 - i;

    std::cout << "Printing map using range based for loop" << std::endl;
    for(const auto& x : m)
        std::cout << x.first << " : " << x.second << std::endl;

    std::cout << "Printing map using iterators" << std::endl;
    for(auto x = m.begin(); x != m.end(); x++)
        std::cout << x->first << " : " << x->second << std::endl;

    std::cout << "Printing map using const iterators" << std::endl;
    for(auto x = m.cbegin(); x != m.cend(); x++)
        std::cout << x->first << " : " << x->second << std::endl;

    for(int i = 0; i < 10; i++)
        m[i] = i;

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
