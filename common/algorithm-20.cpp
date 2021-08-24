/* Algorithm to compute square of sorted array and store in sorted order
 * Input : Sorted array containing negative and positive integers
 * Output : Sorted array
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>

std::vector<int> computeSquareSorted(std::vector<int>& input)
{
    std::vector<int> output(input.size());
    int negIndex = -1, posIndex = input.size(), outIndex = 0;

    /* Find two indices one pointing to the positive number
     * and another pointing to negative number
     * If there is no positive or no negative number then
     * the corresponding index can point to out of bound index
     */
    for (int i = 0; i < input.size(); i++) {
        if (input[i] < 0)
            negIndex++;
        else
            break;
    }
    for (int i = input.size() - 1; i >= 0; i--) {
        if (input[i] >= 0)
            posIndex--;
        else
            break;
    }

    while (posIndex < input.size() && negIndex > -1) {
        if (input[posIndex] < -1 * input[negIndex]) {
            int d = input[posIndex];
            output[outIndex++] = d * d;
            ++posIndex;
        } else {
            int d = input[negIndex];
            output[outIndex++] = d * d;
            --negIndex;
        }
    }

    while (posIndex < input.size()) {
        int d = input[posIndex];
        output[outIndex++] = d * d;
        ++posIndex;
    }

    while (negIndex > -1) {
        int d = input[negIndex];
        output[outIndex++] = d * d;
        --negIndex;
    }

    return output;
}

void printArray(std::vector<int>& arr)
{
    for (auto x : arr) std::cout << x << std::endl;
}

int main(void)
{
    std::vector<int> v1 { -5, -4, -3, -2, -1, 1, 2, 3, 4, 5 };
    std::vector<int> v2 { 1, 2, 3, 4, 5, 6, 7 };
    std::vector<int> v3 { -10, -9, -8, -7, -6 };
    std::vector<int> v4 { -10, -5, 0, 1, 2, 3, 4, 5 };
    std::vector<int> v5 { -10, -9, -8, -7, -6, -5, 0, 1 };

    auto v1out = computeSquareSorted(v1);
    auto v2out = computeSquareSorted(v2);
    auto v3out = computeSquareSorted(v3);
    auto v4out = computeSquareSorted(v4);
    auto v5out = computeSquareSorted(v5);

    std::cout << "Contents of V1" << std::endl;
    printArray(v1);
    std::cout << "Contents of V1 sorted" << std::endl;
    printArray(v1out);

    std::cout << "Contents of V2" << std::endl;
    printArray(v2);
    std::cout << "Contents of V2 sorted" << std::endl;
    printArray(v2out);

    std::cout << "Contents of V3" << std::endl;
    printArray(v3);
    std::cout << "Contents of V3 sorted" << std::endl;
    printArray(v3out);

    std::cout << "Contents of V4" << std::endl;
    printArray(v4);
    std::cout << "Contents of V4 sorted" << std::endl;
    printArray(v4out);

    std::cout << "Contents of V5" << std::endl;
    printArray(v5);
    std::cout << "Contents of V5 sorted" << std::endl;
    printArray(v5out);

    return 0;
}
