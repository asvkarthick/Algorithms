/* Sorting an array using selection sort
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>
#include <string>

void selectionsort(std::vector<int> &v)
{
    int size = v.size();
    for (int i = 0; i < size - 1; i++) {
    	int min = i;
    	for (int j = i + 1; j < size; j++) {
    		if (v[min] > v[j]) {
    			min = j;
    		}
    	}
    	
    	int temp = v[min];
    	v[min] = v[i];
    	v[i] = temp;
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
    selectionsort(v);
    std::cout << "After sorting ... " << std::endl;
    print(v);

    return 0;
}
