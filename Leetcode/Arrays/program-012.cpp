/* Compute the spiral of n
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>

std::vector<std::vector<int>> spiral(int n)
{
    std::vector<std::vector<int>> v;
    int counter = 0;
    for (int i = 0; i < n; i++) v.push_back(std::vector<int>(n));
    for (int i = 0; i < n / 2; i++) {
        /* Left to right */
        for (int j = i; j < n - i; j++) {
            std::cout << counter << " " << i << " " << j << std::endl;
            v[i][j] = counter++;
        }
        /* Top to bottom */
        for (int j = i + 1; j < n - i; j++) {
            std::cout << counter << " " << i << " " << j << std::endl;
            v[j][n - i - 1] = counter++;
        }
        /* Right to left */
        for (int j = n - i - 2; j >= i; j--) {
            std::cout << counter << " " << i << " " << j << std::endl;
            v[n - i - 1][j] = counter++;
        }
        /* Bottom to top */
        for (int j = n - i - 2; j > i; j--) {
            std::cout << counter << " " << i << " " << j << std::endl;
            v[j][i] = counter++;
        }
    }
    /* Handle the odd case */
    if (n % 2) v[n / 2][n / 2] = counter;
    return v;
}

static void print(std::vector<std::vector<int>>& v)
{
    for (int row = 0; row < v.size(); row++) {
        for (int col = 0; col < v.size(); col++) {
            std::cout << v[row][col] << "  ";
        }
	std::cout << std::endl;
    }
}

int main(void)
{
    int n;
    std::cout << "Enter n : ";
    std::cin >> n;
    auto v = spiral(n);
    print(v);

    return 0;
}
