/* Sorting an array using merge sort
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>
#include <string>

void merge(std::vector<int>& array, std::vector<int>& l, int n1, std::vector<int>& r, int n2)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            array[k++] = l[i++];
        } else {
            array[k++] = r[j++];
        }
    }
    while (i < n1) array[k++] = l[i++];
    while (j < n2) array[k++] = r[j++];
}

void mergesort(std::vector<int>& v, int n)
{
    if (n <= 1) return;

    int n1 = n / 2;
    int n2 = n - n1;
    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for (int i = 0; i < n1; i++) left[i] = v[i];
    for (int i = 0; i < n2; i++) right[i] = v[n1 + i];

    mergesort(left, n1);
    mergesort(right, n2);
    merge(v, left, n1, right, n2);
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
    mergesort(v, v.size());
    std::cout << "After sorting ... " << std::endl;
    print(v);

    return 0;
}
