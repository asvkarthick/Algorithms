/* Sorting an array using heap sort
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>
#include <string>

int parent(int n)
{
    return n >> 1;
}

int left(int n)
{
    return 2 * (n + 1) - 1;
}

int right(int n)
{
    return 2 * (n + 1);
}

void minHeapify(std::vector<int>& v, int n, int heapsize)
{
    int l = left(n);
    int r = right(n);
    int smallest = n;

    if (l < heapsize && v[smallest] > v[l]) smallest = l;
    if (r < heapsize && v[smallest] > v[r]) smallest = r;

    if (smallest != n) {
        auto t = v[smallest];
        v[smallest] = v[n];
        v[n] = t;
        minHeapify(v, smallest, heapsize);
    }
}

void maxHeapify(std::vector<int>& v, int n, int heapsize)
{
    int l = left(n);
    int r = right(n);
    int largest = n;

    if (l < heapsize && v[largest] < v[l]) largest = l;
    if (r < heapsize && v[largest] < v[r]) largest = r;

    if (largest != n) {
        auto t = v[largest];
        v[largest] = v[n];
        v[n] = t;
        maxHeapify(v, largest, heapsize);
    }
}

void sortAscending(std::vector<int>& v)
{
    int n = v.size();
    int heapsize = v.size();

    for (int i = n / 2; i >= 0; i--) {
        maxHeapify(v, i, heapsize);
    }

    for (int i = n - 1; i >= 1; i--) {
        auto t = v[0];
        v[0] = v[i];
        v[i] = t;
        --heapsize;
        maxHeapify(v, 0, heapsize);
    }
}

void sortDescending(std::vector<int>& v)
{
    int n = v.size();
    int heapsize = v.size();

    for (int i = n / 2; i >= 0; i--) {
        minHeapify(v, i, heapsize);
    }

    for (int i = n - 1; i >= 1; i--) {
        auto t = v[0];
        v[0] = v[i];
        v[i] = t;
        --heapsize;
        minHeapify(v, 0, heapsize);
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
    sortAscending(v);
    std::cout << "After sorting in ascending order ... " << std::endl;
    print(v);
    sortDescending(v);
    std::cout << "After sorting in descending order ... " << std::endl;
    print(v);

    return 0;
}
