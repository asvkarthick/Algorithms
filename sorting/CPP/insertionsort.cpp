/* Sorting an array using insertion sort
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>
#include <string>

void insertionsort(std::vector<int> &v)
{
    int size = v.size();
    for (int i = 1; i < size; i++) {
        auto elem = v[i];
	int j = i - 1;
        for (; j >= 0; j--) {
            if (v[j] > elem) {
                v[j + 1] = v[j];
            } else {
                break;
            }
        }
        v[j + 1] = elem;
    }
}

void print(std::vector<int> &v)
{
    std::cout << "Contents of array : " << std::endl;
    for (auto x : v) {
        std::cout << x << std::endl;
    }
}

int main(void)
{
    std::string str;
    std::vector<int> v;
    do {
        std::cout << "Enter a number (end to stop) : ";
        std::cin >> str;
        if (str == "end") {
            std::cout << "End of program" << std::endl;
        } else {
            int n = stoi(str);
            std::cout << "Entered number : " << n << std::endl;
            v.push_back(n);
        }
    } while (str != "end");

    std::cout << "Before sorting ... " << std::endl;
    print(v);
    insertionsort(v);
    std::cout << "After sorting ... " << std::endl;
    print(v);

    return 0;
}
